#pragma once
#include "ModulesModel.h"
#include <vector> using namespace std; 


class ModulesManager {
public:
	std::vector<class ModulesModel * > collection;

	//Initializing all modules
	//iModOscillators->init(iControlsManager);
	//iModGainFaders->init(iControlsManager);
	//iModFilters->init(iControlsManager);
	//iModAmpEnvelope->init(iControlsManager);
	//iModEQuilibrium->init(iControlsManager);

	//Load Modules
	//ModOscillators* iModOscillators = new ModOscillators();
	//ModGainFaders* iModGainFaders = new ModGainFaders();
	//ModFilters* iModFilters = new ModFilters();
	//ModAmpEnvelope* iModAmpEnvelope = new ModAmpEnvelope();
	//ModEQuilibrium* iModEQuilibrium = new ModEQuilibrium();

	
	
	int Add(ModulesModel* myInstance)
	{
			collection.push_back(myInstance);
			return (collection.size() - 1);
	}

	int Count(void)
	{
		return collection.size();
	}

private:

};