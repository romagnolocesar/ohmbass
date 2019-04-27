#include "controlsManager.h"
#include "IGraphics.h"


class ModOscillators : public ModulesModel
{
public:
	EModulesName moduleName = OSCILATORS;

	IBitmap pBitmap;
	GraphicsModel::EGraphicsType graphicType;
	GraphicsModel* iGraphic;
	EDirection* EDirection;

	void init(controlsManager* IControlsManager, IGraphics* pGraphics);
};

