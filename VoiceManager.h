//#include <tr1/functional> if that doesn't work

#ifndef __OhmBass__VoiceManager__
#define __OhmBass__VoiceManager__

#include "Voice.h"
#include <functional> 


class VoiceManager {
public:
	double EQuilibriumLowFreq, EQuilibriumLowGain, EQuilibriumHighFreq, EQuilibriumHighShelf;
	void onNoteOn(int noteNumber, int velocity);
	void onNoteOff(int noteNumber, int velocity);
	double nextSample(bool osc1status, bool osc2status);

	void setSampleRate(double sampleRate) {
		EnvelopeGenerator::setSampleRate(sampleRate);
		for (int i = 0; i < NumberOfVoices; i++) {
			Voice& voice = voices[i];
			voice.mOscillatorOne.setSampleRate(sampleRate);
			voice.mOscillatorTwo.setSampleRate(sampleRate);
		}
		mLFO1.setSampleRate(sampleRate);
		mLFO2.setSampleRate(sampleRate);
		mLFO3.setSampleRate(sampleRate);
	}

	inline void setLFOMode(int oscNumber, Oscillator::OscillatorMode mode) {
		if (oscNumber == 1) {
			mLFO1.setMode(mode);
		}
		else if (oscNumber == 2) {
			mLFO2.setMode(mode);
		}
		else if (oscNumber == 3) {
			mLFO3.setMode(mode);
		}
		
	};
	inline void setLFOFrequency(int oscNumber, double frequency) { 
		if (oscNumber == 1) {
			mLFO1.setFrequency(frequency);
		}
		else if (oscNumber == 2) {
			mLFO2.setFrequency(frequency);
		}
		else if (oscNumber == 3) {
			mLFO3.setFrequency(frequency);
		}
		
	};

	typedef std::function<void(Voice&)> VoiceChangerFunction;

	inline void changeAllVoices(VoiceChangerFunction changer) {
		for (int i = 0; i < NumberOfVoices; i++) {
			changer(voices[i]);
		}
	}
	// Functions to change a single voice:
	static void setVolumeEnvelopeStageValue(Voice& voice, EnvelopeGenerator::EnvelopeStage stage, double value) {
		voice.mVolumeEnvelope.setStageValue(stage, value);
	}
	void setEQuilibriumLowFreq(double amount) { 
		this->EQuilibriumLowFreq = amount;
	}
	void setEQuilibriumLowGain(double amount) {
		this->EQuilibriumLowGain = amount;
	}
	void setHighFreq(double amount) {
		this->EQuilibriumHighFreq = amount;
	}
	void setHighShelf(double amount) {
		this->EQuilibriumHighShelf = amount;
	}
	static void setFilterEnvelopeStageValue(Voice& voice, EnvelopeGenerator::EnvelopeStage stage, double value) {
		voice.mFilterEnvelope.setStageValue(stage, value);
	}
	static void setOscillatorMode(Voice& voice, int oscillatorNumber, Oscillator::OscillatorMode mode) {
		switch (oscillatorNumber) {
		case 1:
			voice.mOscillatorOne.setMode(mode);
			break;
		case 2:
			voice.mOscillatorTwo.setMode(mode);
			break;
		}
	}
	static void setOscillatorPitchMod(Voice& voice, int oscillatorNumber, double amount) {
		switch (oscillatorNumber) {
		case 1:
			voice.setOscillatorOnePitchAmount(amount);
			break;
		case 2:
			voice.setOscillatorTwoPitchAmount(amount);
			break;
		}
	}
	static void setOscillatorOneOutput(Voice& voice, double value) {
		voice.setOscillatorOneOutput(value);
	}
	static void setOscillatorTwoOutput(Voice& voice, double value) {
		voice.setOscillatorTwoOutput(value);
	}
	static void setFilterCutoff(Voice& voice, double cutoff) {
		voice.mFilter.setCutoff(cutoff);
	}
	static void setSlopeMode(Voice& voice, int slope) {
		voice.mFilter.setSlopeMode(slope);
	}
	static void setFilterResonance(Voice& voice, double resonance) {
		voice.mFilter.setResonance(resonance);
	}
	static void setFilterMode(Voice& voice, Filter::FilterMode mode) {
		voice.mFilter.setFilterMode(mode);
	}
	static void setFilterEnvAmount(Voice& voice, double amount) {
		voice.setFilterEnvelopeAmount(amount);
	}
	static void setFilterLFOAmount(Voice& voice, double amount) {
		voice.setFilterLFOAmount(amount);
	}
private:
	static const int NumberOfVoices = 64;
	Voice voices[NumberOfVoices];
	Oscillator mLFO1, mLFO2, mLFO3;
	Voice* findFreeVoice();
};

#endif /* defined(__OhmBass__VoiceManager__) */