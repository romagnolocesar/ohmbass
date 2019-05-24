#pragma once
#include "controlsManager.h"
#include "graphicsManager.h"
#include "Biquad.h"

class ModEQuilibrium : public ModulesModel
{
public:
	EModulesName moduleName = EQUILIBRIUM;

	IBitmap pBitmap;
	GraphicsModel::EGraphicsType graphicType;
	GraphicsModel* iGraphic;


	void setLowFreq(double newLowFreq);
	void setLowBoost(double newLowBoost);
	void setHighFreq(double newHighFreq);
	void setHighShelf(double newHighShelf);

	double getLowFreq();
	double getLowBoost();
	double getHighFreq();
	double getHighShelf();

	void init(controlsManager* IControlsManager, graphicsManager* IGraphicsManager);
	void doModelsControlsInIControlsCollection(IPlug* myOhmBass, controlsManager* iControlsManager, graphicsManager* iGraphicsManager, int i);

	void updateLowFilterValues();
	void updateHighFilterValues();

	void process();

	//EQuilibrium Filterzzzzz
	Biquad *filterPeakLow = new Biquad();
	Biquad *filterPeakHigh = new Biquad();

	
 
	
private:
	double lowFreq;
	double lowBoost;
	double highFreq;
	double highShelf;
};


