#include "Oscillator.h"

class PolyBLEPOscillator : public Oscillator {
public:
	PolyBLEPOscillator() : lastOutput(0.0) { updateIncrement(); };
	double nextSample();
private:
	double poly_blep(double t);
	double lastOutput;
};