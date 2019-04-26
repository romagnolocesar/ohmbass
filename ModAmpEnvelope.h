#pragma once
#include "OhmBass.h"
#include "controlsManager.h"

class ModAmpEnvelope : public ModulesModel
{
public:
	EModulesName moduleName = AMPENVELOPE;

	/*void init(controlsManager* IControlsManager);*/

	ModAmpEnvelope();
	~ModAmpEnvelope();
};

