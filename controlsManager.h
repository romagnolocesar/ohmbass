#pragma once
#include "OhmBass.h"
#include "IControl.h"
#include "modelControl.h"
#include "Modules.h"
#include <vector> using namespace std; 



class controlsManager{
public:

	const double parameterStep = 0.001;
	std::vector<class modelControl * > collection;

	void addParam(Modules::EModulesName moduleName, char* alias, int x, int y, double defaultVal, double minVal, double maxVal) {
		int idx = this->Count();
		modelControl* myControl = new modelControl(moduleName, idx, alias, x, y, defaultVal, minVal, maxVal);
		this->AddCollection(myControl);
	};


	int AddCollection(modelControl* myInstance)
	{
		collection.push_back(myInstance);
		return (collection.size() - 1);
	}

	int Count(void)
	{
		return collection.size();
	}

	int kNumParams;

	//enum EParams
	//{
	//	// Oscillator Section:
	//	mBgBtnOscWavesOsc1 = 0,
	//	mBgBtnOscWavesOsc2,
	//	mIconSineWaveOffOsc1,
	//	mIconSineWaveOnOsc1,
	//	mIconSawWaveOffOsc1,
	//	mIconSawWaveOnOsc1,
	//	mIconSqWaveOffOsc1,
	//	mIconSqWaveOnOsc1,
	//	mIconTriangleWaveOffOsc1,
	//	mIconTriangleWaveOnOsc1,
	//	mIconSineWaveOffOsc2,
	//	mIconSineWaveOnOsc2,
	//	mIconSawWaveOffOsc2,
	//	mIconSawWaveOnOsc2,
	//	mIconSqWaveOffOsc2,
	//	mIconSqWaveOnOsc2,
	//	mIconTriangleWaveOffOsc2,
	//	mIconTriangleWaveOnOsc2,
	//	mOsc1PitchMod,
	//	mOsc2PitchMod,
	//	//Faders
	//	mFadersGlowOsc1,
	//	mFadersGlowOsc2,
	//	mFadersHandlerOffOsc1,
	//	mFadersHandlerOffOsc2,
	//	mFadersHandlerOnOsc1,
	//	mFadersHandlerOnOsc2,
	//	// Filter Section:
	//	mFilterMode,
	//	mFilterCutoff,
	//	mFilterResonance,
	//	mFilterLfoAmount,
	//	mFilterEnvAmount,
	//	// LFO:
	//	mLFOWaveform,
	//	mLFOFrequency,
	//	// Volume Envelope:
	//	mVolumeEnvAttack,
	//	mVolumeEnvDecay,
	//	mVolumeEnvSustain,
	//	mVolumeEnvRelease,
	//	// Filter Envelope:
	//	mFilterEnvAttack,
	//	mFilterEnvDecay,
	//	mFilterEnvSustain,
	//	mFilterEnvRelease,
	//	//GHRR PLACE
	//	//Eq-Librium
	//	mGhrtab1,
	//	mGhrEqlOnTitle,
	//	mGhrEqlLowFreq,
	//	mGhrBostLowFreq,
	//	mGhrEqlHihgFreq,
	//	mGhrShelfHihgFreq,
	//	kNumParams
	//};

	/*typedef struct {
		const char* name;
		const int x;
		const int y;
		const double defaultVal;
		const double minVal;
		const double maxVal;
	} parameterProperties_struct;*/

	IControl* control;
	IControl* Osc1ControlSineOn;
	IControl* Osc1ControlSawOn;
	IControl* Osc1ControlSquareOn;
	IControl* Osc1ControlTriagleOn;
	IControl* Osc2ControlSineOn;
	IControl* Osc2ControlSawOn;
	IControl* Osc2ControlSquareOn;
	IControl* Osc2ControlTriagleOn;

	IControl* Osc1FaderHandlerOff;
	IControl* Osc2FaderHandlerOff;
	IControl* Osc1FaderHandlerOn;
	IControl* Osc2FaderHandlerOn;
	IControl* Osc1FaderGlow;
	IControl* Osc2FaderGlow;
	



	/*parameterProperties_struct getParameterProperties(int idx) {
		return parameterProperties[idx];
	};*/

	void createParams(IPlug* myOhmBass);
	int getKNumParams();
	void ToggleIconsWavesButtons(int nOsc, int idxWaveMode);

private:
	//parameterProperties_struct parameterProperties[kNumParams] =
	//{
	//	//OSCILLATORS	
	//	{"Bg Btn Osc 1 Waves", 99, 206, 0.0, 0.0, 1.0},
	//	{"Bg Btn Osc 2 Waves", 99, 306, 0.0, 0.0, 1.0},
	//	{"Icon Sine Wave Off OSC1", 58, 218, TRUE},
	//	{"Icon Sine Wave On OSC1", 58, 218, TRUE},
	//	{"Icon Saw Wave Off OSC1", 114, 218, TRUE},
	//	{"Icon Saw Wave On OSC1", 114, 218, FALSE},
	//	{"Icon Square Wave Off OSC1", 170, 218, TRUE},
	//	{"Icon Square Wave On OSC1", 170, 218, FALSE},
	//	{"Icon Triangle Wave Off OSC1", 226, 218, TRUE},
	//	{"Icon Triangle Wave On OSC1", 226, 218, FALSE},
	//	{"Icon Sine Wave Off OSC2", 58, 318, TRUE},
	//	{"Icon Sine Wave On OSC2", 58, 318, TRUE},
	//	{"Icon Saw Wave Off OSC2", 114, 318, TRUE},
	//	{"Icon Saw Wave On OSC2", 114, 318, FALSE},
	//	{"Icon Square Wave Off OSC2", 170, 318, TRUE},
	//	{"Icon Square Wave On OSC2", 170, 318, FALSE},
	//	{"Icon Triangle Wave Off OSC2", 226, 318, TRUE},
	//	{"Icon Triangle Wave On OSC2", 226, 318, FALSE},
	//	{"Osc 1 Pitch Mod", 308, 195, 0.0, 0.0, 1.0},
	//	{"Osc 2 Pitch Mod", 308, 295, 0.0, 0.0, 1.0},
	//	//GAIN FADERS
	//	{"Fader Glow Osc1", 452, 219, 0.0, 0.0, 1.0},
	//	{"Fader Glow Osc2", 533, 219, 0.0, 0.0, 1.0},
	//	{"Fader Handler Off Osc1", 429, 210, 0.8, 0.0, 1.0},
	//	{"Fader Handler Off Osc2", 510, 210, 0.0, 0.0, 1.0},
	//	{"Fader Handler On Osc1", 429, 210, 0.8, 0.0, 1.0},
	//	{"Fader Handler On Osc2", 510, 210, 0.0, 0.0, 1.0},
	//	//FILTERS AND FILTER ENVELOPES
	//	{"Filter Mode", 875, 300},
	//	{"Filter Cutoff", 635, 343, 0.99, 0.0, 0.99},
	//	{"Filter Resonance", 730, 343, 0.0, 0.0, 1.0},
	//	{"Filter LFO Amount", 840, 343, 0.0, 0.0, 1.0},
	//	{"Filter Envelope Amount", 915, 343, 0.0, -1.0, 1.0},
	//	{"LFO Waveform", 30, 520},
	//	{"LFO Frequency", 75, 510, 6.0, 0.01, 30.0},
	//	//AMPLIFICATOR ENVELOPE
	//	{"Volume Env Attack", 35, 15, 0.01, 0.01, 10.0},
	//	{"Volume Env Decay", 130, 15, 0.5, 0.01, 15.0},
	//	{"Volume Env Sustain", 225, 15, 0.1, 0.001, 1.0},
	//	{"Volume Env Release", 320, 15, 1.0, 0.01, 15.0},
	//	{"Filter Env Attack", 635, 193, 0.01, 0.01, 10.0},
	//	{"Filter Env Decay", 730, 193, 0.5, 0.01, 15.0},
	//	{"Filter Env Sustain", 820, 193, 0.1, 0.001, 1.0},
	//	{"Filter Env Release", 915, 193, 1.0, 0.01, 15.0},
	//	
	//	//GHRR PLACE
	//	{"Tab1 Ghrr", 548, 522, 0.0, 0.0, 1.0},
	//	{"Knb Eql title on", 552, 530, 0.0, 0.0, 1.0},
	//	{"Knb Eql Low freq", 560, 640, 0.3, 0.0, 1.0},
	//	{"Knb Bost Low freq", 639, 640, 0.5, 0.0, 1.0},
	//	{"Knb Eql High freq", 718, 640, 0.5, 0.0, 1.0},
	//	{"Knb Shelf Hihg freq", 797, 640, 0.1, 0.0, 1.0}
	//};

};

