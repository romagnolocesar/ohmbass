#include "controlsManager.h"
#include "graphicsManager.h"

class ModGainFaders :
	public ModulesModel
{
public:
	EModulesName moduleName = GAINFADERS;

	IBitmap pBitmap;
	IRECT iRect;
	GraphicsModel::EGraphicsType graphicType;
	GraphicsModel* iGraphic;
	EDirection* EDirection;

	void ModGainFaders::init(controlsManager* IControlsManager, graphicsManager* IGraphicsManager);
};

