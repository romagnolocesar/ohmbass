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
	int mBgBtnOscWavesOsc1, mBgBtnOscWavesOsc2, mOsc1PitchMod, mOsc2PitchMod;

	void init(controlsManager* IControlsManager, graphicsManager* IGraphicsManager);
	void doModelsControlsInIControlsCollection(IPlug* myOhmBass, controlsManager* iControlsManager, graphicsManager* iGraphicsManager, int i);
	void fillSetOfWavesIcons(controlsManager* iControlsManager);
	void OnParamChange(controlsManager* IControlsManager, int paramIdx, int idxWaveMode, bool isPluginInitialized);
	void ToggleIconsWavesButtons(controlsManager* IControlsManager, int nOsc, int idxWaveMode);
};

