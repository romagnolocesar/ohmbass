#include "modulesManager.h"

void modulesManager::InitAllModules(controlsManager* iControlsManager, graphicsManager* iGraphicsManager) {
	//Initializing all modules (controls)
	iModOscillators->init(iControlsManager, iGraphicsManager);
	iModGainFaders->init(iControlsManager, iGraphicsManager);
	iModFilters->init(iControlsManager, iGraphicsManager);
	iModAmpEnvelope->init(iControlsManager, iGraphicsManager);
	iModEQuilibrium->init(iControlsManager, iGraphicsManager);
}

void modulesManager::loadAuxParameters(controlsManager* iControlsManager) {
	iModOscillators->fillSetOfWavesIcons(iControlsManager);
	iModGainFaders->fillSetOfFaders(iControlsManager);
}

modulesManager::modulesManager()
{}


modulesManager::~modulesManager()
{
}
