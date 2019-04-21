#include "OhmBass.h"
#include "controlsManager.h"




graphicsManager::graphicsManager()
{
}


graphicsManager::~graphicsManager()
{
}

void graphicsManager::AttachBackgroundMainDisplay()
{
	//background
	pGraphics->AttachBackground(BG_ID, BG_FN);
}

void graphicsManager::loadKeyboard()
{
	//keybooards
	this->whiteKeyImage = pGraphics->LoadIBitmap(WHITE_KEY_ID, WHITE_KEY_FN, 6);
	this->blackKeyImage = pGraphics->LoadIBitmap(BLACK_KEY_ID, BLACK_KEY_FN);
}

void graphicsManager::loadOscWavesModes()
{
	this->waveformBitmap = pGraphics->LoadIBitmap(WAVEFORM_ID, WAVEFORM_FN, 4);
}

void graphicsManager::loadFiltersModes()
{
	this->filterModeBitmap = pGraphics->LoadIBitmap(FILTERMODE_ID, FILTERMODE_FN, 3);
}

void graphicsManager::loadKnobs()
{
	this->knobBitmap = pGraphics->LoadIBitmap(KNOB_MEDIUM_ID, KNOB_MEDIUM, 47);
}

void graphicsManager::loadWavesIcons()
{
	this->iconSineWaveOnOsc1 = pGraphics->LoadIBitmap(ICONSINEWAVEON_ID, ICONSINEWAVEON_FN);
	this->iconSineWaveOffOsc1 = pGraphics->LoadIBitmap(ICONSINEWAVEOFF_ID, ICONSINEWAVEOFF_FN);
	this->iconSawWaveOnOsc1 = pGraphics->LoadIBitmap(ICONSAWWAVEON_ID, ICONSAWWAVEON_FN);
	this->iconSawWaveOffOsc1 = pGraphics->LoadIBitmap(ICONSAWWAVEOFF_ID, ICONSAWWAVEOFF_FN);
	this->iconSquareWaveOnOsc1 = pGraphics->LoadIBitmap(ICONSQUAREWAVEON_ID, ICONSQUAREWAVEON_FN);
	this->iconSquareWaveOffOsc1 = pGraphics->LoadIBitmap(ICONSQUAREWAVEOFF_ID, ICONSQUAREWAVEOFF_FN);
	this->iconTriangleWaveOnOsc1 = pGraphics->LoadIBitmap(ICONTRIANGLEWAVEON_ID, ICONTRIANGLEWAVEON_FN);
	this->iconTriangleWaveOffOsc1 = pGraphics->LoadIBitmap(ICONTRIANGLEWAVEOFF_ID, ICONTRIANGLEWAVEOFF_FN);
	this->iconSineWaveOnOsc2 = pGraphics->LoadIBitmap(ICONSINEWAVEON_ID, ICONSINEWAVEON_FN);
	this->iconSineWaveOffOsc2 = pGraphics->LoadIBitmap(ICONSINEWAVEOFF_ID, ICONSINEWAVEOFF_FN);
	this->iconSawWaveOnOsc2 = pGraphics->LoadIBitmap(ICONSAWWAVEON_ID, ICONSAWWAVEON_FN);
	this->iconSawWaveOffOsc2 = pGraphics->LoadIBitmap(ICONSAWWAVEOFF_ID, ICONSAWWAVEOFF_FN);
	this->iconSquareWaveOnOsc2 = pGraphics->LoadIBitmap(ICONSQUAREWAVEON_ID, ICONSQUAREWAVEON_FN);
	this->iconSquareWaveOffOsc2 = pGraphics->LoadIBitmap(ICONSQUAREWAVEOFF_ID, ICONSQUAREWAVEOFF_FN);
	this->iconTriangleWaveOnOsc2 = pGraphics->LoadIBitmap(ICONTRIANGLEWAVEON_ID, ICONTRIANGLEWAVEON_FN);
	this->iconTriangleWaveOffOsc2 = pGraphics->LoadIBitmap(ICONTRIANGLEWAVEOFF_ID, ICONTRIANGLEWAVEOFF_FN);
}

void graphicsManager::loadOscWavesButtonsBackgrounds()
{
	this->bgBtnOscWavesOsc1 = pGraphics->LoadIBitmap(BGBTNOSCWAVES_ID, BGBTNOSCWAVES_FN, 2);
	this->bgBtnOscWavesOsc2 = pGraphics->LoadIBitmap(BGBTNOSCWAVES_ID, BGBTNOSCWAVES_FN, 2);
}

void graphicsManager::attachGraphicsInControls(IPlug* myOhmBass,controlsManager* iControlsManager)
{
	for (int i = 0; i < iControlsManager->getKNumParams(); i++) {
		controlsManager::parameterProperties_struct properties = iControlsManager->getParameterProperties(i);
		IParam* param = myOhmBass->GetParam(i);
		IBitmap* graphic;
		switch (i) {
			//Buttons Waves
		case controlsManager::mBgBtnOscWavesOsc1:
			graphic = &bgBtnOscWavesOsc1;
			iControlsManager->control = new IRadioButtonsControl(myOhmBass, IRECT(43, 206, 43 + (56 * 4), 56 + (60 * 4)), i, 4, graphic, kHorizontal);
			break;
		case controlsManager::mBgBtnOscWavesOsc2:
			graphic = &bgBtnOscWavesOsc2;
			iControlsManager->control = new IRadioButtonsControl(myOhmBass, IRECT(43, 306, 43 + (56 * 4), 126 + (60 * 4)), i, 4, graphic, kHorizontal);
			break;
			//Osc1 Icons Buttons Waves
		case controlsManager::mIconSineWaveOffOsc1:
			graphic = &iconSineWaveOffOsc1;
			iControlsManager->control = new IBitmapControl(myOhmBass, properties.x, properties.y, i, graphic);
			iControlsManager->control->Hide(!properties.defaultVal);
			iControlsManager->control->GrayOut(TRUE, 0.99f);
			break;
		case controlsManager::mIconSineWaveOnOsc1:
			graphic = &iconSineWaveOnOsc1;
			iControlsManager->Osc1ControlSineOn = new IBitmapControl(myOhmBass, properties.x, properties.y, i, graphic);
			iControlsManager->Osc1ControlSineOn->Hide(!properties.defaultVal);
			iControlsManager->Osc1ControlSineOn->GrayOut(TRUE, 0.99f);
			pGraphics->AttachControl(iControlsManager->Osc1ControlSineOn);
			break;
		case iControlsManager->mIconSawWaveOffOsc1:
			graphic = &iconSawWaveOffOsc1;
			iControlsManager->control = new IBitmapControl(myOhmBass, properties.x, properties.y, i, graphic);
			iControlsManager->control->Hide(!properties.defaultVal);
			iControlsManager->control->GrayOut(TRUE, 0.99f);
			break;
		case iControlsManager->mIconSawWaveOnOsc1:
			graphic = &iconSawWaveOnOsc1;
			iControlsManager->Osc1ControlSawOn = new IBitmapControl(myOhmBass, properties.x, properties.y, i, graphic);
			iControlsManager->Osc1ControlSawOn->Hide(!properties.defaultVal);
			iControlsManager->Osc1ControlSawOn->GrayOut(TRUE, 0.99f);
			pGraphics->AttachControl(iControlsManager->Osc1ControlSawOn);
			break;
		case iControlsManager->mIconSqWaveOffOsc1:
			graphic = &iconSquareWaveOffOsc1;
			iControlsManager->control = new IBitmapControl(myOhmBass, properties.x, properties.y, i, graphic);
			iControlsManager->control->Hide(!properties.defaultVal);
			iControlsManager->control->GrayOut(TRUE, 0.99f);
			break;
		case iControlsManager->mIconSqWaveOnOsc1:
			graphic = &iconSquareWaveOnOsc1;
			iControlsManager->Osc1ControlSquareOn = new IBitmapControl(myOhmBass, properties.x, properties.y, i, graphic);
			iControlsManager->Osc1ControlSquareOn->Hide(!properties.defaultVal);
			iControlsManager->Osc1ControlSquareOn->GrayOut(TRUE, 0.99f);
			pGraphics->AttachControl(iControlsManager->Osc1ControlSquareOn);
			break;
		case iControlsManager->mIconTriangleWaveOffOsc1:
			graphic = &iconTriangleWaveOffOsc1;
			iControlsManager->control = new IBitmapControl(myOhmBass, properties.x, properties.y, i, graphic);
			iControlsManager->control->Hide(!properties.defaultVal);
			iControlsManager->control->GrayOut(TRUE, 0.99f);
			break;
		case iControlsManager->mIconTriangleWaveOnOsc1:
			graphic = &iconTriangleWaveOnOsc1;
			iControlsManager->Osc1ControlTriagleOn = new IBitmapControl(myOhmBass, properties.x, properties.y, i, graphic);
			iControlsManager->Osc1ControlTriagleOn->Hide(!properties.defaultVal);
			iControlsManager->Osc1ControlTriagleOn->GrayOut(TRUE, 0.99f);
			pGraphics->AttachControl(iControlsManager->Osc1ControlTriagleOn);
			break;
			//Osc2 Icons Buttons Waves
		case iControlsManager->mIconSineWaveOffOsc2:
			graphic = &iconSineWaveOffOsc2;
			iControlsManager->control = new IBitmapControl(myOhmBass, properties.x, properties.y, i, graphic);
			iControlsManager->control->Hide(!properties.defaultVal);
			iControlsManager->control->GrayOut(TRUE, 0.99f);
			break;
		case iControlsManager->mIconSineWaveOnOsc2:
			graphic = &iconSineWaveOnOsc2;
			iControlsManager->Osc2ControlSineOn = new IBitmapControl(myOhmBass, properties.x, properties.y, i, graphic);
			iControlsManager->Osc2ControlSineOn->Hide(!properties.defaultVal);
			iControlsManager->Osc2ControlSineOn->GrayOut(TRUE, 0.99f);
			pGraphics->AttachControl(iControlsManager->Osc2ControlSineOn);
			break;
		case iControlsManager->mIconSawWaveOffOsc2:
			graphic = &iconSawWaveOffOsc2;
			iControlsManager->control = new IBitmapControl(myOhmBass, properties.x, properties.y, i, graphic);
			iControlsManager->control->SetBlendMethod(IChannelBlend::EBlendMethod::kBlendColorDodge);
			iControlsManager->control->Hide(!properties.defaultVal);
			iControlsManager->control->GrayOut(TRUE, 0.99f);
			break;
		case iControlsManager->mIconSawWaveOnOsc2:
			graphic = &iconSawWaveOnOsc2;
			iControlsManager->Osc2ControlSawOn = new IBitmapControl(myOhmBass, properties.x, properties.y, i, graphic);
			iControlsManager->Osc2ControlSawOn->SetBlendMethod(IChannelBlend::EBlendMethod::kBlendColorDodge);
			iControlsManager->Osc2ControlSawOn->Hide(!properties.defaultVal);
			iControlsManager->Osc2ControlSawOn->GrayOut(TRUE, 0.99f);
			pGraphics->AttachControl(iControlsManager->Osc2ControlSawOn);
			break;
		case iControlsManager->mIconSqWaveOffOsc2:
			graphic = &iconSquareWaveOffOsc2;
			iControlsManager->control = new IBitmapControl(myOhmBass, properties.x, properties.y, i, graphic);
			iControlsManager->control->SetBlendMethod(IChannelBlend::EBlendMethod::kBlendColorDodge);
			iControlsManager->control->Hide(!properties.defaultVal);
			iControlsManager->control->GrayOut(TRUE, 0.99f);
			break;
		case iControlsManager->mIconSqWaveOnOsc2:
			graphic = &iconSquareWaveOnOsc2;
			iControlsManager->Osc2ControlSquareOn = new IBitmapControl(myOhmBass, properties.x, properties.y, i, graphic);
			iControlsManager->Osc2ControlSquareOn->SetBlendMethod(IChannelBlend::EBlendMethod::kBlendColorDodge);
			iControlsManager->Osc2ControlSquareOn->Hide(!properties.defaultVal);
			iControlsManager->Osc2ControlSquareOn->GrayOut(TRUE, 0.99f);
			pGraphics->AttachControl(iControlsManager->Osc2ControlSquareOn);
			break;
		case iControlsManager->mIconTriangleWaveOffOsc2:
			graphic = &iconTriangleWaveOffOsc2;
			iControlsManager->control = new IBitmapControl(myOhmBass, properties.x, properties.y, i, graphic);
			iControlsManager->control->SetBlendMethod(IChannelBlend::EBlendMethod::kBlendColorDodge);
			iControlsManager->control->Hide(!properties.defaultVal);
			iControlsManager->control->GrayOut(TRUE, 0.99f);
			break;
		case iControlsManager->mIconTriangleWaveOnOsc2:
			graphic = &iconTriangleWaveOnOsc2;
			iControlsManager->Osc2ControlTriagleOn = new IBitmapControl(myOhmBass, properties.x, properties.y, i, graphic);
			iControlsManager->Osc2ControlTriagleOn->SetBlendMethod(IChannelBlend::EBlendMethod::kBlendColorDodge);
			iControlsManager->Osc2ControlTriagleOn->Hide(!properties.defaultVal);
			iControlsManager->Osc2ControlTriagleOn->GrayOut(TRUE, 0.99f);
			pGraphics->AttachControl(iControlsManager->Osc2ControlTriagleOn);
			break;
			//LFO
		case iControlsManager->mLFOWaveform:
			graphic = &waveformBitmap;
			iControlsManager->control = new ISwitchControl(myOhmBass, properties.x, properties.y, i, graphic);
			break;
		case iControlsManager->mFilterMode:
			graphic = &filterModeBitmap;
			iControlsManager->control = new ISwitchControl(myOhmBass, properties.x, properties.y, i, graphic);
			break;
			// Knobs:
		default:
			graphic = &knobBitmap;
			iControlsManager->control = new IKnobMultiControl(myOhmBass, properties.x, properties.y, i, graphic);
			break;
		}
		if (
			i != iControlsManager->mIconSineWaveOnOsc1 &&
			i != iControlsManager->mIconSawWaveOnOsc1 &&
			i != iControlsManager->mIconSqWaveOnOsc1 &&
			i != iControlsManager->mIconTriangleWaveOnOsc1 &&
			i != iControlsManager->mIconSineWaveOnOsc2 &&
			i != iControlsManager->mIconSawWaveOnOsc2 &&
			i != iControlsManager->mIconSqWaveOnOsc2 &&
			i != iControlsManager->mIconTriangleWaveOnOsc2) {
			pGraphics->AttachControl(iControlsManager->control);
		}

	}
}

