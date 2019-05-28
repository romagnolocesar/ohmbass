#pragma once
#include "OhmBass.h"
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmain"
#include "IPlug_include_in_plug_src.h"
#pragma clang diagnostic pop
#include "IKeyboardControl.h"
#include "resource.h"

#include <math.h>
#include <algorithm>


const int kNumPrograms = 5; //Qtd of presets
bool isPluginInitialized = FALSE;
const int kNumParams = 49; //Qtd for params

OhmBass::OhmBass(IPlugInstanceInfo instanceInfo) : IPLUG_CTOR(kNumParams, kNumPrograms, instanceInfo), lastVirtualKeyboardNoteNumber(virtualKeyboardMinimumNoteNumber - 1) {
	TRACE;

	this->globals_sampleRate = mSampleRate;

	//create the main display
	CreateMainDisplay();

	//Initializing all modules (controls)
	iModulesManager->InitAllModules(iControlsManager, iGraphicsManager);

	//create all params
	iControlsManager->createParams(this);

	//Attach Background in Main Display
	iGraphicsManager->attachBackgroundMainDisplay();

	//Creating a Collection of IControls objects
	doModelsControlsInIControlsCollection();

	//Set default params on Filters (BiQuad Filter)
	iModulesManager->iModEQuilibrium->updateLowFilterValues();

	//Load Keyboard
	iGraphicsManager->loadKeyboard();

	
	
	//create keyboard
	CreateKeyboard();

	iGraphicsManager->createLines(this);

	//Attach all graphics with your respective controls in main screen
	AttachGraphics(iGraphicsManager->pGraphics);

	//Create all default presets
	CreatePresets();

	//Flag to indicate when the plugin was full started
	isPluginInitialized = TRUE;

	//Fills
	if (isPluginInitialized) {
		iModulesManager->loadAuxParameters(iControlsManager);
	}
	
	mMIDIReceiver.noteOn.Connect(&voiceManager, &VoiceManager::onNoteOn);
	mMIDIReceiver.noteOff.Connect(&voiceManager, &VoiceManager::onNoteOff);

}
OhmBass::~OhmBass() {}


void OhmBass::CreateMainDisplay() {
	iGraphicsManager->pGraphics = MakeGraphics(this, iGraphicsManager->kWidth, iGraphicsManager->kHeight);
	iGraphicsManager->loadCommonsBitmaps();
}

void OhmBass::doModelsControlsInIControlsCollection() {
	for (int i = 0; i < iControlsManager->getKNumParams(); i++) {
		switch (iControlsManager->controlsModelsCollection[i]->moduleName) {
		case ModulesModel::OSCILATORS:
			iModulesManager->iModOscillators->doModelsControlsInIControlsCollection(this, iControlsManager, iGraphicsManager, i);
			break;
		case ModulesModel::GAINFADERS:
			iModulesManager->iModGainFaders->doModelsControlsInIControlsCollection(this, iControlsManager, iGraphicsManager, i);
			break;
		case ModulesModel::FILTERS:
			iModulesManager->iModFilters->doModelsControlsInIControlsCollection(this, iControlsManager, iGraphicsManager, i);
			break;
		case ModulesModel::AMPENVELOPE:
			iModulesManager->iModAmpEnvelope->doModelsControlsInIControlsCollection(this, iControlsManager, iGraphicsManager, i);
			break;
		case ModulesModel::EQUILIBRIUM:
			iModulesManager->iModEQuilibrium->doModelsControlsInIControlsCollection(this, iControlsManager, iGraphicsManager, i);
			break;
		}
	}
}

void OhmBass::CreateKeyboard() {
	//                            C#     D#          F#      G#      A# (Quantos PX as notas # deslocam pra esquerda) 
	int keyCoordinates[12] = { 0, 20, 33, 57, 67, 99, 120, 132, 155, 165, 189, 198 };
	iGraphicsManager->mVirtualKeyboard = new IKeyboardControl(
		this,
		iGraphicsManager->kKeybX,
		iGraphicsManager->kKeybY,
		iGraphicsManager->virtualKeyboardMinimumNoteNumber,
		2,/* octaves: */
		&iGraphicsManager->whiteKeyImage,
		&iGraphicsManager->blackKeyImage,
		keyCoordinates
	);
	iGraphicsManager->pGraphics->AttachControl(iGraphicsManager->mVirtualKeyboard);
}


void OhmBass::CreatePresets() {
}


void OhmBass::ProcessDoubleReplacing(double** inputs, double** outputs, int nFrames)
{
	//Update all information about time
	GetTime(&iGraphicsManager->mTimeInfo);

	// Mutex is already locked for us.
	double *leftOutput = outputs[0];
	double *rightOutput = outputs[1];
	processVirtualKeyboard();
	for (int i = 0; i < nFrames; ++i) {
		mMIDIReceiver.advance();

		//Audio processing and FX
		double result;
		result = voiceManager.nextSample();
		result = iModulesManager->process(result);

		//Audio Final Output
		leftOutput[i] = rightOutput[i] = result;
	}

	mMIDIReceiver.Flush(nFrames);
}

void OhmBass::Reset()
{
	TRACE;
	IMutexLock lock(this);
	double sampleRate = GetSampleRate();
	voiceManager.setSampleRate(sampleRate);
}

void OhmBass::OnParamChange(int paramIdx)
{
	using std::placeholders::_1;
	using std::bind;

	IMutexLock lock(this);
	IParam* param = GetParam(paramIdx);
	int idxWaveMode = 0;
	idxWaveMode = param->Int();
	idxWaveMode--;
	VoiceManager::VoiceChangerFunction changer;
	if (iControlsManager->controlsModelsCollection[paramIdx]->moduleName == ModulesModel::EModulesName::OSCILATORS) {
		if (paramIdx == iModulesManager->iModOscillators->mBgBtnOscWavesOsc1) {
			changer = bind(&VoiceManager::setOscillatorMode, _1, 1, static_cast<Oscillator::OscillatorMode>(idxWaveMode));
		}
		else if (paramIdx == iModulesManager->iModOscillators->mBgBtnOscWavesOsc2) {
			changer = bind(&VoiceManager::setOscillatorMode, _1, 2, static_cast<Oscillator::OscillatorMode>(idxWaveMode));
		}
		else if (paramIdx == iModulesManager->iModOscillators->mOsc1PitchMod) {
			changer = bind(&VoiceManager::setOscillatorPitchMod, _1, 1, param->Value());
		}
		else if (paramIdx == iModulesManager->iModOscillators->mOsc2PitchMod) {
			changer = bind(&VoiceManager::setOscillatorPitchMod, _1, 2, param->Value());
		}
		iModulesManager->iModOscillators->OnParamChange(iControlsManager, paramIdx, idxWaveMode, isPluginInitialized);
	}else if (iControlsManager->controlsModelsCollection[paramIdx]->moduleName == ModulesModel::EModulesName::GAINFADERS) {
		if (paramIdx == iModulesManager->iModGainFaders->mFadersHandlerOnOsc1) {
			changer = bind(&VoiceManager::setOscillatorOneOutput, _1, param->Value());
		}
		else if (paramIdx == iModulesManager->iModGainFaders->mFadersHandlerOffOsc1) {
			changer = bind(&VoiceManager::setOscillatorOneOutput, _1, param->Value());
		}
		else if (paramIdx == iModulesManager->iModGainFaders->mFadersHandlerOnOsc2) {
			changer = bind(&VoiceManager::setOscillatorTwoOutput, _1, param->Value());
		}
		else if (paramIdx == iModulesManager->iModGainFaders->mFadersHandlerOffOsc2) {
			changer = bind(&VoiceManager::setOscillatorTwoOutput, _1, param->Value());
		}
		iModulesManager->iModGainFaders->OnParamChange(iControlsManager, paramIdx, isPluginInitialized, param);
	}
	else if (iControlsManager->controlsModelsCollection[paramIdx]->moduleName == ModulesModel::EModulesName::FILTERS) {
		if (isPluginInitialized) {
			if (strcmp(iControlsManager->controlsModelsCollection[paramIdx]->alias, "Filter Mode") == 0) {
				changer = bind(&VoiceManager::setFilterMode, _1, static_cast<Filter::FilterMode>(param->Int()));
			}
			else if (strcmp(iControlsManager->controlsModelsCollection[paramIdx]->alias, "Filter Cutoff") == 0) {
				changer = bind(&VoiceManager::setFilterCutoff, _1, param->Value());
			}
			else if (strcmp(iControlsManager->controlsModelsCollection[paramIdx]->alias, "Filter Resonance") == 0) {
				changer = bind(&VoiceManager::setFilterResonance, _1, param->Value());
			}
			else if (strcmp(iControlsManager->controlsModelsCollection[paramIdx]->alias, "Filter LFO Amount") == 0) {
				changer = bind(&VoiceManager::setFilterLFOAmount, _1, param->Value());
			}
			else if (strcmp(iControlsManager->controlsModelsCollection[paramIdx]->alias, "Filter Envelope Amount") == 0) {
				changer = bind(&VoiceManager::setFilterEnvAmount, _1, param->Value());
			}
			else if (strcmp(iControlsManager->controlsModelsCollection[paramIdx]->alias, "LFO Waveform") == 0) {
				voiceManager.setLFOMode(static_cast<Oscillator::OscillatorMode>(param->Int()));
			}
			else if (strcmp(iControlsManager->controlsModelsCollection[paramIdx]->alias, "LFO Frequency") == 0) {
				voiceManager.setLFOFrequency(param->Value());
			}
			else if (strcmp(iControlsManager->controlsModelsCollection[paramIdx]->alias, "Filter Env Attack") == 0) {
				changer = bind(&VoiceManager::setFilterEnvelopeStageValue, _1, EnvelopeGenerator::ENVELOPE_STAGE_ATTACK, param->Value());
			}
			else if (strcmp(iControlsManager->controlsModelsCollection[paramIdx]->alias, "Filter Env Decay") == 0) {
				changer = bind(&VoiceManager::setVolumeEnvelopeStageValue, _1, EnvelopeGenerator::ENVELOPE_STAGE_DECAY, param->Value());
			}
			else if (strcmp(iControlsManager->controlsModelsCollection[paramIdx]->alias, "Filter Env Sustain") == 0) {
				changer = bind(&VoiceManager::setFilterEnvelopeStageValue, _1, EnvelopeGenerator::ENVELOPE_STAGE_SUSTAIN, param->Value());
			}
			else if (strcmp(iControlsManager->controlsModelsCollection[paramIdx]->alias, "Filter Env Release") == 0) {
				changer = bind(&VoiceManager::setFilterEnvelopeStageValue, _1, EnvelopeGenerator::ENVELOPE_STAGE_RELEASE, param->Value());
			}

		}
	}
	else if (iControlsManager->controlsModelsCollection[paramIdx]->moduleName == ModulesModel::EModulesName::AMPENVELOPE) {
		if (strcmp(iControlsManager->controlsModelsCollection[paramIdx]->alias, "Volume Env Attack") == 0) {
			changer = bind(&VoiceManager::setVolumeEnvelopeStageValue, _1, EnvelopeGenerator::ENVELOPE_STAGE_ATTACK, param->Value());
		}
		else if (strcmp(iControlsManager->controlsModelsCollection[paramIdx]->alias, "Volume Env Decay") == 0) {
			changer = bind(&VoiceManager::setVolumeEnvelopeStageValue, _1, EnvelopeGenerator::ENVELOPE_STAGE_DECAY, param->Value());
		}
		else if (strcmp(iControlsManager->controlsModelsCollection[paramIdx]->alias, "Volume Env Sustain") == 0) {
			changer = bind(&VoiceManager::setVolumeEnvelopeStageValue, _1, EnvelopeGenerator::ENVELOPE_STAGE_SUSTAIN, param->Value());
		}
		else if (strcmp(iControlsManager->controlsModelsCollection[paramIdx]->alias, "Volume Env Release") == 0) {
			changer = bind(&VoiceManager::setVolumeEnvelopeStageValue, _1, EnvelopeGenerator::ENVELOPE_STAGE_RELEASE, param->Value());
		}
	}
	else if (iControlsManager->controlsModelsCollection[paramIdx]->moduleName == ModulesModel::EModulesName::EQUILIBRIUM) {
		if (strcmp(iControlsManager->controlsModelsCollection[paramIdx]->alias, "Knb Eql Low freq") == 0){
			this->voiceManager.setEQuilibriumLowFreq(param->Value());
			iModulesManager->iModEQuilibrium->setLowFreq(param->Value());	
			iModulesManager->iModEQuilibrium->updateLowFilterValues();
		}
		else if (strcmp(iControlsManager->controlsModelsCollection[paramIdx]->alias, "Knb Bost Low boost") == 0){
			this->voiceManager.setEQuilibriumLowGain(param->Value());
			iModulesManager->iModEQuilibrium->setLowBoost(param->Value());
			iModulesManager->iModEQuilibrium->updateLowFilterValues();
		}
		else if (strcmp(iControlsManager->controlsModelsCollection[paramIdx]->alias, "Knb Eql High freq") == 0) {
			this->voiceManager.setHighFreq(param->Value());
			iModulesManager->iModEQuilibrium->setHighFreq(param->Value());
			iModulesManager->iModEQuilibrium->updateHighFilterValues();
		}
		else if (strcmp(iControlsManager->controlsModelsCollection[paramIdx]->alias, "Knb Shelf Hihg shelf") == 0) {
			this->voiceManager.setHighShelf(param->Value());
			iModulesManager->iModEQuilibrium->setHighShelf(param->Value());
			iModulesManager->iModEQuilibrium->updateHighFilterValues();
		}
		else if (strcmp(iControlsManager->controlsModelsCollection[paramIdx]->alias, "ActiOhm Bass Magic") == 0) {
			iModulesManager->iModEQuilibrium->setActiOhmBassMagic(param->Value());
			//Init Filters
			iModulesManager->iModEQuilibrium->updateLowShelfFilter();
			iModulesManager->iModEQuilibrium->updateControlNasalHighFreq();
			iModulesManager->iModEQuilibrium->updateControlNasalLowFreq();
			iModulesManager->iModEQuilibrium->updateHighCutFilter();
		}
		
		
	}
	if (changer) {
		voiceManager.changeAllVoices(changer);
	}


}

void OhmBass::ProcessMidiMsg(IMidiMsg* pMsg) {
	mMIDIReceiver.onMessageReceived(pMsg);
	iGraphicsManager->mVirtualKeyboard->SetDirty();
}


void OhmBass::processVirtualKeyboard() {
	IKeyboardControl* virtualKeyboard = (IKeyboardControl*)iGraphicsManager->mVirtualKeyboard;
	int virtualKeyboardNoteNumber = virtualKeyboard->GetKey() + virtualKeyboardMinimumNoteNumber;

	if (lastVirtualKeyboardNoteNumber >= virtualKeyboardMinimumNoteNumber && virtualKeyboardNoteNumber != lastVirtualKeyboardNoteNumber) {
		// The note number has changed from a valid key to something else (valid key or nothing). Release the valid key:
		IMidiMsg midiMessage;
		midiMessage.MakeNoteOffMsg(lastVirtualKeyboardNoteNumber, 0);
		mMIDIReceiver.onMessageReceived(&midiMessage);
	}

	if (virtualKeyboardNoteNumber >= virtualKeyboardMinimumNoteNumber && virtualKeyboardNoteNumber != lastVirtualKeyboardNoteNumber) {
		// A valid key is pressed that wasn't pressed the previous call. Send a "note on" message to the MIDI receiver:
		IMidiMsg midiMessage;
		midiMessage.MakeNoteOnMsg(virtualKeyboardNoteNumber, virtualKeyboard->GetVelocity(), 0);
		mMIDIReceiver.onMessageReceived(&midiMessage);
	}

	lastVirtualKeyboardNoteNumber = virtualKeyboardNoteNumber;
}