#include "controlsManager.h"
#include "graphicsManager.h"


class ModOscillators : public ModulesModel
{
public:
	EModulesName moduleName = OSCILATORS;

	IBitmap pBitmap;
	GraphicsModel::EGraphicsType graphicType;
	GraphicsModel* iGraphic;
	EDirection* EDirection;

	void init(controlsManager* IControlsManager, graphicsManager* IGraphicsManager);
};

