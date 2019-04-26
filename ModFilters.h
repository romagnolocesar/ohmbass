#pragma once
#include "OhmBass.h"
#include "controlsManager.h"

class ModFilters :
	public ModulesModel
{
public:
	EModulesName moduleName = FILTERS;

	ModFilters();
	~ModFilters();

	/*void ModFilters::init(controlsManager* IControlsManager);*/
};

