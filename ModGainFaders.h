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

	void ModGainFaders::init(controlsManager* IControlsManager, graphicsManager* IGraphicsManager);
	void ModGainFaders::OnParamChange(controlsManager* IControlsManager, int paramIdx, bool isPluginInitialized);

	/*if (isPluginInitialized) {

		iControlsManager->Osc1FaderHandlerOff->Hide(TRUE);
		iControlsManager->Osc1FaderHandlerOff->GrayOut(TRUE, 0.99f);
		
		iControlsManager->Osc1FaderHandlerOn->Hide(FALSE);
		iControlsManager->Osc1FaderHandlerOn->GrayOut(FALSE);
		
		iControlsManager->Osc2FaderHandlerOn->Hide(TRUE);
		iControlsManager->Osc2FaderHandlerOn->GrayOut(TRUE, 0.99f);
		
		iControlsManager->Osc2FaderHandlerOff->Hide(FALSE);
		iControlsManager->Osc2FaderHandlerOff->GrayOut(FALSE);
		
		iControlsManager->Osc1FaderHandlerOn->SetValueFromPlug(param->Value());
		iControlsManager->Osc1FaderHandlerOff->SetValueFromPlug(param->Value());
		
		
		changer = bind(&VoiceManager::setOscillatorOneOutput, _1, param->Value());
	}*/
};

