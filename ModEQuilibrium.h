#pragma once
#include "ModulesModel.h"

class ModEQuilibrium : public ModulesModel
{
public:
	EModulesName moduleName = EQUILIBRIUM;


	void setLowFreq(double newLowFreq);
	void setLowBoost(double newLowBoost);
	void setHighFreq(double newHighFreq);
	void setHighShelf(double newHighShelf);

	/*void init(controlsManager* IControlsManager);*/

	double getLowFreq();
	double getLowBoost();
	double getHighFreq();
	double getHighShelf();
 
	
private:
	double lowFreq, lowBoost, highFreq, highShelf;
};


