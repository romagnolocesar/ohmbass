#pragma once
#include "controlsManager.h"
#include "graphicsManager.h"
#include "Biquad.h"

class ModEQuilibrium : public ModulesModel
{
public:
	EModulesName moduleName = EQUILIBRIUM;

	#define LINE_STARTX = 562;
	#define LINE_STARTY = 640;
	#define LINE_CTRX = 600;
	#define LINE_CTRY = 570;
	#define LINE_ENDX = 803;
	#define LINE_ENDY = 640;

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


