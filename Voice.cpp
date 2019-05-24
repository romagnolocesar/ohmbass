#include "Voice.h"



double Voice::nextSample(Biquad* filterGainLow, Biquad* filterShelfHigh) {
	if (!isActive) return 0.0;

	double oscillatorOneOutput = mOscillatorOne.nextSample();
	double oscillatorTwoOutput = mOscillatorTwo.nextSample();

	double oscillatorSum = (oscillatorOneOutput*mOscilatorOneOutput) + (oscillatorTwoOutput*mOscilatorTwoOutput);

	double volumeEnvelopeValue = mVolumeEnvelope.nextSample();
	double filterEnvelopeValue = mFilterEnvelope.nextSample();

	mFilter.setCutoffMod(filterEnvelopeValue * mFilterEnvelopeAmount + mLFOValue * mFilterLFOAmount);

	mOscillatorOne.setPitchMod(mLFOValue * mOscillatorOnePitchAmount);
	mOscillatorTwo.setPitchMod(mLFOValue * mOscillatorTwoPitchAmount);


	//PARALEL FILTER
	return mFilter.process(
		filterShelfHigh->process(
			filterGainLow->process(
				oscillatorSum * volumeEnvelopeValue * mVelocity / 127.0
			)
		)
	);
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
