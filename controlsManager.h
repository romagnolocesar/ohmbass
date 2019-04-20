#pragma once
#include "IControl.h"

class controlsManager
{
public:
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

	IControl* control;
	IControl* Osc1ControlSineOn;
	IControl* Osc1ControlSawOn;
	IControl* Osc1ControlSquareOn;
	IControl* Osc1ControlTriagleOn;
	IControl* Osc2ControlSineOn;
	IControl* Osc2ControlSawOn;
	IControl* Osc2ControlSquareOn;
	IControl* Osc2ControlTriagleOn;

	controlsManager();
	~controlsManager();
	

	
};

