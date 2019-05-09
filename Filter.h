#include <cmath>

class Filter {
public:
	enum FilterMode {
		FILTER_MODE_LOWPASS = 0,
		FILTER_MODE_HIGHPASS,
		FILTER_MODE_BANDPASS,
		kNumFilterModes
	};
	Filter() :
		cutoff(0.99),
		resonance(0.0),
		cutoffMod(0.0),
		mode(FILTER_MODE_LOWPASS),
		cuttofEQuilibriumLowFreq(0.0),
		buf0(0.0),
		buf1(0.0),
		buf2(0.0),
		buf3(0.0),
		EQlibriumbuf0(0.0),
		EQlibriumbuf1(0.0),
		EQlibriumbuf2(0.0),
		EQlibriumbuf3(0.0)
	{
		calculateFeedbackAmount();
	};
	void reset() {
		buf0 = buf1 = buf2 = buf3 = 0.0;
		EQlibriumbuf0 = EQlibriumbuf1 = EQlibriumbuf2 = EQlibriumbuf3 = 0.0;
	}
	double process(double inputValue, double mEQuilibriumLowGain);
	inline void setCutoff(double newCutoff) { cutoff = newCutoff; calculateFeedbackAmount(); };
	inline void setCutoffEquilibriumLow(double newCutoff) { cuttofEQuilibriumLowFreq = newCutoff;};
	inline void setResonance(double newResonance) { resonance = newResonance; calculateFeedbackAmount(); };
	inline void setFilterMode(FilterMode newMode) { mode = newMode; }
	inline void setCutoffMod(double newCutoffMod) {
		cutoffMod = newCutoffMod;
		calculateFeedbackAmount();
	}
private:
	double cutoff;
	double resonance;
	FilterMode mode;
	double feedbackAmount;
	inline void calculateFeedbackAmount() {
		feedbackAmount = resonance + resonance / (1.0 - getCalculatedCutoff());
	}
	double buf0;
	double buf1;
	double buf2;
	double buf3;
	double EQlibriumbuf0;
	double EQlibriumbuf1;
	double EQlibriumbuf2;
	double EQlibriumbuf3;
	double cutoffMod;
	double cuttofEQuilibriumLowFreq;
	inline double getCalculatedCutoffEquilibriumLow() const {
		return (fmax(fmin(cuttofEQuilibriumLowFreq, 0.99), 0.01))/10;
	}
	inline double getCalculatedCutoff() const {
		return fmax(fmin(cutoff + cutoffMod, 0.99), 0.01);
	};

};