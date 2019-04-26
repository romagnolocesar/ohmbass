#include "controlsManager.h"


class ModOscillators : public ModulesModel
{
public:
	EModulesName moduleName = OSCILATORS;

	ModOscillators();
	~ModOscillators();

	IGraphics* pGraphics;

	void init(controlsManager* IControlsManager);
};

