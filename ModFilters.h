#pragma once
#include "controlsManager.h"
#include "graphicsManager.h"

class ModFilters :
	public ModulesModel
{
public:
	EModulesName moduleName = FILTERS;

	ModFilters();
	~ModFilters();


	IBitmap pBitmap;
	GraphicsModel::EGraphicsType graphicType;
	GraphicsModel* iGraphic;

	void init(controlsManager* IControlsManager, graphicsManager* IGraphicsManager);
	void doModelsControlsInIControlsCollection(IPlug* myOhmBass, controlsManager* iControlsManager, graphicsManager* iGraphicsManager, int i);
};

