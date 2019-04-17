#include "OhmBass.h"
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmain"
#include "IPlug_include_in_plug_src.h"
#pragma clang diagnostic pop
#include "IControl.h"
#include "IKeyboardControl.h"
#include "resource.h"

#include <math.h>
#include <algorithm>

IGraphics* pGraphics;
IControl* control;
IControl* controlSineOn;
const int kNumPrograms = 5;
const double parameterStep = 0.001;
bool isParametersInitialized = FALSE;



enum EParams
{
	// Oscillator Section:
	mBgBtnOscWaves = 0,
	mIconSineWaveOff,
	mIconSineWaveOn,
	mIconSawWaveOff,
	mIconSawWaveOn,
	mIconSqWaveOff,
	mIconSqWaveOn,
	mIconTriangleWaveOff,
	mIconTriangleWaveOn,
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
  {"Icon Sine Wave Off", 58, 218, TRUE},
  {"Icon Sine Wave On", 58, 218, TRUE},
  {"Icon Saw Wave Off", 114, 218, TRUE},
  {"Icon Saw Wave On", 114, 218, FALSE},
  {"Icon Square Wave Off", 170, 218, TRUE},
  {"Icon Square Wave On", 170, 218, FALSE},
  {"Icon Triangle Wave Off", 226, 218, TRUE},
  {"Icon Triangle Wave On", 226, 218, FALSE},
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
		case mBgBtnOscWaves:
			param->InitInt(properties.name, 1, 1, 4, "osc1waves");
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

	//waves buttons
		//icons
	IBitmap iconSawWaveOn = pGraphics->LoadIBitmap(ICONSAWWAVEON_ID, ICONSAWWAVEON_FN);
	IBitmap iconSawWaveOff = pGraphics->LoadIBitmap(ICONSAWWAVEOFF_ID, ICONSAWWAVEOFF_FN);
	IBitmap iconSineWaveOn = pGraphics->LoadIBitmap(ICONSINEWAVEON_ID, ICONSINEWAVEON_FN);
	IBitmap iconSineWaveOff = pGraphics->LoadIBitmap(ICONSINEWAVEOFF_ID, ICONSINEWAVEOFF_FN);
	IBitmap iconSquareWaveOn = pGraphics->LoadIBitmap(ICONSQUAREWAVEON_ID, ICONSQUAREWAVEON_FN);
	IBitmap iconSquareWaveOff = pGraphics->LoadIBitmap(ICONSQUAREWAVEOFF_ID, ICONSQUAREWAVEOFF_FN);
	IBitmap iconTriangleWaveOn = pGraphics->LoadIBitmap(ICONTRIANGLEWAVEON_ID, ICONTRIANGLEWAVEON_FN);
	IBitmap iconTriangleWaveOff = pGraphics->LoadIBitmap(ICONTRIANGLEWAVEOFF_ID, ICONTRIANGLEWAVEOFF_FN);

	IBitmap bgBtnOscWaves = pGraphics->LoadIBitmap(BGBTNOSCWAVES_ID, BGBTNOSCWAVES_FN, 2);



	for (int i = 0; i < kNumParams; i++) {
		const parameterProperties_struct& properties = parameterProperties[i];
		IParam* param = GetParam(i);
		IBitmap* graphic;
		switch (i) {
		//Osc1 Buttons Waves
		case mBgBtnOscWaves:
			graphic = &bgBtnOscWaves;
			control = new IRadioButtonsControl(this, IRECT(43, 206, 43 + (56 * 4), 56 + (60 * 4)), i, 4, graphic, kHorizontal);
			break;
		//Osc1 Icons Buttons Waves
		case mIconSineWaveOff:
			graphic = &iconSineWaveOff;
			control = new IBitmapControl(this, properties.x, properties.y, i, graphic);
			control->Hide(!properties.defaultVal);
			control->GrayOut(TRUE, 0.99f);
			break;
		case mIconSineWaveOn:
			graphic = &iconSineWaveOn;
			controlSineOn = new IBitmapControl(this, properties.x, properties.y, i, graphic);
			controlSineOn->Hide(!properties.defaultVal);
			controlSineOn->GrayOut(TRUE, 0.99f);
			pGraphics->AttachControl(controlSineOn);
			break;
		case mIconSawWaveOff:
			graphic = &iconSawWaveOff;
			control = new IBitmapControl(this, properties.x, properties.y, i, graphic);
			control->SetBlendMethod(IChannelBlend::EBlendMethod::kBlendColorDodge);
			control->Hide(!properties.defaultVal);
			control->GrayOut(TRUE, 0.99f);
			break;
		case mIconSawWaveOn:
			graphic = &iconSawWaveOn;
			control = new IBitmapControl(this, properties.x, properties.y, i, graphic);
			control->SetBlendMethod(IChannelBlend::EBlendMethod::kBlendColorDodge);
			control->Hide(!properties.defaultVal);
			control->GrayOut(TRUE, 0.99f);
			break;
		case mIconSqWaveOff:
			graphic = &iconSquareWaveOff;
			control = new IBitmapControl(this, properties.x, properties.y, i, graphic);
			control->SetBlendMethod(IChannelBlend::EBlendMethod::kBlendColorDodge);
			control->Hide(!properties.defaultVal);
			control->GrayOut(TRUE, 0.99f);
			break;
		case mIconSqWaveOn:
			graphic = &iconSquareWaveOn;
			control = new IBitmapControl(this, properties.x, properties.y, i, graphic);
			control->SetBlendMethod(IChannelBlend::EBlendMethod::kBlendColorDodge);
			control->Hide(!properties.defaultVal);
			control->GrayOut(TRUE, 0.99f);
			break;
		case mIconTriangleWaveOff:
			graphic = &iconTriangleWaveOff;
			control = new IBitmapControl(this, properties.x, properties.y, i, graphic);
			control->SetBlendMethod(IChannelBlend::EBlendMethod::kBlendColorDodge);
			control->Hide(!properties.defaultVal);
			control->GrayOut(TRUE, 0.99f);
			break;
		case mIconTriangleWaveOn:
			graphic = &iconTriangleWaveOn;
			control = new IBitmapControl(this, properties.x, properties.y, i, graphic);
			control->SetBlendMethod(IChannelBlend::EBlendMethod::kBlendColorDodge);
			control->Hide(!properties.defaultVal);
			control->GrayOut(TRUE, 0.99f);
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
		if (i != mIconSineWaveOn) {
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
	IControl* control2;
	int idxWaveMode = 0;
	if (paramIdx == mLFOWaveform) {
		voiceManager.setLFOMode(static_cast<Oscillator::OscillatorMode>(param->Int()));
	}
	else if (paramIdx == mLFOFrequency) {
		voiceManager.setLFOFrequency(param->Value());
	}
	else if (paramIdx == mIconSineWaveOff) {
		
	}
	else if (paramIdx == mIconSineWaveOn) {

	}
	else if (paramIdx == mIconSawWaveOff) {

	}
	else if (paramIdx == mIconSawWaveOn) {

	}
	else if (paramIdx == mIconSqWaveOff) {

	}
	else if (paramIdx == mIconSqWaveOn) {

	}
	else if (paramIdx == mIconTriangleWaveOff) {

	}
	else if (paramIdx == mIconTriangleWaveOn) {

	}
	else {
		using std::placeholders::_1;
		using std::bind;
		VoiceManager::VoiceChangerFunction changer;
		switch (paramIdx) {
			case mBgBtnOscWaves: 
				idxWaveMode = param->Int();
				idxWaveMode--;
				changer = bind(&VoiceManager::setOscillatorMode, _1, 1, static_cast<Oscillator::OscillatorMode>(idxWaveMode));
				if (isParametersInitialized) {
					controlSineOn->Hide(TRUE);
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
		voiceManager.changeAllVoices(changer);
	}
}

void OhmBass::ProcessMidiMsg(IMidiMsg* pMsg) {
	mMIDIReceiver.onMessageReceived(pMsg);
	mVirtualKeyboard->SetDirty();
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