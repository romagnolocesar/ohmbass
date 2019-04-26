#include "controlsManager.h"



class ModOscillators : public ModulesModel
{
public:
	EModulesName moduleName = OSCILATORS;

	ModOscillators();
	~ModOscillators();

	IBitmap pBitmap;
	IGraphics* pGraphics;
	GraphicsModel::EGraphicsType graphicType;
	GraphicsModel* iGraphic;

	void init(controlsManager* IControlsManager);
};

