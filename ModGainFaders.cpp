#include "ModGainFaders.h"

void ModGainFaders::init(controlsManager* IControlsManager, graphicsManager* IGraphicsManager) {
	/* Glows */
	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(FADERGLOW_ID, FADERGLOW_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Fader Glow Osc1", ControlsModel::DOUBLE, 452, 219, 0.0, 0.0, 1.0, iGraphic);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(FADERGLOW_ID, FADERGLOW_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Fader Glow Osc2", ControlsModel::DOUBLE, 533, 219, 0.0, 0.0, 1.0, iGraphic);
}

	//void ModGainFaders::init(controlsManager* IControlsManager) {
//
//	IControlsManager->addParam(this->moduleName, "Fader Glow Osc1", ControlsModel::DOUBLE, 452, 219, 0.0, 0.0, 1.0);
//	IControlsManager->addParam(this->moduleName, "Fader Glow Osc2", ControlsModel::DOUBLE, 533, 219, 0.0, 0.0, 1.0);
//	IControlsManager->addParam(this->moduleName, "Fader Handler Off Osc1", ControlsModel::DOUBLE, 429, 210, 0.8, 0.0, 1.0);
//	IControlsManager->addParam(this->moduleName, "Fader Handler Off Osc2", ControlsModel::DOUBLE, 510, 210, 0.0, 0.0, 1.0);
//	IControlsManager->addParam(this->moduleName, "Fader Handler On Osc1", ControlsModel::DOUBLE, 429, 210, 0.8, 0.0, 1.0);
//	IControlsManager->addParam(this->moduleName, "Fader Handler On Osc2", ControlsModel::DOUBLE, 510, 210, 0.0, 0.0, 1.0);
//}


//void ModGainFaders::init(controlsManager* IControlsManager) {
//
//	IControlsManager->addParam(this->moduleName, "", ControlsModel::DOUBLE, 452, 219, 0.0, 0.0, 1.0);
//	IControlsManager->addParam(this->moduleName, "", ControlsModel::DOUBLE, 533, 219, 0.0, 0.0, 1.0);

//	IControlsManager->addParam(this->moduleName, "", ControlsModel::DOUBLE, 429, 210, 0.8, 0.0, 1.0);
//	IControlsManager->addParam(this->moduleName, "", ControlsModel::DOUBLE, 510, 210, 0.0, 0.0, 1.0);
//	IControlsManager->addParam(this->moduleName, "", ControlsModel::DOUBLE, 429, 210, 0.8, 0.0, 1.0);
//	IControlsManager->addParam(this->moduleName, "", ControlsModel::DOUBLE, 510, 210, 0.0, 0.0, 1.0);
//}

//Faders
//	this->fadersHandlerOnOsc1 = pGraphics->LoadIBitmap(FADERHANDLERON_ID, FADERHANDLERON_FN);
//	this->fadersHandlerOnOsc2 = pGraphics->LoadIBitmap(FADERHANDLERON_ID, FADERHANDLERON_FN);
//	this->fadersHandlerOffOsc1 = pGraphics->LoadIBitmap(FADERHANDLEROFF_ID, FADERHANDLEROFF_FN);
//	this->fadersHandlerOffOsc2 = pGraphics->LoadIBitmap(FADERHANDLEROFF_ID, FADERHANDLEROFF_FN);
//	//Glows
//	this->faderGlowBarOsc1 = pGraphics->LoadIBitmap(FADERGLOW_ID, FADERGLOW_FN);
//	this->faderGlowBarOsc2 = pGraphics->LoadIBitmap(FADERGLOW_ID, FADERGLOW_FN);

//Faders Oscillators
//		case controlsManager::mFadersHandlerOffOsc1:
//			graphic = &fadersHandlerOffOsc1;
//			iControlsManager->Osc1FaderHandlerOff = new
//			pGraphics->AttachControl(iControlsManager->Osc1FaderHandlerOff);
//			break;
//		case controlsManager::mFadersHandlerOffOsc2:
//			graphic = &fadersHandlerOffOsc2;
//			iControlsManager->Osc2FaderHandlerOff = new IFaderControl(myOhmBass, properties.x, properties.y, 210, i, graphic, EDirection::kVertical);
//			pGraphics->AttachControl(iControlsManager->Osc2FaderHandlerOff);
//			break;
//		case controlsManager::mFadersHandlerOnOsc1:
//			graphic = &fadersHandlerOnOsc1;
//			iControlsManager->Osc1FaderHandlerOn = new IFaderControl(myOhmBass, properties.x, properties.y, 210, i, graphic, EDirection::kVertical);
//			iControlsManager->Osc1FaderHandlerOn->Hide(TRUE);
//			iControlsManager->Osc1FaderHandlerOn->GrayOut(TRUE, 0.99f);
//			pGraphics->AttachControl(iControlsManager->Osc1FaderHandlerOn);
//			break;
//		case controlsManager::mFadersHandlerOnOsc2:
//			graphic = &fadersHandlerOnOsc2;
//			iControlsManager->Osc2FaderHandlerOn = new IFaderControl(myOhmBass, properties.x, properties.y, 210, i, graphic, EDirection::kVertical);
//			iControlsManager->Osc2FaderHandlerOn->Hide(TRUE);
//			iControlsManager->Osc2FaderHandlerOn->GrayOut(TRUE, 0.99f);
//			pGraphics->AttachControl(iControlsManager->Osc2FaderHandlerOn);
//			break;



//		case controlsManager::mFadersGlowOsc1:
//			graphic = &faderGlowBarOsc1;
//			iControlsManager->Osc1FaderGlow = new IBitmapControl(myOhmBass, properties.x, properties.y, i, graphic);
//			pGraphics->AttachControl(iControlsManager->Osc1FaderGlow);
//			break;
//		case controlsManager::mFadersGlowOsc2:
//			graphic = &faderGlowBarOsc2;
//			iControlsManager->Osc2FaderGlow = new IBitmapControl(myOhmBass, properties.x, properties.y, i, graphic);
//			pGraphics->AttachControl(iControlsManager->Osc2FaderGlow);
//			break;