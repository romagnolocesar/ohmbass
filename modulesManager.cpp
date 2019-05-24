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

double modulesManager::process(double output)
{
	//(EQLIBRIUM) Filters	
	output = iModEQuilibrium->filterPeakLow->process(output);
	output = iModEQuilibrium->filterPeakHigh->process(output);

	return output;
}

modulesManager::modulesManager()
{}


modulesManager::~modulesManager()
{
}
