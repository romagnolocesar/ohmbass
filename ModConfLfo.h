#pragma once
#include "controlsManager.h"
#include "graphicsManager.h"

class ModConfLfo :
	public ModulesModel
{
public:
	EModulesName moduleName = CONFLFO;

	ModConfLfo();
	~ModConfLfo();

	IBitmap pBitmap;
	GraphicsModel::EGraphicsType graphicType;
	GraphicsModel* iGraphic;

	int mOsc1PitchMod, mOsc2PitchMod;

	void ModConfLfo::init(controlsManager* IControlsManager, graphicsManager* IGraphicsManager);
	void fillAuxParams(controlsManager* iControlsManager);
	void doModelsControlsInIControlsCollection(IPlug* myOhmBass, controlsManager* iControlsManager, graphicsManager* iGraphicsManager, int i);


	//void createModalBox(IPlug* myOhmBass, IGraphics* pGraphics, int w, int h);
	void showLFOFrequency(controlsManager * iControlsManager, int lfoNumber);
	void showModalBox(controlsManager* iControlsManager);
	void hideLFOFrequency(controlsManager * iControlsManager, int lfoNumber);
	void hideModalBox(controlsManager* iControlsManager);

	int frequencyKnobLFO1, frequencyKnobLFO2, frequencyKnobLFO3;
	


private:
	IModalBox* modalBoxConfLfo;
	
};

