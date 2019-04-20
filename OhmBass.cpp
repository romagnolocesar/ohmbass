#include "OhmBass.h"
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmain"
#include "IPlug_include_in_plug_src.h"
#pragma clang diagnostic pop
#include "IControl.h"
#include "IKeyboardControl.h"
#include "controlsManager.h"
#include "resource.h"

#include <math.h>
#include <algorithm>

IGraphics* pGraphics;
IControl* control;

IControl* Osc1ControlSineOn;
IControl* Osc1ControlSawOn;
IControl* Osc1ControlSquareOn;
IControl* Osc1ControlTriagleOn;
IControl* Osc2ControlSineOn;
IControl* Osc2ControlSawOn;
IControl* Osc2ControlSquareOn;
IControl* Osc2ControlTriagleOn;

const int kNumPrograms = 5;
const double parameterStep = 0.001;
bool isParametersInitialized = FALSE;

enum EParams
{
	// Oscillator Section:
	mBgBtnOscWavesOsc1 = 0,
	mBgBtnOscWavesOsc2,
	mIconSineWaveOffOsc1,
	mIconSineWaveOnOsc1,
	mIconSawWaveOffOsc1,
	mIconSawWaveOnOsc1,
	mIconSqWaveOffOsc1,
	mIconSqWaveOnOsc1,
	mIconTriangleWaveOffOsc1,
	mIconTriangleWaveOnOsc1,
	mIconSineWaveOffOsc2,
	mIconSineWaveOnOsc2,
	mIconSawWaveOffOsc2,
	mIconSawWaveOnOsc2,
	mIconSqWaveOffOsc2,
	mIconSqWaveOnOsc2,
	mIconTriangleWaveOffOsc2,
	mIconTriangleWaveOnOsc2,
	mOsc1PitchMod,
	mOsc2PitchMod,
	mOscMix,
	// Filter Section:
	mFilterMode,
	mFilterCutoff,
	mFilterResonance,
	mFilterLfoAmount,
	mFilterEnvAmount,
	// LFO:
	mLFOWaveform,
	mLFOFrequency,
	// Volume Envelope:
	mVolumeEnvAttack,
	mVolumeEnvDecay,
	mVolumeEnvSustain,
	mVolumeEnvRelease,
	// Filter Envelope:
	mFilterEnvAttack,
	mFilterEnvDecay,
	mFilterEnvSustain,
	mFilterEnvRelease,
	kNumParams
};


typedef struct {
	const char* name;
	const int x;
	const int y;
	const double defaultVal;
	const double minVal;
	const double maxVal;
} parameterProperties_struct;

const parameterProperties_struct parameterProperties[kNumParams] = 
{	
  {"Bg Btn Osc 1 Waves", 99, 206, 0.0, 0.0, 1.0},
  {"Bg Btn Osc 2 Waves", 99, 306, 0.0, 0.0, 1.0},
  {"Icon Sine Wave Off OSC1", 58, 218, TRUE},
  {"Icon Sine Wave On OSC1", 58, 218, TRUE},
  {"Icon Saw Wave Off OSC1", 114, 218, TRUE},
  {"Icon Saw Wave On OSC1", 114, 218, FALSE},
  {"Icon Square Wave Off OSC1", 170, 218, TRUE},
  {"Icon Square Wave On OSC1", 170, 218, FALSE},
  {"Icon Triangle Wave Off OSC1", 226, 218, TRUE},
  {"Icon Triangle Wave On OSC1", 226, 218, FALSE},
  {"Icon Sine Wave Off OSC2", 58, 318, TRUE},
  {"Icon Sine Wave On OSC2", 58, 318, TRUE},
  {"Icon Saw Wave Off OSC2", 114, 318, TRUE},
  {"Icon Saw Wave On OSC2", 114, 318, FALSE},
  {"Icon Square Wave Off OSC2", 170, 318, TRUE},
  {"Icon Square Wave On OSC2", 170, 318, FALSE},
  {"Icon Triangle Wave Off OSC2", 226, 318, TRUE},
  {"Icon Triangle Wave On OSC2", 226, 318, FALSE},
  {"Osc 1 Pitch Mod", 308, 195, 0.0, 0.0, 1.0},
  {"Osc 2 Pitch Mod", 308, 295, 0.0, 0.0, 1.0},
  {"Osc Mix", 480, 200, 0.5, 0.0, 1.0},
  {"Filter Mode", 875, 300},
  {"Filter Cutoff", 635, 343, 0.99, 0.0, 0.99},
  {"Filter Resonance", 730, 343, 0.0, 0.0, 1.0},
  {"Filter LFO Amount", 820, 343, 0.0, 0.0, 1.0},
  {"Filter Envelope Amount", 915, 343, 0.0, -1.0, 1.0},
  {"LFO Waveform", 30, 498},
  {"LFO Frequency", 69, 484, 6.0, 0.01, 30.0},
  {"Volume Env Attack", 35, 15, 0.01, 0.01, 10.0},
  {"Volume Env Decay", 130, 15, 0.5, 0.01, 15.0},
  {"Volume Env Sustain", 225, 15, 0.1, 0.001, 1.0},
  {"Volume Env Release", 320, 15, 1.0, 0.01, 15.0},
  {"Filter Env Attack", 635, 193, 0.01, 0.01, 10.0},
  {"Filter Env Decay", 730, 193, 0.5, 0.01, 15.0},
  {"Filter Env Sustain", 820, 193, 0.1, 0.001, 1.0},
  {"Filter Env Release", 915, 193, 1.0, 0.01, 15.0}
};

enum ELayout
{
	kWidth = GUI_WIDTH,
	kHeight = GUI_HEIGHT,
	kKeybX = 36,
	kKeybY = 606
};

OhmBass::OhmBass(IPlugInstanceInfo instanceInfo) : IPLUG_CTOR(kNumParams, kNumPrograms, instanceInfo), lastVirtualKeyboardNoteNumber(virtualKeyboardMinimumNoteNumber - 1) {
	TRACE;

	CreateParams();
	CreateGraphics();
	CreatePresets();

	mMIDIReceiver.noteOn.Connect(&voiceManager, &VoiceManager::onNoteOn);
	mMIDIReceiver.noteOff.Connect(&voiceManager, &VoiceManager::onNoteOff);
}
OhmBass::~OhmBass() {}
void OhmBass::CreateParams() {
	for (int i = 0; i < kNumParams; i++) {
		IParam* param = GetParam(i);
		const parameterProperties_struct& properties = parameterProperties[i];
		switch (i) {
		case mBgBtnOscWavesOsc1:
			param->InitInt(properties.name, 1, 1, 4, "osc1waves");
			break;
		case mBgBtnOscWavesOsc2:
			param->InitInt(properties.name, 1, 1, 4, "osc2waves");
			break;
		case mLFOWaveform:
			param->InitEnum(properties.name,
				Oscillator::OSCILLATOR_MODE_TRIANGLE,
				Oscillator::kNumOscillatorModes);
			// For VST3:
			param->SetDisplayText(0, properties.name);
			break;
		case mFilterMode:
			param->InitEnum(properties.name,
				Filter::FILTER_MODE_LOWPASS,
				Filter::kNumFilterModes);
			break;
		default:
			param->InitDouble(properties.name,
				properties.defaultVal,
				properties.minVal,
				properties.maxVal,
				parameterStep);
			break;
		}
	}
	GetParam(mFilterCutoff)->SetShape(2);
	GetParam(mVolumeEnvAttack)->SetShape(3);
	GetParam(mFilterEnvAttack)->SetShape(3);
	GetParam(mVolumeEnvDecay)->SetShape(3);
	GetParam(mFilterEnvDecay)->SetShape(3);
	GetParam(mVolumeEnvSustain)->SetShape(2);
	GetParam(mFilterEnvSustain)->SetShape(2);
	GetParam(mVolumeEnvRelease)->SetShape(3);
	GetParam(mFilterEnvRelease)->SetShape(3);
	for (int i = 0; i < kNumParams; i++) {
		OnParamChange(i);
	}
}

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
	IBitmap iconSawWaveOnOsc1 = pGraphics->LoadIBitmap(ICONSAWWAVEON_ID, ICONSAWWAVEON_FN);
	IBitmap iconSawWaveOffOsc1 = pGraphics->LoadIBitmap(ICONSAWWAVEOFF_ID, ICONSAWWAVEOFF_FN);
	IBitmap iconSineWaveOnOsc1 = pGraphics->LoadIBitmap(ICONSINEWAVEON_ID, ICONSINEWAVEON_FN);
	IBitmap iconSineWaveOffOsc1 = pGraphics->LoadIBitmap(ICONSINEWAVEOFF_ID, ICONSINEWAVEOFF_FN);
	IBitmap iconSquareWaveOnOsc1 = pGraphics->LoadIBitmap(ICONSQUAREWAVEON_ID, ICONSQUAREWAVEON_FN);
	IBitmap iconSquareWaveOffOsc1 = pGraphics->LoadIBitmap(ICONSQUAREWAVEOFF_ID, ICONSQUAREWAVEOFF_FN);
	IBitmap iconTriangleWaveOnOsc1 = pGraphics->LoadIBitmap(ICONTRIANGLEWAVEON_ID, ICONTRIANGLEWAVEON_FN);
	IBitmap iconTriangleWaveOffOsc1 = pGraphics->LoadIBitmap(ICONTRIANGLEWAVEOFF_ID, ICONTRIANGLEWAVEOFF_FN);
	IBitmap iconSawWaveOnOsc2 = pGraphics->LoadIBitmap(ICONSAWWAVEON_ID, ICONSAWWAVEON_FN);
	IBitmap iconSawWaveOffOsc2 = pGraphics->LoadIBitmap(ICONSAWWAVEOFF_ID, ICONSAWWAVEOFF_FN);
	IBitmap iconSineWaveOnOsc2 = pGraphics->LoadIBitmap(ICONSINEWAVEON_ID, ICONSINEWAVEON_FN);
	IBitmap iconSineWaveOffOsc2 = pGraphics->LoadIBitmap(ICONSINEWAVEOFF_ID, ICONSINEWAVEOFF_FN);
	IBitmap iconSquareWaveOnOsc2 = pGraphics->LoadIBitmap(ICONSQUAREWAVEON_ID, ICONSQUAREWAVEON_FN);
	IBitmap iconSquareWaveOffOsc2 = pGraphics->LoadIBitmap(ICONSQUAREWAVEOFF_ID, ICONSQUAREWAVEOFF_FN);
	IBitmap iconTriangleWaveOnOsc2 = pGraphics->LoadIBitmap(ICONTRIANGLEWAVEON_ID, ICONTRIANGLEWAVEON_FN);
	IBitmap iconTriangleWaveOffOsc2 = pGraphics->LoadIBitmap(ICONTRIANGLEWAVEOFF_ID, ICONTRIANGLEWAVEOFF_FN);

	IBitmap bgBtnOscWavesOsc1 = pGraphics->LoadIBitmap(BGBTNOSCWAVES_ID, BGBTNOSCWAVES_FN, 2);
	IBitmap bgBtnOscWavesOsc2 = pGraphics->LoadIBitmap(BGBTNOSCWAVES_ID, BGBTNOSCWAVES_FN, 2);



	for (int i = 0; i < kNumParams; i++) {
		const parameterProperties_struct& properties = parameterProperties[i];
		IParam* param = GetParam(i);
		IBitmap* graphic;
		switch (i) {
		//Buttons Waves
		case mBgBtnOscWavesOsc1:
			graphic = &bgBtnOscWavesOsc1;
			control = new IRadioButtonsControl(this, IRECT(43, 206, 43 + (56 * 4), 56 + (60 * 4)), i, 4, graphic, kHorizontal);
			break;
		case mBgBtnOscWavesOsc2:
			graphic = &bgBtnOscWavesOsc2;
			control = new IRadioButtonsControl(this, IRECT(43, 306, 43 + (56 * 4), 126 + (60 * 4)), i, 4, graphic, kHorizontal);
			break;
		//Osc1 Icons Buttons Waves
		case mIconSineWaveOffOsc1:
			graphic = &iconSineWaveOffOsc1;
			control = new IBitmapControl(this, properties.x, properties.y, i, graphic);
			control->Hide(!properties.defaultVal);
			control->GrayOut(TRUE, 0.99f);
			break;
		case mIconSineWaveOnOsc1:
			graphic = &iconSineWaveOnOsc1;
			Osc1ControlSineOn = new IBitmapControl(this, properties.x, properties.y, i, graphic);
			Osc1ControlSineOn->Hide(!properties.defaultVal);
			Osc1ControlSineOn->GrayOut(TRUE, 0.99f);
			pGraphics->AttachControl(Osc1ControlSineOn);
			break;
		case mIconSawWaveOffOsc1:
			graphic = &iconSawWaveOffOsc1;
			control = new IBitmapControl(this, properties.x, properties.y, i, graphic);
			control->SetBlendMethod(IChannelBlend::EBlendMethod::kBlendColorDodge);
			control->Hide(!properties.defaultVal);
			control->GrayOut(TRUE, 0.99f);
			break;
		case mIconSawWaveOnOsc1:
			graphic = &iconSawWaveOnOsc1;
			Osc1ControlSawOn = new IBitmapControl(this, properties.x, properties.y, i, graphic);
			Osc1ControlSawOn->SetBlendMethod(IChannelBlend::EBlendMethod::kBlendColorDodge);
			Osc1ControlSawOn->Hide(!properties.defaultVal);
			Osc1ControlSawOn->GrayOut(TRUE, 0.99f);
			pGraphics->AttachControl(Osc1ControlSawOn);
			break;
		case mIconSqWaveOffOsc1:
			graphic = &iconSquareWaveOffOsc1;
			control = new IBitmapControl(this, properties.x, properties.y, i, graphic);
			control->SetBlendMethod(IChannelBlend::EBlendMethod::kBlendColorDodge);
			control->Hide(!properties.defaultVal);
			control->GrayOut(TRUE, 0.99f);
			break;
		case mIconSqWaveOnOsc1:
			graphic = &iconSquareWaveOnOsc1;
			Osc1ControlSquareOn = new IBitmapControl(this, properties.x, properties.y, i, graphic);
			Osc1ControlSquareOn->SetBlendMethod(IChannelBlend::EBlendMethod::kBlendColorDodge);
			Osc1ControlSquareOn->Hide(!properties.defaultVal);
			Osc1ControlSquareOn->GrayOut(TRUE, 0.99f);
			pGraphics->AttachControl(Osc1ControlSquareOn);
			break;
		case mIconTriangleWaveOffOsc1:
			graphic = &iconTriangleWaveOffOsc1;
			control = new IBitmapControl(this, properties.x, properties.y, i, graphic);
			control->SetBlendMethod(IChannelBlend::EBlendMethod::kBlendColorDodge);
			control->Hide(!properties.defaultVal);
			control->GrayOut(TRUE, 0.99f);
			break;
		case mIconTriangleWaveOnOsc1:
			graphic = &iconTriangleWaveOnOsc1;
			Osc1ControlTriagleOn = new IBitmapControl(this, properties.x, properties.y, i, graphic);
			Osc1ControlTriagleOn->SetBlendMethod(IChannelBlend::EBlendMethod::kBlendColorDodge);
			Osc1ControlTriagleOn->Hide(!properties.defaultVal);
			Osc1ControlTriagleOn->GrayOut(TRUE, 0.99f);
			pGraphics->AttachControl(Osc1ControlTriagleOn);
			break;
		//Osc2 Icons Buttons Waves
		case mIconSineWaveOffOsc2:
			graphic = &iconSineWaveOffOsc2;
			control = new IBitmapControl(this, properties.x, properties.y, i, graphic);
			control->Hide(!properties.defaultVal);
			control->GrayOut(TRUE, 0.99f);
			break;
		case mIconSineWaveOnOsc2:
			graphic = &iconSineWaveOnOsc2;
			Osc2ControlSineOn = new IBitmapControl(this, properties.x, properties.y, i, graphic);
			Osc2ControlSineOn->Hide(!properties.defaultVal);
			Osc2ControlSineOn->GrayOut(TRUE, 0.99f);
			pGraphics->AttachControl(Osc2ControlSineOn);
			break;
		case mIconSawWaveOffOsc2:
			graphic = &iconSawWaveOffOsc2;
			control = new IBitmapControl(this, properties.x, properties.y, i, graphic);
			control->SetBlendMethod(IChannelBlend::EBlendMethod::kBlendColorDodge);
			control->Hide(!properties.defaultVal);
			control->GrayOut(TRUE, 0.99f);
			break;
		case mIconSawWaveOnOsc2:
			graphic = &iconSawWaveOnOsc2;
			Osc2ControlSawOn = new IBitmapControl(this, properties.x, properties.y, i, graphic);
			Osc2ControlSawOn->SetBlendMethod(IChannelBlend::EBlendMethod::kBlendColorDodge);
			Osc2ControlSawOn->Hide(!properties.defaultVal);
			Osc2ControlSawOn->GrayOut(TRUE, 0.99f);
			pGraphics->AttachControl(Osc2ControlSawOn);
			break;
		case mIconSqWaveOffOsc2:
			graphic = &iconSquareWaveOffOsc2;
			control = new IBitmapControl(this, properties.x, properties.y, i, graphic);
			control->SetBlendMethod(IChannelBlend::EBlendMethod::kBlendColorDodge);
			control->Hide(!properties.defaultVal);
			control->GrayOut(TRUE, 0.99f);
			break;
		case mIconSqWaveOnOsc2:
			graphic = &iconSquareWaveOnOsc2;
			Osc2ControlSquareOn = new IBitmapControl(this, properties.x, properties.y, i, graphic);
			Osc2ControlSquareOn->SetBlendMethod(IChannelBlend::EBlendMethod::kBlendColorDodge);
			Osc2ControlSquareOn->Hide(!properties.defaultVal);
			Osc2ControlSquareOn->GrayOut(TRUE, 0.99f);
			pGraphics->AttachControl(Osc2ControlSquareOn);
			break;
		case mIconTriangleWaveOffOsc2:
			graphic = &iconTriangleWaveOffOsc2;
			control = new IBitmapControl(this, properties.x, properties.y, i, graphic);
			control->SetBlendMethod(IChannelBlend::EBlendMethod::kBlendColorDodge);
			control->Hide(!properties.defaultVal);
			control->GrayOut(TRUE, 0.99f);
			break;
		case mIconTriangleWaveOnOsc2:
			graphic = &iconTriangleWaveOnOsc2;
			Osc2ControlTriagleOn = new IBitmapControl(this, properties.x, properties.y, i, graphic);
			Osc2ControlTriagleOn->SetBlendMethod(IChannelBlend::EBlendMethod::kBlendColorDodge);
			Osc2ControlTriagleOn->Hide(!properties.defaultVal);
			Osc2ControlTriagleOn->GrayOut(TRUE, 0.99f);
			pGraphics->AttachControl(Osc2ControlTriagleOn);
			break;
		//LFO
		case mLFOWaveform:
			graphic = &waveformBitmap;
			control = new ISwitchControl(this, properties.x, properties.y, i, graphic);
			break;
		case mFilterMode:
			graphic = &filterModeBitmap;
			control = new ISwitchControl(this, properties.x, properties.y, i, graphic);
			break;
			// Knobs:
		default:
			graphic = &knobBitmap;
			control = new IKnobMultiControl(this, properties.x, properties.y, i, graphic);
			break;
		}
		if (i != mIconSineWaveOnOsc1 && i != mIconSawWaveOnOsc1 && i != mIconSqWaveOnOsc1 && i != mIconTriangleWaveOnOsc1) {
			pGraphics->AttachControl(control);
		}else if (i != mIconSineWaveOnOsc2 && i != mIconSawWaveOnOsc2 && i != mIconSqWaveOnOsc2 && i != mIconTriangleWaveOnOsc2) {
			pGraphics->AttachControl(control);
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
	if (paramIdx == mLFOWaveform) {
		voiceManager.setLFOMode(static_cast<Oscillator::OscillatorMode>(param->Int()));
	}
	else if (paramIdx == mLFOFrequency) {
		voiceManager.setLFOFrequency(param->Value());
	}
	else if (paramIdx == mIconSineWaveOffOsc1) {
		
	}
	else if (paramIdx == mIconSineWaveOnOsc1) {

	}
	else if (paramIdx == mIconSawWaveOffOsc1) {

	}
	else if (paramIdx == mIconSawWaveOnOsc1) {

	}
	else if (paramIdx == mIconSqWaveOffOsc1) {

	}
	else if (paramIdx == mIconSqWaveOnOsc1) {

	}
	else if (paramIdx == mIconTriangleWaveOffOsc1) {

	}
	else if (paramIdx == mIconTriangleWaveOnOsc1) {

	}
	else if (paramIdx == mIconSineWaveOffOsc1) {
		
	}
	else if (paramIdx == mIconSineWaveOnOsc1) {

	}
	else if (paramIdx == mIconSawWaveOffOsc1) {

	}
	else if (paramIdx == mIconSawWaveOnOsc1) {

	}
	else if (paramIdx == mIconSqWaveOffOsc1) {

	}
	else if (paramIdx == mIconSqWaveOnOsc1) {

	}
	else if (paramIdx == mIconTriangleWaveOffOsc1) {

	}
	else if (paramIdx == mIconTriangleWaveOnOsc1) {

	}
	else if (paramIdx == mIconSineWaveOffOsc2) {

	}
	else if (paramIdx == mIconSineWaveOnOsc2) {

	}
	else if (paramIdx == mIconSawWaveOffOsc2) {

	}
	else if (paramIdx == mIconSawWaveOnOsc2) {

	}
	else if (paramIdx == mIconSqWaveOffOsc2) {

	}
	else if (paramIdx == mIconSqWaveOnOsc2) {

	}
	else if (paramIdx == mIconTriangleWaveOffOsc2) {

	}
	else if (paramIdx == mIconTriangleWaveOnOsc2) {

	}
	else {
		using std::placeholders::_1;
		using std::bind;
		VoiceManager::VoiceChangerFunction changer;
		switch (paramIdx) {
			case mBgBtnOscWavesOsc1:
				idxWaveMode = param->Int();
				idxWaveMode--;
				changer = bind(&VoiceManager::setOscillatorMode, _1, 1, static_cast<Oscillator::OscillatorMode>(idxWaveMode));
				if (isParametersInitialized) {
					ToggleIconsWavesButtons(1, idxWaveMode);
				}
				break;
			case mBgBtnOscWavesOsc2:
				idxWaveMode = param->Int();
				idxWaveMode--;
				changer = bind(&VoiceManager::setOscillatorMode, _1, 2, static_cast<Oscillator::OscillatorMode>(idxWaveMode));
				if (isParametersInitialized) {
					ToggleIconsWavesButtons(2, idxWaveMode);
				}
				break;
			case mOsc1PitchMod:
				changer = bind(&VoiceManager::setOscillatorPitchMod, _1, 1, param->Value());
				break;
			case mOsc2PitchMod:
				changer = bind(&VoiceManager::setOscillatorPitchMod, _1, 2, param->Value());
				break;
			case mOscMix:
				changer = bind(&VoiceManager::setOscillatorMix, _1, param->Value());
				break;
				// Filter Section:
			case mFilterMode:
				changer = bind(&VoiceManager::setFilterMode, _1, static_cast<Filter::FilterMode>(param->Int()));
				break;
			case mFilterCutoff:
				changer = bind(&VoiceManager::setFilterCutoff, _1, param->Value());
				break;
			case mFilterResonance:
				changer = bind(&VoiceManager::setFilterResonance, _1, param->Value());
				break;
			case mFilterLfoAmount:
				changer = bind(&VoiceManager::setFilterLFOAmount, _1, param->Value());
				break;
			case mFilterEnvAmount:
				changer = bind(&VoiceManager::setFilterEnvAmount, _1, param->Value());
				break;
				// Volume Envelope:
			case mVolumeEnvAttack:
				changer = bind(&VoiceManager::setVolumeEnvelopeStageValue, _1, EnvelopeGenerator::ENVELOPE_STAGE_ATTACK, param->Value());
				break;
			case mVolumeEnvDecay:
				changer = bind(&VoiceManager::setVolumeEnvelopeStageValue, _1, EnvelopeGenerator::ENVELOPE_STAGE_DECAY, param->Value());
				break;
			case mVolumeEnvSustain:
				changer = bind(&VoiceManager::setVolumeEnvelopeStageValue, _1, EnvelopeGenerator::ENVELOPE_STAGE_SUSTAIN, param->Value());
				break;
			case mVolumeEnvRelease:
				changer = bind(&VoiceManager::setVolumeEnvelopeStageValue, _1, EnvelopeGenerator::ENVELOPE_STAGE_RELEASE, param->Value());
				break;
				// Filter Envelope:
			case mFilterEnvAttack:
				changer = bind(&VoiceManager::setFilterEnvelopeStageValue, _1, EnvelopeGenerator::ENVELOPE_STAGE_ATTACK, param->Value());
				break;
			case mFilterEnvDecay:
				changer = bind(&VoiceManager::setFilterEnvelopeStageValue, _1, EnvelopeGenerator::ENVELOPE_STAGE_DECAY, param->Value());
				break;
			case mFilterEnvSustain:
				changer = bind(&VoiceManager::setFilterEnvelopeStageValue, _1, EnvelopeGenerator::ENVELOPE_STAGE_SUSTAIN, param->Value());
				break;
			case mFilterEnvRelease:
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
			Osc1ControlSineOn->Hide(FALSE);
			Osc1ControlSawOn->Hide(TRUE);
			Osc1ControlSquareOn->Hide(TRUE);
			Osc1ControlTriagleOn->Hide(TRUE);
			break;
		case 1:
			Osc1ControlSineOn->Hide(TRUE);
			Osc1ControlSawOn->Hide(FALSE);
			Osc1ControlSquareOn->Hide(TRUE);
			Osc1ControlTriagleOn->Hide(TRUE);
			break;
		case 2:
			Osc1ControlSineOn->Hide(TRUE);
			Osc1ControlSawOn->Hide(TRUE);
			Osc1ControlSquareOn->Hide(FALSE);
			Osc1ControlTriagleOn->Hide(TRUE);
			break;
		case 3:
			Osc1ControlSineOn->Hide(TRUE);
			Osc1ControlSawOn->Hide(TRUE);
			Osc1ControlSquareOn->Hide(TRUE);
			Osc1ControlTriagleOn->Hide(FALSE);
			break;
		}

	}
	else if (nOsc == 2) {
		switch (idxWaveMode) {
		case 0:
			Osc2ControlSineOn->Hide(FALSE);
			Osc2ControlSawOn->Hide(TRUE);
			Osc2ControlSquareOn->Hide(TRUE);
			Osc2ControlTriagleOn->Hide(TRUE);
			break;
		case 1:
			Osc2ControlSineOn->Hide(TRUE);
			Osc2ControlSawOn->Hide(FALSE);
			Osc2ControlSquareOn->Hide(TRUE);
			Osc2ControlTriagleOn->Hide(TRUE);
			break;
		case 2:
			Osc2ControlSineOn->Hide(TRUE);
			Osc2ControlSawOn->Hide(TRUE);
			Osc2ControlSquareOn->Hide(FALSE);
			Osc2ControlTriagleOn->Hide(TRUE);
			break;
		case 3:
			Osc2ControlSineOn->Hide(TRUE);
			Osc2ControlSawOn->Hide(TRUE);
			Osc2ControlSquareOn->Hide(TRUE);
			Osc2ControlTriagleOn->Hide(FALSE);
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