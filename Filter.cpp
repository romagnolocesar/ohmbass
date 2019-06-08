#include "Filter.h"



double Filter::process(double inputValue) {
	if (inputValue == 0.0) return inputValue;

	double calculatedCutoff = getCalculatedCutoff();


	switch (slope_mode)
	{
	case FILTER_SLOPE_24:
		buf0 += calculatedCutoff * (inputValue - buf0 + feedbackAmount * (buf0 - buf1));
		buf1 += calculatedCutoff * (buf0 - buf1);
		buf2 += calculatedCutoff * (buf1 - buf2);
		buf3 += calculatedCutoff * (buf2 - buf3);

		switch (mode) {
		case FILTER_MODE_LOWPASS:
			return buf3;
		case FILTER_MODE_HIGHPASS:
			return inputValue - buf3;
		case FILTER_MODE_BANDPASS:
			return buf0 - buf3;
		default:
			return 0.0;
		}
		break;
	case FILTER_SLOPE_12:
		buf0 += cutoff * (inputValue - buf0);
		buf1 += cutoff * (buf0 - buf1);

		switch (mode) {
			case FILTER_MODE_LOWPASS:
				return buf1;
			case FILTER_MODE_HIGHPASS:
				return inputValue - buf0;
			case FILTER_MODE_BANDPASS:
				return buf0 - buf1;
			default:
				return 0.0;
			}
		break;
	}
	

	//caso 12db
	/*switch (mode){
	case FILTER_MODE_LOWPASS:
		return buf3;
	case FILTER_MODE_HIGHPASS:
		return inputValue - buf3;
	case FILTER_MODE_BANDPASS:
		return buf0 - buf3;
	default:
		return 0.0;
	}*/

	
}