#pragma once
#include "Modules.h"

class ModEQuilibrium : public Modules
{
public:
	const Modules::EModulesType moduleType = EQUILIBRIUM;

	void setLowFreq(double newLowFreq);
	void setLowBoost(double newLowBoost);
	void setHighFreq(double newHighFreq);
	void setHighShelf(double newHighShelf);

	double getLowFreq();
	double getLowBoost();
	double getHighFreq();
	double getHighShelf();
	
private:
	double lowFreq, lowBoost, highFreq, highShelf;
};


