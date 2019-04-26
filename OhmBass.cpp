#pragma once
#include "OhmBass.h"
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmain"
#include "IPlug_include_in_plug_src.h"
#pragma clang diagnostic pop
#include "resource.h"
#include "IKeyboardControl.h"
#include <math.h>
#include <algorithm>




const int kNumPrograms = 5; //Qtd of presets
bool isPluginInitialized = FALSE;
//Helpers for managers elements
controlsManager* iControlsManager = new controlsManager();
graphicsManager* iGraphicsManager = new graphicsManager();



const int kNumParams = iControlsManager->getKNumParams(); //Qtd for params



OhmBass::OhmBass(IPlugInstanceInfo instanceInfo) : IPLUG_CTOR(kNumParams, kNumPrograms, instanceInfo), lastVirtualKeyboardNoteNumber(virtualKeyboardMinimumNoteNumber - 1) {
	TRACE;

	

	//crete all params
	iControlsManager->createParams(this);
	//create the main display
	CreateMainDisplay();
	//load all graphics
	iGraphicsManager->AttachBackgroundMainDisplay();
	iGraphicsManager->loadKeyboard();
	/*iGraphicsManager->loadOscWavesModes();
	iGraphicsManager->loadFiltersModes();
	iGraphicsManager->loadKnobs();
	iGraphicsManager->loadWavesIcons();
	iGraphicsManager->loadOscWavesButtonsBackgrounds();
	iGraphicsManager->loadGhrrEqlControls();
	iGraphicsManager->loadFaders();*/
	
	//create keyboard
	CreateKeyboard();
	//Attach the controls in graphics
	/*iGraphicsManager->attachGraphicsInControls(this, iControlsManager);*/
	//Attach all graphics with your respective controls in main screen
	AttachGraphics(iGraphicsManager->pGraphics);

	//Flag to indicate when the plugin was full started
	isPluginInitialized = TRUE;
	//Create all default presets
	CreatePresets();

	

	mMIDIReceiver.noteOn.Connect(&voiceManager, &VoiceManager::onNoteOn);
	mMIDIReceiver.noteOff.Connect(&voiceManager, &VoiceManager::onNoteOff);
}
OhmBass::~OhmBass() {}

void OhmBass::CreateMainDisplay() {
	iGraphicsManager->pGraphics = MakeGraphics(this, iGraphicsManager->kWidth, iGraphicsManager->kHeight);
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
	// Mutex is already locked for us.

	double *leftOutput = outputs[0];
	double *rightOutput = outputs[1];
	processVirtualKeyboard();
	for (int i = 0; i < nFrames; ++i) {
		mMIDIReceiver.advance();
		leftOutput[i] = rightOutput[i] = voiceManager.nextSample();
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
//	IMutexLock lock(this);
//	IParam* param = GetParam(paramIdx);
//	int idxWaveMode = 0;
//	if (paramIdx == iControlsManager->mLFOWaveform) {
//		voiceManager.setLFOMode(static_cast<Oscillator::OscillatorMode>(param->Int()));
//	}
//	else if (paramIdx == iControlsManager->mLFOFrequency) {
//		voiceManager.setLFOFrequency(param->Value());
//
//	} else {
//		using std::placeholders::_1;
//		using std::bind;
//		VoiceManager::VoiceChangerFunction changer;
//		switch (paramIdx) {
//			case iControlsManager->mBgBtnOscWavesOsc1:
//				idxWaveMode = param->Int();
//				idxWaveMode--;
//				changer = bind(&VoiceManager::setOscillatorMode, _1, 1, static_cast<Oscillator::OscillatorMode>(idxWaveMode));
//				if (isPluginInitialized) {
//					iControlsManager->ToggleIconsWavesButtons(1, idxWaveMode);
//				}
//				break;
//			case iControlsManager->mBgBtnOscWavesOsc2:
//				idxWaveMode = param->Int();
//				idxWaveMode--;
//				changer = bind(&VoiceManager::setOscillatorMode, _1, 2, static_cast<Oscillator::OscillatorMode>(idxWaveMode));
//				if (isPluginInitialized) {
//					iControlsManager->ToggleIconsWavesButtons(2, idxWaveMode);
//				}
//				break;
//				//FADERS
//			case iControlsManager->mFadersHandlerOffOsc1:
//				if (isPluginInitialized) {
//					iControlsManager->Osc1FaderHandlerOff->Hide(TRUE);
//					iControlsManager->Osc1FaderHandlerOff->GrayOut(TRUE, 0.99f);
//
//					iControlsManager->Osc1FaderHandlerOn->Hide(FALSE);
//					iControlsManager->Osc1FaderHandlerOn->GrayOut(FALSE);
//
//					iControlsManager->Osc2FaderHandlerOn->Hide(TRUE);
//					iControlsManager->Osc2FaderHandlerOn->GrayOut(TRUE, 0.99f);
//
//					iControlsManager->Osc2FaderHandlerOff->Hide(FALSE);
//					iControlsManager->Osc2FaderHandlerOff->GrayOut(FALSE);
//
//					iControlsManager->Osc1FaderHandlerOn->SetValueFromPlug(param->Value());
//					iControlsManager->Osc1FaderHandlerOff->SetValueFromPlug(param->Value());
//
//
//					changer = bind(&VoiceManager::setOscillatorOneOutput, _1, param->Value());
//				}
//				break;
//			case iControlsManager->mFadersHandlerOnOsc1:
//				if (isPluginInitialized) {
//					iControlsManager->Osc1FaderHandlerOff->SetValueFromPlug(param->Value());
//					iControlsManager->Osc1FaderHandlerOn->SetValueFromPlug(param->Value());
//
//					changer = bind(&VoiceManager::setOscillatorOneOutput, _1, param->Value());
//				}
//				break;
//			case iControlsManager->mFadersHandlerOffOsc2:
//				if (isPluginInitialized) {
//					iControlsManager->Osc2FaderHandlerOff->Hide(TRUE);
//					iControlsManager->Osc2FaderHandlerOff->GrayOut(TRUE, 0.99f);
//
//					iControlsManager->Osc2FaderHandlerOn->Hide(FALSE);
//					iControlsManager->Osc2FaderHandlerOn->GrayOut(FALSE);
//
//					iControlsManager->Osc1FaderHandlerOn->Hide(TRUE);
//					iControlsManager->Osc1FaderHandlerOn->GrayOut(TRUE, 0.99f);
//
//					iControlsManager->Osc1FaderHandlerOff->Hide(FALSE);
//					iControlsManager->Osc1FaderHandlerOff->GrayOut(FALSE);
//
//					iControlsManager->Osc2FaderHandlerOn->SetValueFromPlug(param->Value());
//					iControlsManager->Osc2FaderHandlerOff->SetValueFromPlug(param->Value());
//
//
//					changer = bind(&VoiceManager::setOscillatorTwoOutput, _1, param->Value());
//				}
//				break;
//			case iControlsManager->mFadersHandlerOnOsc2:
//				if (isPluginInitialized) {
//					iControlsManager->Osc2FaderHandlerOff->SetValueFromPlug(param->Value());
//					iControlsManager->Osc2FaderHandlerOn->SetValueFromPlug(param->Value());
//
//					changer = bind(&VoiceManager::setOscillatorTwoOutput, _1, param->Value());
//				}
//				break;
//				//Pitch Osc
//			case iControlsManager->mOsc1PitchMod:
//				changer = bind(&VoiceManager::setOscillatorPitchMod, _1, 1, param->Value());
//				break;
//			case iControlsManager->mOsc2PitchMod:
//				changer = bind(&VoiceManager::setOscillatorPitchMod, _1, 2, param->Value());
//				break;
//				// Filter Section:
//			case iControlsManager->mFilterMode:
//				changer = bind(&VoiceManager::setFilterMode, _1, static_cast<Filter::FilterMode>(param->Int()));
//				break;
//			case iControlsManager->mFilterCutoff:
//				changer = bind(&VoiceManager::setFilterCutoff, _1, param->Value());
//				break;
//			case iControlsManager->mFilterResonance:
//				changer = bind(&VoiceManager::setFilterResonance, _1, param->Value());
//				break;
//			case iControlsManager->mFilterLfoAmount:
//				changer = bind(&VoiceManager::setFilterLFOAmount, _1, param->Value());
//				break;
//			case iControlsManager->mFilterEnvAmount:
//				changer = bind(&VoiceManager::setFilterEnvAmount, _1, param->Value());
//				break;
//				// Volume Envelope:
//			case iControlsManager->mVolumeEnvAttack:
//				changer = bind(&VoiceManager::setVolumeEnvelopeStageValue, _1, EnvelopeGenerator::ENVELOPE_STAGE_ATTACK, param->Value());
//				break;
//			case iControlsManager->mVolumeEnvDecay:
//				changer = bind(&VoiceManager::setVolumeEnvelopeStageValue, _1, EnvelopeGenerator::ENVELOPE_STAGE_DECAY, param->Value());
//				break;
//			case iControlsManager->mVolumeEnvSustain:
//				changer = bind(&VoiceManager::setVolumeEnvelopeStageValue, _1, EnvelopeGenerator::ENVELOPE_STAGE_SUSTAIN, param->Value());
//				break;
//			case iControlsManager->mVolumeEnvRelease:
//				changer = bind(&VoiceManager::setVolumeEnvelopeStageValue, _1, EnvelopeGenerator::ENVELOPE_STAGE_RELEASE, param->Value());
//				break;
//				// Filter Envelope:
//			case iControlsManager->mFilterEnvAttack:
//				changer = bind(&VoiceManager::setFilterEnvelopeStageValue, _1, EnvelopeGenerator::ENVELOPE_STAGE_ATTACK, param->Value());
//				break;
//			case iControlsManager->mFilterEnvDecay:
//				changer = bind(&VoiceManager::setFilterEnvelopeStageValue, _1, EnvelopeGenerator::ENVELOPE_STAGE_DECAY, param->Value());
//				break;
//			case iControlsManager->mFilterEnvSustain:
//				changer = bind(&VoiceManager::setFilterEnvelopeStageValue, _1, EnvelopeGenerator::ENVELOPE_STAGE_SUSTAIN, param->Value());
//				break;
//			case iControlsManager->mFilterEnvRelease:
//				changer = bind(&VoiceManager::setFilterEnvelopeStageValue, _1, EnvelopeGenerator::ENVELOPE_STAGE_RELEASE, param->Value());
//				break;
//			//EQ-LIBRIUM
//			case iControlsManager->mGhrEqlLowFreq:
//				iModEQuilibrium->setLowFreq(param->Value());
//				break;
//			case iControlsManager->mGhrBostLowFreq:
//				iModEQuilibrium->setLowBoost(param->Value());
//				break;
//			case iControlsManager->mGhrEqlHihgFreq:
//				iModEQuilibrium->setHighFreq(param->Value());
//				break;
//			case iControlsManager->mGhrShelfHihgFreq:
//				iModEQuilibrium->setHighShelf(param->Value());
//				break;
//		}
//		if (changer) {
//			voiceManager.changeAllVoices(changer);
//		}
//		
//	}
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