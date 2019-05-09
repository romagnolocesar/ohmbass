#include "Voice.h"



double Voice::nextSample() {
	if (!isActive) return 0.0;

	double oscillatorOneOutput = mOscillatorOne.nextSample();
	double oscillatorTwoOutput = mOscillatorTwo.nextSample();

	double oscillatorSum = (oscillatorOneOutput*mOscilatorOneOutput) + (oscillatorTwoOutput*mOscilatorTwoOutput);

	double volumeEnvelopeValue = mVolumeEnvelope.nextSample();
	double filterEnvelopeValue = mFilterEnvelope.nextSample();

	double CutoffEquilibriumLow = mEQuilibriumLowFreq;


	mFilter.setCutoffMod(filterEnvelopeValue * mFilterEnvelopeAmount + mLFOValue * mFilterLFOAmount);
	mFilter.setCutoffEquilibriumLow(CutoffEquilibriumLow);

	mOscillatorOne.setPitchMod(mLFOValue * mOscillatorOnePitchAmount);
	mOscillatorTwo.setPitchMod(mLFOValue * mOscillatorTwoPitchAmount);


	return mFilter.process((oscillatorSum * volumeEnvelopeValue * mVelocity / 127.0), mEQuilibriumLowGain);
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
