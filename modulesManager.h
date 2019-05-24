//Modules
#include "ModOscillators.h"
#include "ModGainFaders.h"
#include "ModFilters.h"
#include "ModAmpEnvelope.h"
#include "ModEQuilibrium.h"


class modulesManager
{
public:
	modulesManager();
	~modulesManager();

	void InitAllModules(controlsManager* iControlsManager, graphicsManager* iGraphicsManager);
	void loadAuxParameters(controlsManager* iControlsManager);
	double process(double output);


	//Create Modules
	ModOscillators* iModOscillators = new ModOscillators();
	ModGainFaders* iModGainFaders = new ModGainFaders();
	ModFilters* iModFilters = new ModFilters();
	ModAmpEnvelope* iModAmpEnvelope = new ModAmpEnvelope();
	ModEQuilibrium* iModEQuilibrium = new ModEQuilibrium();
};

