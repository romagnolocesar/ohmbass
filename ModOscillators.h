#include "controlsManager.h"
#include "graphicsManager.h"


class ModOscillators : public ModulesModel
{
public:
	EModulesName moduleName = OSCILATORS;

	IBitmap pBitmap;
	IRECT iRect;
	GraphicsModel::EGraphicsType graphicType;
	GraphicsModel* iGraphic;
	EDirection* EDirection;
	IGraphics* pGraphics;
	int mapWavesIconsIdx[2][4][2];

	void init(controlsManager* IControlsManager, graphicsManager* IGraphicsManager);
	void doModelsControlsInIControlsCollection(IPlug* myOhmBass, controlsManager* iControlsManager, graphicsManager* iGraphicsManager, int i);
	void fillSetOfWavesIcons(IPlug* myOhmBass, controlsManager* iControlsManager);
	void OnParamChange(controlsManager* IControlsManager, int paramIdx, bool isPluginInitialized);
	void ToggleIconsWavesButtons(int nOsc, int idxWaveMode);
};

