#include "OhmBass.h"
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmain"
#include "IPlug_include_in_plug_src.h"
#pragma clang diagnostic pop
#include "IKeyboardControl.h"
#include "resource.h"

#include <math.h>
#include <algorithm>

IGraphics* pGraphics;

controlsManager* iControlsManager = new controlsManager();

const int kNumPrograms = 5;
bool isParametersInitialized = FALSE;
const int kNumParams = iControlsManager->kNumParams;




enum ELayout
{
	kWidth = GUI_WIDTH,
	kHeight = GUI_HEIGHT,
	kKeybX = 36,
	kKeybY = 606
};

OhmBass::OhmBass(IPlugInstanceInfo instanceInfo) : IPLUG_CTOR(kNumParams, kNumPrograms, instanceInfo), lastVirtualKeyboardNoteNumber(virtualKeyboardMinimumNoteNumber - 1) {
	TRACE;

	iControlsManager->createParams(this);
	CreateGraphics();
	CreatePresets();

	mMIDIReceiver.noteOn.Connect(&voiceManager, &VoiceManager::onNoteOn);
	mMIDIReceiver.noteOff.Connect(&voiceManager, &VoiceManager::onNoteOff);
}
OhmBass::~OhmBass() {}

void OhmBass::CreateGraphics() {
	pGraphics = MakeGraphics(this, kWidth, kHeight);

	//background
	pGraphics->AttachBackground(BG_ID, BG_FN);

	//keybooards
	IBitmap whiteKeyImage = pGraphics->LoadIBitmap(WHITE_KEY_ID, WHITE_KEY_FN, 6);
	IBitmap blackKeyImage = pGraphics->LoadIBitmap(BLACK_KEY_ID, BLACK_KEY_FN);
	//                            C#     D#          F#      G#      A# (Quantos PX as notas # deslocam pra esquerda) 
	int keyCoordinates[12] = { 0, 20, 33, 57, 67, 99, 120, 132, 155, 165, 189, 198 };
	mVirtualKeyboard = new IKeyboardControl(this, kKeybX, kKeybY, virtualKeyboardMinimumNoteNumber, /* octaves: */ 2, &whiteKeyImage, &blackKeyImage, keyCoordinates);
	pGraphics->AttachControl(mVirtualKeyboard);

	//Oscilattors
	IBitmap waveformBitmap = pGraphics->LoadIBitmap(WAVEFORM_ID, WAVEFORM_FN, 4);
	IBitmap filterModeBitmap = pGraphics->LoadIBitmap(FILTERMODE_ID, FILTERMODE_FN, 3);

	//knobs
	IBitmap knobBitmap = pGraphics->LoadIBitmap(KNOB_MEDIUM_ID, KNOB_MEDIUM, 47);

	//waves buttons icons
	IBitmap iconSineWaveOnOsc1 = pGraphics->LoadIBitmap(ICONSINEWAVEON_ID, ICONSINEWAVEON_FN);
	IBitmap iconSineWaveOffOsc1 = pGraphics->LoadIBitmap(ICONSINEWAVEOFF_ID, ICONSINEWAVEOFF_FN);
	IBitmap iconSawWaveOnOsc1 = pGraphics->LoadIBitmap(ICONSAWWAVEON_ID, ICONSAWWAVEON_FN);
	IBitmap iconSawWaveOffOsc1 = pGraphics->LoadIBitmap(ICONSAWWAVEOFF_ID, ICONSAWWAVEOFF_FN);
	IBitmap iconSquareWaveOnOsc1 = pGraphics->LoadIBitmap(ICONSQUAREWAVEON_ID, ICONSQUAREWAVEON_FN);
	IBitmap iconSquareWaveOffOsc1 = pGraphics->LoadIBitmap(ICONSQUAREWAVEOFF_ID, ICONSQUAREWAVEOFF_FN);
	IBitmap iconTriangleWaveOnOsc1 = pGraphics->LoadIBitmap(ICONTRIANGLEWAVEON_ID, ICONTRIANGLEWAVEON_FN);
	IBitmap iconTriangleWaveOffOsc1 = pGraphics->LoadIBitmap(ICONTRIANGLEWAVEOFF_ID, ICONTRIANGLEWAVEOFF_FN);
	IBitmap iconSineWaveOnOsc2 = pGraphics->LoadIBitmap(ICONSINEWAVEON_ID, ICONSINEWAVEON_FN);
	IBitmap iconSineWaveOffOsc2 = pGraphics->LoadIBitmap(ICONSINEWAVEOFF_ID, ICONSINEWAVEOFF_FN);
	IBitmap iconSawWaveOnOsc2 = pGraphics->LoadIBitmap(ICONSAWWAVEON_ID, ICONSAWWAVEON_FN);
	IBitmap iconSawWaveOffOsc2 = pGraphics->LoadIBitmap(ICONSAWWAVEOFF_ID, ICONSAWWAVEOFF_FN);
	IBitmap iconSquareWaveOnOsc2 = pGraphics->LoadIBitmap(ICONSQUAREWAVEON_ID, ICONSQUAREWAVEON_FN);
	IBitmap iconSquareWaveOffOsc2 = pGraphics->LoadIBitmap(ICONSQUAREWAVEOFF_ID, ICONSQUAREWAVEOFF_FN);
	IBitmap iconTriangleWaveOnOsc2 = pGraphics->LoadIBitmap(ICONTRIANGLEWAVEON_ID, ICONTRIANGLEWAVEON_FN);
	IBitmap iconTriangleWaveOffOsc2 = pGraphics->LoadIBitmap(ICONTRIANGLEWAVEOFF_ID, ICONTRIANGLEWAVEOFF_FN);

	IBitmap bgBtnOscWavesOsc1 = pGraphics->LoadIBitmap(BGBTNOSCWAVES_ID, BGBTNOSCWAVES_FN, 2);
	IBitmap bgBtnOscWavesOsc2 = pGraphics->LoadIBitmap(BGBTNOSCWAVES_ID, BGBTNOSCWAVES_FN, 2);



	for (int i = 0; i < kNumParams; i++) {
		controlsManager::parameterProperties_struct properties = iControlsManager->getParameterProperties(i);
		IParam* param = GetParam(i);
		IBitmap* graphic;
		switch (i) {
		//Buttons Waves
		case controlsManager::mBgBtnOscWavesOsc1:
			graphic = &bgBtnOscWavesOsc1;
			iControlsManager->control = new IRadioButtonsControl(this, IRECT(43, 206, 43 + (56 * 4), 56 + (60 * 4)), i, 4, graphic, kHorizontal);
			break;
		case controlsManager::mBgBtnOscWavesOsc2:
			graphic = &bgBtnOscWavesOsc2;
			iControlsManager->control = new IRadioButtonsControl(this, IRECT(43, 306, 43 + (56 * 4), 126 + (60 * 4)), i, 4, graphic, kHorizontal);
			break;
		//Osc1 Icons Buttons Waves
		case controlsManager::mIconSineWaveOffOsc1:
			graphic = &iconSineWaveOffOsc1;
			iControlsManager->control = new IBitmapControl(this, properties.x, properties.y, i, graphic);
			iControlsManager->control->Hide(!properties.defaultVal);
			iControlsManager->control->GrayOut(TRUE, 0.99f);
			break;
		case controlsManager::mIconSineWaveOnOsc1:
			graphic = &iconSineWaveOnOsc1;
			iControlsManager->Osc1ControlSineOn = new IBitmapControl(this, properties.x, properties.y, i, graphic);
			iControlsManager->Osc1ControlSineOn->Hide(!properties.defaultVal);
			iControlsManager->Osc1ControlSineOn->GrayOut(TRUE, 0.99f);
			pGraphics->AttachControl(iControlsManager->Osc1ControlSineOn);
			break;
		case iControlsManager->mIconSawWaveOffOsc1:
			graphic = &iconSawWaveOffOsc1;
			iControlsManager->control = new IBitmapControl(this, properties.x, properties.y, i, graphic);
			iControlsManager->control->Hide(!properties.defaultVal);
			iControlsManager->control->GrayOut(TRUE, 0.99f);
			break;
		case iControlsManager->mIconSawWaveOnOsc1:
			graphic = &iconSawWaveOnOsc1;
			iControlsManager->Osc1ControlSawOn = new IBitmapControl(this, properties.x, properties.y, i, graphic);
			iControlsManager->Osc1ControlSawOn->Hide(!properties.defaultVal);
			iControlsManager->Osc1ControlSawOn->GrayOut(TRUE, 0.99f);
			pGraphics->AttachControl(iControlsManager->Osc1ControlSawOn);
			break;
		case iControlsManager->mIconSqWaveOffOsc1:
			graphic = &iconSquareWaveOffOsc1;
			iControlsManager->control = new IBitmapControl(this, properties.x, properties.y, i, graphic);
			iControlsManager->control->Hide(!properties.defaultVal);
			iControlsManager->control->GrayOut(TRUE, 0.99f);
			break;
		case iControlsManager->mIconSqWaveOnOsc1:
			graphic = &iconSquareWaveOnOsc1;
			iControlsManager->Osc1ControlSquareOn = new IBitmapControl(this, properties.x, properties.y, i, graphic);
			iControlsManager->Osc1ControlSquareOn->Hide(!properties.defaultVal);
			iControlsManager->Osc1ControlSquareOn->GrayOut(TRUE, 0.99f);
			pGraphics->AttachControl(iControlsManager->Osc1ControlSquareOn);
			break;
		case iControlsManager->mIconTriangleWaveOffOsc1:
			graphic = &iconTriangleWaveOffOsc1;
			iControlsManager->control = new IBitmapControl(this, properties.x, properties.y, i, graphic);
			iControlsManager->control->Hide(!properties.defaultVal);
			iControlsManager->control->GrayOut(TRUE, 0.99f);
			break;
		case iControlsManager->mIconTriangleWaveOnOsc1:
			graphic = &iconTriangleWaveOnOsc1;
			iControlsManager->Osc1ControlTriagleOn = new IBitmapControl(this, properties.x, properties.y, i, graphic);
			iControlsManager->Osc1ControlTriagleOn->Hide(!properties.defaultVal);
			iControlsManager->Osc1ControlTriagleOn->GrayOut(TRUE, 0.99f);
			pGraphics->AttachControl(iControlsManager->Osc1ControlTriagleOn);
			break;
		//Osc2 Icons Buttons Waves
		case iControlsManager->mIconSineWaveOffOsc2:
			graphic = &iconSineWaveOffOsc2;
			iControlsManager->control = new IBitmapControl(this, properties.x, properties.y, i, graphic);
			iControlsManager->control->Hide(!properties.defaultVal);
			iControlsManager->control->GrayOut(TRUE, 0.99f);
			break;
		case iControlsManager->mIconSineWaveOnOsc2:
			graphic = &iconSineWaveOnOsc2;
			iControlsManager->Osc2ControlSineOn = new IBitmapControl(this, properties.x, properties.y, i, graphic);
			iControlsManager->Osc2ControlSineOn->Hide(!properties.defaultVal);
			iControlsManager->Osc2ControlSineOn->GrayOut(TRUE, 0.99f);
			pGraphics->AttachControl(iControlsManager->Osc2ControlSineOn);
			break;
		case iControlsManager->mIconSawWaveOffOsc2:
			graphic = &iconSawWaveOffOsc2;
			iControlsManager->control = new IBitmapControl(this, properties.x, properties.y, i, graphic);
			iControlsManager->control->SetBlendMethod(IChannelBlend::EBlendMethod::kBlendColorDodge);
			iControlsManager->control->Hide(!properties.defaultVal);
			iControlsManager->control->GrayOut(TRUE, 0.99f);
			break;
		case iControlsManager->mIconSawWaveOnOsc2:
			graphic = &iconSawWaveOnOsc2;
			iControlsManager->Osc2ControlSawOn = new IBitmapControl(this, properties.x, properties.y, i, graphic);
			iControlsManager->Osc2ControlSawOn->SetBlendMethod(IChannelBlend::EBlendMethod::kBlendColorDodge);
			iControlsManager->Osc2ControlSawOn->Hide(!properties.defaultVal);
			iControlsManager->Osc2ControlSawOn->GrayOut(TRUE, 0.99f);
			pGraphics->AttachControl(iControlsManager->Osc2ControlSawOn);
			break;
		case iControlsManager->mIconSqWaveOffOsc2:
			graphic = &iconSquareWaveOffOsc2;
			iControlsManager->control = new IBitmapControl(this, properties.x, properties.y, i, graphic);
			iControlsManager->control->SetBlendMethod(IChannelBlend::EBlendMethod::kBlendColorDodge);
			iControlsManager->control->Hide(!properties.defaultVal);
			iControlsManager->control->GrayOut(TRUE, 0.99f);
			break;
		case iControlsManager->mIconSqWaveOnOsc2:
			graphic = &iconSquareWaveOnOsc2;
			iControlsManager->Osc2ControlSquareOn = new IBitmapControl(this, properties.x, properties.y, i, graphic);
			iControlsManager->Osc2ControlSquareOn->SetBlendMethod(IChannelBlend::EBlendMethod::kBlendColorDodge);
			iControlsManager->Osc2ControlSquareOn->Hide(!properties.defaultVal);
			iControlsManager->Osc2ControlSquareOn->GrayOut(TRUE, 0.99f);
			pGraphics->AttachControl(iControlsManager->Osc2ControlSquareOn);
			break;
		case iControlsManager->mIconTriangleWaveOffOsc2:
			graphic = &iconTriangleWaveOffOsc2;
			iControlsManager->control = new IBitmapControl(this, properties.x, properties.y, i, graphic);
			iControlsManager->control->SetBlendMethod(IChannelBlend::EBlendMethod::kBlendColorDodge);
			iControlsManager->control->Hide(!properties.defaultVal);
			iControlsManager->control->GrayOut(TRUE, 0.99f);
			break;
		case iControlsManager->mIconTriangleWaveOnOsc2:
			graphic = &iconTriangleWaveOnOsc2;
			iControlsManager->Osc2ControlTriagleOn = new IBitmapControl(this, properties.x, properties.y, i, graphic);
			iControlsManager->Osc2ControlTriagleOn->SetBlendMethod(IChannelBlend::EBlendMethod::kBlendColorDodge);
			iControlsManager->Osc2ControlTriagleOn->Hide(!properties.defaultVal);
			iControlsManager->Osc2ControlTriagleOn->GrayOut(TRUE, 0.99f);
			pGraphics->AttachControl(iControlsManager->Osc2ControlTriagleOn);
			break;
		//LFO
		case iControlsManager->mLFOWaveform:
			graphic = &waveformBitmap;
			iControlsManager->control = new ISwitchControl(this, properties.x, properties.y, i, graphic);
			break;
		case iControlsManager->mFilterMode:
			graphic = &filterModeBitmap;
			iControlsManager->control = new ISwitchControl(this, properties.x, properties.y, i, graphic);
			break;
			// Knobs:
		default:
			graphic = &knobBitmap;
			iControlsManager->control = new IKnobMultiControl(this, properties.x, properties.y, i, graphic);
			break;
		}
		if (
			i != iControlsManager->mIconSineWaveOnOsc1 && 
			i != iControlsManager->mIconSawWaveOnOsc1 && 
			i != iControlsManager->mIconSqWaveOnOsc1 && 
			i != iControlsManager->mIconTriangleWaveOnOsc1 && 
			i != iControlsManager->mIconSineWaveOnOsc2 && 
			i != iControlsManager->mIconSawWaveOnOsc2 && 
			i != iControlsManager->mIconSqWaveOnOsc2 && 
			i != iControlsManager->mIconTriangleWaveOnOsc2) {
			pGraphics->AttachControl(iControlsManager->control);
		}
		
	}
	AttachGraphics(pGraphics);
	isParametersInitialized = TRUE;
}

void OhmBass::CreatePresets() {
}


void OhmBass::ProcessDoubleReplacing(
	double** inputs,
	double** outputs,
	int nFrames)
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
	IMutexLock lock(this);
	IParam* param = GetParam(paramIdx);
	int idxWaveMode = 0;
	if (paramIdx == iControlsManager->mLFOWaveform) {
		voiceManager.setLFOMode(static_cast<Oscillator::OscillatorMode>(param->Int()));
	}
	else if (paramIdx == iControlsManager->mLFOFrequency) {
		voiceManager.setLFOFrequency(param->Value());
	}
	else if (paramIdx == iControlsManager->mIconSineWaveOffOsc1 ||
		paramIdx == iControlsManager->mIconSineWaveOnOsc1 ||
		paramIdx == iControlsManager->mIconSawWaveOffOsc1 ||
		paramIdx == iControlsManager->mIconSawWaveOnOsc1 ||
		paramIdx == iControlsManager->mIconSqWaveOffOsc1 ||
		paramIdx == iControlsManager->mIconSqWaveOnOsc1 ||
		paramIdx == iControlsManager->mIconTriangleWaveOffOsc1 ||
		paramIdx == iControlsManager->mIconTriangleWaveOnOsc1 ||
		paramIdx == iControlsManager->mIconSineWaveOffOsc1 ||
		paramIdx == iControlsManager->mIconSineWaveOnOsc1 ||
		paramIdx == iControlsManager->mIconSawWaveOffOsc1 ||
		paramIdx == iControlsManager->mIconSawWaveOnOsc1 ||
		paramIdx == iControlsManager->mIconSqWaveOffOsc1 ||
		paramIdx == iControlsManager->mIconSqWaveOnOsc1 ||
		paramIdx == iControlsManager->mIconTriangleWaveOffOsc1 ||
		paramIdx == iControlsManager->mIconTriangleWaveOnOsc1 ||
		paramIdx == iControlsManager->mIconSineWaveOffOsc2 ||
		paramIdx == iControlsManager->mIconSineWaveOnOsc2 ||
		paramIdx == iControlsManager->mIconSawWaveOffOsc2 ||
		paramIdx == iControlsManager->mIconSawWaveOnOsc2 ||
		paramIdx == iControlsManager->mIconSqWaveOffOsc2 ||
		paramIdx == iControlsManager->mIconSqWaveOnOsc2 ||
		paramIdx == iControlsManager->mIconTriangleWaveOffOsc2 ||
		paramIdx == iControlsManager->mIconTriangleWaveOnOsc2
		) {
		//blank
	} else {
		using std::placeholders::_1;
		using std::bind;
		VoiceManager::VoiceChangerFunction changer;
		switch (paramIdx) {
			case iControlsManager->mBgBtnOscWavesOsc1:
				idxWaveMode = param->Int();
				idxWaveMode--;
				changer = bind(&VoiceManager::setOscillatorMode, _1, 1, static_cast<Oscillator::OscillatorMode>(idxWaveMode));
				if (isParametersInitialized) {
					ToggleIconsWavesButtons(1, idxWaveMode);
				}
				break;
			case iControlsManager->mBgBtnOscWavesOsc2:
				idxWaveMode = param->Int();
				idxWaveMode--;
				changer = bind(&VoiceManager::setOscillatorMode, _1, 2, static_cast<Oscillator::OscillatorMode>(idxWaveMode));
				if (isParametersInitialized) {
					ToggleIconsWavesButtons(2, idxWaveMode);
				}
				break;
			case iControlsManager->mOsc1PitchMod:
				changer = bind(&VoiceManager::setOscillatorPitchMod, _1, 1, param->Value());
				break;
			case iControlsManager->mOsc2PitchMod:
				changer = bind(&VoiceManager::setOscillatorPitchMod, _1, 2, param->Value());
				break;
			case iControlsManager->mOscMix:
				changer = bind(&VoiceManager::setOscillatorMix, _1, param->Value());
				break;
				// Filter Section:
			case iControlsManager->mFilterMode:
				changer = bind(&VoiceManager::setFilterMode, _1, static_cast<Filter::FilterMode>(param->Int()));
				break;
			case iControlsManager->mFilterCutoff:
				changer = bind(&VoiceManager::setFilterCutoff, _1, param->Value());
				break;
			case iControlsManager->mFilterResonance:
				changer = bind(&VoiceManager::setFilterResonance, _1, param->Value());
				break;
			case iControlsManager->mFilterLfoAmount:
				changer = bind(&VoiceManager::setFilterLFOAmount, _1, param->Value());
				break;
			case iControlsManager->mFilterEnvAmount:
				changer = bind(&VoiceManager::setFilterEnvAmount, _1, param->Value());
				break;
				// Volume Envelope:
			case iControlsManager->mVolumeEnvAttack:
				changer = bind(&VoiceManager::setVolumeEnvelopeStageValue, _1, EnvelopeGenerator::ENVELOPE_STAGE_ATTACK, param->Value());
				break;
			case iControlsManager->mVolumeEnvDecay:
				changer = bind(&VoiceManager::setVolumeEnvelopeStageValue, _1, EnvelopeGenerator::ENVELOPE_STAGE_DECAY, param->Value());
				break;
			case iControlsManager->mVolumeEnvSustain:
				changer = bind(&VoiceManager::setVolumeEnvelopeStageValue, _1, EnvelopeGenerator::ENVELOPE_STAGE_SUSTAIN, param->Value());
				break;
			case iControlsManager->mVolumeEnvRelease:
				changer = bind(&VoiceManager::setVolumeEnvelopeStageValue, _1, EnvelopeGenerator::ENVELOPE_STAGE_RELEASE, param->Value());
				break;
				// Filter Envelope:
			case iControlsManager->mFilterEnvAttack:
				changer = bind(&VoiceManager::setFilterEnvelopeStageValue, _1, EnvelopeGenerator::ENVELOPE_STAGE_ATTACK, param->Value());
				break;
			case iControlsManager->mFilterEnvDecay:
				changer = bind(&VoiceManager::setFilterEnvelopeStageValue, _1, EnvelopeGenerator::ENVELOPE_STAGE_DECAY, param->Value());
				break;
			case iControlsManager->mFilterEnvSustain:
				changer = bind(&VoiceManager::setFilterEnvelopeStageValue, _1, EnvelopeGenerator::ENVELOPE_STAGE_SUSTAIN, param->Value());
				break;
			case iControlsManager->mFilterEnvRelease:
				changer = bind(&VoiceManager::setFilterEnvelopeStageValue, _1, EnvelopeGenerator::ENVELOPE_STAGE_RELEASE, param->Value());
				break;
		}
		if (changer) {
			voiceManager.changeAllVoices(changer);
		}
		
	}
}

void OhmBass::ProcessMidiMsg(IMidiMsg* pMsg) {
	mMIDIReceiver.onMessageReceived(pMsg);
	mVirtualKeyboard->SetDirty();
}

void OhmBass::ToggleIconsWavesButtons(int nOsc, int idxWaveMode) {
	if (nOsc == 1) {
		switch (idxWaveMode) {
		case 0:
			iControlsManager->Osc1ControlSineOn->Hide(FALSE);
			iControlsManager->Osc1ControlSawOn->Hide(TRUE);
			iControlsManager->Osc1ControlSquareOn->Hide(TRUE);
			iControlsManager->Osc1ControlTriagleOn->Hide(TRUE);
			break;
		case 1:
			iControlsManager->Osc1ControlSineOn->Hide(TRUE);
			iControlsManager->Osc1ControlSawOn->Hide(FALSE);
			iControlsManager->Osc1ControlSquareOn->Hide(TRUE);
			iControlsManager->Osc1ControlTriagleOn->Hide(TRUE);
			break;
		case 2:
			iControlsManager->Osc1ControlSineOn->Hide(TRUE);
			iControlsManager->Osc1ControlSawOn->Hide(TRUE);
			iControlsManager->Osc1ControlSquareOn->Hide(FALSE);
			iControlsManager->Osc1ControlTriagleOn->Hide(TRUE);
			break;
		case 3:
			iControlsManager->Osc1ControlSineOn->Hide(TRUE);
			iControlsManager->Osc1ControlSawOn->Hide(TRUE);
			iControlsManager->Osc1ControlSquareOn->Hide(TRUE);
			iControlsManager->Osc1ControlTriagleOn->Hide(FALSE);
			break;
		}

	}
	else if (nOsc == 2) {
		switch (idxWaveMode) {
		case 0:
			iControlsManager->Osc2ControlSineOn->Hide(FALSE);
			iControlsManager->Osc2ControlSawOn->Hide(TRUE);
			iControlsManager->Osc2ControlSquareOn->Hide(TRUE);
			iControlsManager->Osc2ControlTriagleOn->Hide(TRUE);
			break;
		case 1:
			iControlsManager->Osc2ControlSineOn->Hide(TRUE);
			iControlsManager->Osc2ControlSawOn->Hide(FALSE);
			iControlsManager->Osc2ControlSquareOn->Hide(TRUE);
			iControlsManager->Osc2ControlTriagleOn->Hide(TRUE);
			break;
		case 2:
			iControlsManager->Osc2ControlSineOn->Hide(TRUE);
			iControlsManager->Osc2ControlSawOn->Hide(TRUE);
			iControlsManager->Osc2ControlSquareOn->Hide(FALSE);
			iControlsManager->Osc2ControlTriagleOn->Hide(TRUE);
			break;
		case 3:
			iControlsManager->Osc2ControlSineOn->Hide(TRUE);
			iControlsManager->Osc2ControlSawOn->Hide(TRUE);
			iControlsManager->Osc2ControlSquareOn->Hide(TRUE);
			iControlsManager->Osc2ControlTriagleOn->Hide(FALSE);
			break;
		}

	}
}
void OhmBass::processVirtualKeyboard() {
	IKeyboardControl* virtualKeyboard = (IKeyboardControl*)mVirtualKeyboard;
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