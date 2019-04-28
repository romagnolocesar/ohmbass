#include "ModOscillators.h"



void ModOscillators::init(controlsManager* IControlsManager, graphicsManager* IGraphicsManager) {

	/* Waves Buttons of Oscillator 1*/
	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(BGBTNOSCWAVES_ID, BGBTNOSCWAVES_FN, 2);
	graphicType = GraphicsModel::RADIOBUTTONSCONTROL;
	iRect = IRECT(43, 206, 43 + (56 * 4), 56 + (60 * 4));
	iGraphic = new GraphicsModel(pBitmap, graphicType, iRect, EDirection::kHorizontal);
	IControlsManager->addParam(this->moduleName, "Bg Btn Osc 1 Waves", ControlsModel::INT, 99, 206, 1, 1, 4, iGraphic);

	/* Waves Buttons of Oscillator 2*/
	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(BGBTNOSCWAVES_ID, BGBTNOSCWAVES_FN, 2);
	graphicType = GraphicsModel::RADIOBUTTONSCONTROL;
	iRect = IRECT(43, 306, 43 + (56 * 4), 126 + (60 * 4));
	iGraphic = new GraphicsModel(pBitmap, graphicType, iRect, EDirection::kHorizontal);
	IControlsManager->addParam(this->moduleName, "Bg Btn Osc 2 Waves", ControlsModel::INT, 99, 306, 1, 1, 4, iGraphic);

	/* Waves Icons */
	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONSINEWAVEOFF_ID, ICONSINEWAVEOFF_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Icon Sine Wave Off OSC1", ControlsModel::NONE, 58, 218, TRUE, iGraphic);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONSINEWAVEON_ID, ICONSINEWAVEON_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Icon Sine Wave On OSC1", ControlsModel::NONE, 58, 218, TRUE, iGraphic);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONSINEWAVEON_ID, ICONSINEWAVEON_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Icon Saw Wave Off OSC1", ControlsModel::NONE, 58, 218, TRUE, iGraphic);


	/*IControlsManager->addParam(this->moduleName, "Bg Btn Osc 2 Waves", ControlsModel::INT, 99, 306, 1, 1, 4);
		IControlsManager->addParam(this->moduleName, "Icon Sine Wave Off OSC1", ControlsModel::NONE, 58, 218, TRUE);
		IControlsManager->addParam(this->moduleName, "Icon Sine Wave On OSC1", ControlsModel::NONE, 58, 218, TRUE);

		IControlsManager->addParam(this->moduleName, "Icon Saw Wave Off OSC1", ControlsModel::NONE, 114, 218, TRUE);

		IControlsManager->addParam(this->moduleName, "Icon Saw Wave On OSC1", ControlsModel::NONE, 114, 218, FALSE);
		IControlsManager->addParam(this->moduleName, "Icon Square Wave Off OSC1", ControlsModel::NONE, 170, 218, TRUE);
		IControlsManager->addParam(this->moduleName, "Icon Square Wave On OSC1", ControlsModel::NONE, 170, 218, FALSE);
		IControlsManager->addParam(this->moduleName, "Icon Triangle Wave Off OSC1", ControlsModel::NONE, 226, 218, TRUE);
		IControlsManager->addParam(this->moduleName, "Icon Triangle Wave On OSC1", ControlsModel::NONE, 226, 218, FALSE);
		IControlsManager->addParam(this->moduleName, "Icon Sine Wave Off OSC2", ControlsModel::NONE, 58, 318, TRUE);
		IControlsManager->addParam(this->moduleName, "Icon Sine Wave On OSC2", ControlsModel::NONE, 58, 318, TRUE);
		IControlsManager->addParam(this->moduleName, "Icon Saw Wave Off OSC2", ControlsModel::NONE, 114, 318, TRUE);
		IControlsManager->addParam(this->moduleName, "Icon Saw Wave On OSC2", ControlsModel::NONE, 114, 318, FALSE);
		IControlsManager->addParam(this->moduleName, "Icon Square Wave Off OSC2", ControlsModel::NONE, 170, 318, TRUE);
		IControlsManager->addParam(this->moduleName, "Icon Square Wave On OSC2", ControlsModel::NONE, 170, 318, FALSE);
		IControlsManager->addParam(this->moduleName, "Icon Triangle Wave Off OSC2", ControlsModel::NONE, 226, 318, TRUE);
		IControlsManager->addParam(this->moduleName, "Icon Triangle Wave On OSC2", ControlsModel::NONE, 226, 318, FALSE);
		IControlsManager->addParam(this->moduleName, "Osc 1 Pitch Mod", ControlsModel::NONE, 308, 195, 0.0, 0.0, 1.0);
		IControlsManager->addParam(this->moduleName, "Osc 2 Pitch Mod", ControlsModel::NONE, 308, 295, 0.0, 0.0, 1.0);*/
}



//		//Osc1 Icons Buttons Waves
	//	case controlsManager::mIconSineWaveOffOsc1:
	//		graphic = &iconSineWaveOffOsc1;
	//		iControlsManager->control = 
	//		iControlsManager->control->Hide(!properties.defaultVal);
	//		iControlsManager->control->GrayOut(TRUE, 0.99f);
	//		break;
	//	case controlsManager::mIconSineWaveOnOsc1:
	//		graphic = &iconSineWaveOnOsc1;
	//		iControlsManager->Osc1ControlSineOn = new IBitmapControl(myOhmBass, properties.x, properties.y, i, graphic);
	//		iControlsManager->Osc1ControlSineOn->Hide(!properties.defaultVal);
	//		iControlsManager->Osc1ControlSineOn->GrayOut(TRUE, 0.99f);
	//		pGraphics->AttachControl(iControlsManager->Osc1ControlSineOn);
	//		break;
	//	case iControlsManager->mIconSawWaveOffOsc1:
	//		graphic = &iconSawWaveOffOsc1;
	//		iControlsManager->control = new IBitmapControl(myOhmBass, properties.x, properties.y, i, graphic);
	//		iControlsManager->control->Hide(!properties.defaultVal);
	//		iControlsManager->control->GrayOut(TRUE, 0.99f);
	//		break;
	//	case iControlsManager->mIconSawWaveOnOsc1:
	//		graphic = &iconSawWaveOnOsc1;
	//		iControlsManager->Osc1ControlSawOn = new IBitmapControl(myOhmBass, properties.x, properties.y, i, graphic);
	//		iControlsManager->Osc1ControlSawOn->Hide(!properties.defaultVal);
	//		iControlsManager->Osc1ControlSawOn->GrayOut(TRUE, 0.99f);
	//		pGraphics->AttachControl(iControlsManager->Osc1ControlSawOn);
	//		break;
	//	case iControlsManager->mIconSqWaveOffOsc1:
	//		graphic = &iconSquareWaveOffOsc1;
	//		iControlsManager->control = new IBitmapControl(myOhmBass, properties.x, properties.y, i, graphic);
	//		iControlsManager->control->Hide(!properties.defaultVal);
	//		iControlsManager->control->GrayOut(TRUE, 0.99f);
	//		break;
	//	case iControlsManager->mIconSqWaveOnOsc1:
	//		graphic = &iconSquareWaveOnOsc1;
	//		iControlsManager->Osc1ControlSquareOn = new IBitmapControl(myOhmBass, properties.x, properties.y, i, graphic);
	//		iControlsManager->Osc1ControlSquareOn->Hide(!properties.defaultVal);
	//		iControlsManager->Osc1ControlSquareOn->GrayOut(TRUE, 0.99f);
	//		pGraphics->AttachControl(iControlsManager->Osc1ControlSquareOn);
	//		break;
	//	case iControlsManager->mIconTriangleWaveOffOsc1:
	//		graphic = &iconTriangleWaveOffOsc1;
	//		iControlsManager->control = new IBitmapControl(myOhmBass, properties.x, properties.y, i, graphic);
	//		iControlsManager->control->Hide(!properties.defaultVal);
	//		iControlsManager->control->GrayOut(TRUE, 0.99f);
	//		break;
	//	case iControlsManager->mIconTriangleWaveOnOsc1:
	//		graphic = &iconTriangleWaveOnOsc1;
	//		iControlsManager->Osc1ControlTriagleOn = new IBitmapControl(myOhmBass, properties.x, properties.y, i, graphic);
	//		iControlsManager->Osc1ControlTriagleOn->Hide(!properties.defaultVal);
	//		iControlsManager->Osc1ControlTriagleOn->GrayOut(TRUE, 0.99f);
	//		pGraphics->AttachControl(iControlsManager->Osc1ControlTriagleOn);
	//		break;
	//		//Osc2 Icons Buttons Waves
	//	case iControlsManager->mIconSineWaveOffOsc2:
	//		graphic = &iconSineWaveOffOsc2;
	//		iControlsManager->control = new IBitmapControl(myOhmBass, properties.x, properties.y, i, graphic);
	//		iControlsManager->control->Hide(!properties.defaultVal);
	//		iControlsManager->control->GrayOut(TRUE, 0.99f);
	//		break;
	//	case iControlsManager->mIconSineWaveOnOsc2:
	//		graphic = &iconSineWaveOnOsc2;
	//		iControlsManager->Osc2ControlSineOn = new IBitmapControl(myOhmBass, properties.x, properties.y, i, graphic);
	//		iControlsManager->Osc2ControlSineOn->Hide(!properties.defaultVal);
	//		iControlsManager->Osc2ControlSineOn->GrayOut(TRUE, 0.99f);
	//		pGraphics->AttachControl(iControlsManager->Osc2ControlSineOn);
	//		break;
	//	case iControlsManager->mIconSawWaveOffOsc2:
	//		graphic = &iconSawWaveOffOsc2;
	//		iControlsManager->control = new IBitmapControl(myOhmBass, properties.x, properties.y, i, graphic);
	//		iControlsManager->control->SetBlendMethod(IChannelBlend::EBlendMethod::kBlendColorDodge);
	//		iControlsManager->control->Hide(!properties.defaultVal);
	//		iControlsManager->control->GrayOut(TRUE, 0.99f);
	//		break;
	//	case iControlsManager->mIconSawWaveOnOsc2:
	//		graphic = &iconSawWaveOnOsc2;
	//		iControlsManager->Osc2ControlSawOn = new IBitmapControl(myOhmBass, properties.x, properties.y, i, graphic);
	//		iControlsManager->Osc2ControlSawOn->SetBlendMethod(IChannelBlend::EBlendMethod::kBlendColorDodge);
	//		iControlsManager->Osc2ControlSawOn->Hide(!properties.defaultVal);
	//		iControlsManager->Osc2ControlSawOn->GrayOut(TRUE, 0.99f);
	//		pGraphics->AttachControl(iControlsManager->Osc2ControlSawOn);
	//		break;
	//	case iControlsManager->mIconSqWaveOffOsc2:
	//		graphic = &iconSquareWaveOffOsc2;
	//		iControlsManager->control = new IBitmapControl(myOhmBass, properties.x, properties.y, i, graphic);
	//		iControlsManager->control->SetBlendMethod(IChannelBlend::EBlendMethod::kBlendColorDodge);
	//		iControlsManager->control->Hide(!properties.defaultVal);
	//		iControlsManager->control->GrayOut(TRUE, 0.99f);
	//		break;
	//	case iControlsManager->mIconSqWaveOnOsc2:
	//		graphic = &iconSquareWaveOnOsc2;
	//		iControlsManager->Osc2ControlSquareOn = new IBitmapControl(myOhmBass, properties.x, properties.y, i, graphic);
	//		iControlsManager->Osc2ControlSquareOn->SetBlendMethod(IChannelBlend::EBlendMethod::kBlendColorDodge);
	//		iControlsManager->Osc2ControlSquareOn->Hide(!properties.defaultVal);
	//		iControlsManager->Osc2ControlSquareOn->GrayOut(TRUE, 0.99f);
	//		pGraphics->AttachControl(iControlsManager->Osc2ControlSquareOn);
	//		break;
	//	case iControlsManager->mIconTriangleWaveOffOsc2:
	//		graphic = &iconTriangleWaveOffOsc2;
	//		iControlsManager->control = new IBitmapControl(myOhmBass, properties.x, properties.y, i, graphic);
	//		iControlsManager->control->SetBlendMethod(IChannelBlend::EBlendMethod::kBlendColorDodge);
	//		iControlsManager->control->Hide(!properties.defaultVal);
	//		iControlsManager->control->GrayOut(TRUE, 0.99f);
	//		break;
	//	case iControlsManager->mIconTriangleWaveOnOsc2:
	//		graphic = &iconTriangleWaveOnOsc2;
	//		iControlsManager->Osc2ControlTriagleOn = new IBitmapControl(myOhmBass, properties.x, properties.y, i, graphic);
	//		iControlsManager->Osc2ControlTriagleOn->SetBlendMethod(IChannelBlend::EBlendMethod::kBlendColorDodge);
	//		iControlsManager->Osc2ControlTriagleOn->Hide(!properties.defaultVal);
	//		iControlsManager->Osc2ControlTriagleOn->GrayOut(TRUE, 0.99f);
	//		pGraphics->AttachControl(iControlsManager->Osc2ControlTriagleOn);
	//		break;




//void graphicsManager::loadWavesIcons()
//{
//	this->iconSineWaveOnOsc1 = pGraphics->LoadIBitmap();
//	this->iconSineWaveOffOsc1 = pGraphics->LoadIBitmap(ICONSINEWAVEOFF_ID, ICONSINEWAVEOFF_FN);

//	this->iconSawWaveOnOsc1 = pGraphics->LoadIBitmap(ICONSAWWAVEON_ID, ICONSAWWAVEON_FN);
//	this->iconSawWaveOffOsc1 = pGraphics->LoadIBitmap(ICONSAWWAVEOFF_ID, ICONSAWWAVEOFF_FN);
//	this->iconSquareWaveOnOsc1 = pGraphics->LoadIBitmap(ICONSQUAREWAVEON_ID, ICONSQUAREWAVEON_FN);
//	this->iconSquareWaveOffOsc1 = pGraphics->LoadIBitmap(ICONSQUAREWAVEOFF_ID, ICONSQUAREWAVEOFF_FN);
//	this->iconTriangleWaveOnOsc1 = pGraphics->LoadIBitmap(ICONTRIANGLEWAVEON_ID, ICONTRIANGLEWAVEON_FN);
//	this->iconTriangleWaveOffOsc1 = pGraphics->LoadIBitmap(ICONTRIANGLEWAVEOFF_ID, ICONTRIANGLEWAVEOFF_FN);
//	this->iconSineWaveOnOsc2 = pGraphics->LoadIBitmap(ICONSINEWAVEON_ID, ICONSINEWAVEON_FN);
//	this->iconSineWaveOffOsc2 = pGraphics->LoadIBitmap(ICONSINEWAVEOFF_ID, ICONSINEWAVEOFF_FN);
//	this->iconSawWaveOnOsc2 = pGraphics->LoadIBitmap(ICONSAWWAVEON_ID, ICONSAWWAVEON_FN);
//	this->iconSawWaveOffOsc2 = pGraphics->LoadIBitmap(ICONSAWWAVEOFF_ID, ICONSAWWAVEOFF_FN);
//	this->iconSquareWaveOnOsc2 = pGraphics->LoadIBitmap(ICONSQUAREWAVEON_ID, ICONSQUAREWAVEON_FN);
//	this->iconSquareWaveOffOsc2 = pGraphics->LoadIBitmap(ICONSQUAREWAVEOFF_ID, ICONSQUAREWAVEOFF_FN);
//	this->iconTriangleWaveOnOsc2 = pGraphics->LoadIBitmap(ICONTRIANGLEWAVEON_ID, ICONTRIANGLEWAVEON_FN);
//	this->iconTriangleWaveOffOsc2 = pGraphics->LoadIBitmap(ICONTRIANGLEWAVEOFF_ID, ICONTRIANGLEWAVEOFF_FN);
//}