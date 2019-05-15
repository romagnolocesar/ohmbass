#include "controlsManager.h"
#include "graphicsManager.h"

class ModGainFaders :
	public ModulesModel
{
public:
	EModulesName moduleName = GAINFADERS;

	IBitmap pBitmap;
	IRECT iRect;
	GraphicsModel::EGraphicsType graphicType;
	GraphicsModel* iGraphic;
	EDirection* EDirection;
	double length;

	int mFadersHandlerOffOsc1;
	int mFadersHandlerOnOsc1;
	int mFadersHandlerOffOsc2;
	int mFadersHandlerOnOsc2;

	void init(controlsManager* IControlsManager, graphicsManager* IGraphicsManager);
	void doModelsControlsInIControlsCollection(IPlug* myOhmBass, controlsManager* iControlsManager, graphicsManager* iGraphicsManager, int i);
	void fillSetOfFaders(controlsManager* iControlsManager);
	void ToggleFaders(controlsManager* IControlsManager, int nOsc, int idxWaveMode, IParam* param);
	void OnParamChange(controlsManager* IControlsManager, int paramIdx, bool isPluginInitialized, IParam* param);
};

