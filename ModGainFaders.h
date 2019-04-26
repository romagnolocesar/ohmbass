#pragma once
#include "OhmBass.h"
#include "controlsManager.h"

class ModGainFaders :
	public ModulesModel
{
public:
	ModGainFaders();
	~ModGainFaders();

	EModulesName moduleName = GAINFADERS;

	/*void ModGainFaders::init(controlsManager* IControlsManager);*/
};

