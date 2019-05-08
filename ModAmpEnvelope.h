#include "controlsManager.h"
#include "graphicsManager.h"

class ModAmpEnvelope : public ModulesModel
{
public:
	EModulesName moduleName = AMPENVELOPE;

	ModAmpEnvelope();
	~ModAmpEnvelope();

	IBitmap pBitmap;
	GraphicsModel::EGraphicsType graphicType;
	GraphicsModel* iGraphic;

	void init(controlsManager* IControlsManager, graphicsManager* IGraphicsManager);
	void doModelsControlsInIControlsCollection(IPlug* myOhmBass, controlsManager* iControlsManager, graphicsManager* iGraphicsManager, int i);
};

