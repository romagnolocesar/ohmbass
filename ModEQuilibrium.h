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
	IBezierControl* iBezierControl;

	//Bezier default position
	float BezierXstart = 560.0f;
	float BezierYstart = 610.0f;
	float BezierXend = 800.0f;
	float BezierYend = 610.0f;


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
	void updateBezierLine();


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


