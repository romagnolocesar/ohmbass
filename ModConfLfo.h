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
	void doModelsControlsInIControlsCollection(IPlug* myOhmBass, controlsManager* iControlsManager, graphicsManager* iGraphicsManager, int i);


	//void createModalBox(IPlug* myOhmBass, IGraphics* pGraphics, int w, int h);
	void showModalBox(controlsManager* iControlsManager);
	void hideModalBox(controlsManager* iControlsManager);

	void fillAuxParams(controlsManager * iControlsManager);



private:
	IModalBox* modalBoxConfLfo;
	
};

