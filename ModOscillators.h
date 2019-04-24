#pragma once
#include "OhmBass.h"
#include "controlsManager.h"

class ModOscillators : public ModulesModel
{
public:
	EModulesName moduleName = OSCILATORS;

	ModOscillators();
	~ModOscillators();

	void init(controlsManager* IControlsManager);
};

