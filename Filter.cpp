#include "Filter.h"



double Filter::process(double inputValue, double mEQuilibriumLowGain) {
	if (inputValue == 0.0) return inputValue;
	double calculatedCutoff = getCalculatedCutoff();
	double calculatedCutoffEquilibriumLow = getCalculatedCutoffEquilibriumLow();

	buf0 += calculatedCutoff * (inputValue - buf0 + feedbackAmount * (buf0 - buf1));
	buf1 += calculatedCutoff * (buf0 - buf1);
	buf2 += calculatedCutoff * (buf1 - buf2);
	buf3 += calculatedCutoff * (buf2 - buf3);

	EQlibriumbuf0 += (calculatedCutoffEquilibriumLow * (inputValue - EQlibriumbuf0 + feedbackAmount * (EQlibriumbuf0 - EQlibriumbuf1))) * mEQuilibriumLowGain;
	EQlibriumbuf1 += calculatedCutoffEquilibriumLow * (EQlibriumbuf0 - EQlibriumbuf1);
	EQlibriumbuf2 += calculatedCutoffEquilibriumLow * (EQlibriumbuf1 - EQlibriumbuf2);
	EQlibriumbuf3 += calculatedCutoffEquilibriumLow * (EQlibriumbuf2 - EQlibriumbuf3);
	switch (mode){
	case FILTER_MODE_LOWPASS:
		return (EQlibriumbuf0 - EQlibriumbuf3);
		//return (buf3) + (EQlibriumbuf0 - EQlibriumbuf3);
	case FILTER_MODE_HIGHPASS:
		return (EQlibriumbuf0 - EQlibriumbuf3);
		//return inputValue - (EQlibriumbuf0 - EQlibriumbuf3);
	case FILTER_MODE_BANDPASS:
		return (EQlibriumbuf0 - EQlibriumbuf3);
		//return buf0 - buf3 + (EQlibriumbuf0 - EQlibriumbuf3);
	default:
		return 0.0;
	}
}