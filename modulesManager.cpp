#include "modulesManager.h"

void modulesManager::InitAllModules(controlsManager* iControlsManager, graphicsManager* iGraphicsManager) {
	//Initializing all modules (controls)
	iModOscillators->init(iControlsManager, iGraphicsManager);
	iModGainFaders->init(iControlsManager, iGraphicsManager);
	iModFilters->init(iControlsManager, iGraphicsManager);
	iModAmpEnvelope->init(iControlsManager, iGraphicsManager);
	iModEQuilibrium->init(iControlsManager, iGraphicsManager);
	iModConfLfo->init(iControlsManager, iGraphicsManager);
	iModToolsBar->init(iControlsManager, iGraphicsManager);
	
}

void modulesManager::loadAuxParameters(controlsManager* iControlsManager) {
	iModOscillators->fillSetOfWavesIcons(iControlsManager);
	iModConfLfo->fillAuxParams(iControlsManager);
	iModGainFaders->fillSetOfFaders(iControlsManager);
}

double modulesManager::process(double output)
{
	output = iModEQuilibrium->process(output);

	return output;
}

modulesManager::modulesManager()
{}


modulesManager::~modulesManager()
{
}
