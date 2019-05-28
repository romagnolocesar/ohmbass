#pragma once
#include "controlsManager.h"
#include "graphicsManager.h"
#include "Biquad.h"

class ModEQuilibrium : public ModulesModel
{
public:
	EModulesName moduleName = EQUILIBRIUM;

	float LINE_STARTX = 562;
	float LINE_STARTY = 630;
	float LINE_ENDX = 803;
	float LINE_ENDY = 630;

	IBitmap pBitmap;
	GraphicsModel::EGraphicsType graphicType;
	GraphicsModel* iGraphic;


	void setLowFreq(double newLowFreq);
	void setLowBoost(double newLowBoost);
	void setHighFreq(double newHighFreq);
	void setHighShelf(double newHighShelf);
	void setActiOhmBassMagic(bool newState);

	double getLowFreq();
	double getLowBoost();
	double getHighFreq();
	double getHighShelf();
	bool getActiOhmBassMagic();

	void init(controlsManager* IControlsManager, graphicsManager* IGraphicsManager);
	void doModelsControlsInIControlsCollection(IPlug* myOhmBass, controlsManager* iControlsManager, graphicsManager* iGraphicsManager, int i);

	//Filters
	void updateLowFilterValues();
	void updateHighFilterValues();
	void updateLowShelfFilter();
	void updateControlNasalHighFreq();
	void updateControlNasalLowFreq();
	void updateHighCutFilter();


	double process(double output);

	//EQuilibrium Filterzzzzz
	Biquad *filterPeakLow = new Biquad();
	Biquad *filterPeakHigh = new Biquad();
	
	//ActiOhm Auto Magic Filters
	Biquad *filterLowShelf = new Biquad();
	Biquad *filterNasalHighFreq = new Biquad();
	Biquad *filterNasalLowFreq = new Biquad();
	Biquad *filterHighCut = new Biquad();

	
 
	
private:
	double lowFreq;
	double lowBoost;
	double highFreq;
	double highShelf;
	bool actiOhmBassMagic;
};


