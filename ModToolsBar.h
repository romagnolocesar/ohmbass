#pragma once
#include "controlsManager.h"
#include "graphicsManager.h"

class ModToolsBar :
	public ModulesModel
{
public:
	EModulesName moduleName = TOOLSBAR;

	IBitmap pBitmap;
	GraphicsModel::EGraphicsType graphicType;
	GraphicsModel* iGraphic;

	ModToolsBar();
	~ModToolsBar();

	void ModToolsBar::init(controlsManager* IControlsManager, graphicsManager* IGraphicsManager);
	void ModToolsBar::doModelsControlsInIControlsCollection(IPlug* myOhmBass, controlsManager* iControlsManager, graphicsManager* iGraphicsManager, int i);



private:

};

