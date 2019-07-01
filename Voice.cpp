#include "Voice.h"



double Voice::nextSample(bool osc1status, bool osc2status) {
	if (!isActive) return 0.0;

	double oscillatorOneOutput = 0.0;
	double oscillatorTwoOutput = 0.0;

	if(osc1status) {
		oscillatorOneOutput = mOscillatorOne.nextSample();
	}

	if (osc2status) {
		oscillatorTwoOutput = mOscillatorTwo.nextSample();
	}

	double oscillatorSum = (oscillatorOneOutput*mOscilatorOneOutput) + (oscillatorTwoOutput*mOscilatorTwoOutput);

	double volumeEnvelopeValue = mVolumeEnvelope.nextSample();
	double filterEnvelopeValue = mFilterEnvelope.nextSample();

	mFilter.setCutoffMod(filterEnvelopeValue * mFilterEnvelopeAmount + mLFO3Value * mFilterLFOAmount);

	mOscillatorOne.setPitchMod(mLFO1Value * mOscillatorOnePitchAmount);
	mOscillatorTwo.setPitchMod(mLFO2Value * mOscillatorTwoPitchAmount);



	double result = 0.0;
	result = oscillatorSum * volumeEnvelopeValue * mVelocity / 127.0;

	//*********** FILTERS AND EQUALIZERS ******************
	
	//Filter 
	result = mFilter.process(result);

	
	
	

	return result;
}

void Voice::setFree() {
	isActive = false;
}

void Voice::reset() {
	mNoteNumber = -1;
	mVelocity = 0;
	mOscillatorOne.reset();
	mOscillatorTwo.reset();
	mVolumeEnvelope.reset();
	mFilterEnvelope.reset();
	mFilter.reset();
}
