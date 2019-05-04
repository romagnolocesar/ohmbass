#include "OhmBass.h"
#include "graphicsManager.h"
#include "controlsManager.h"
#include "VectorLib.h"


void graphicsManager::attachBackgroundMainDisplay()
{
	//background
	pGraphics->AttachBackground(BG_ID, BG_FN);
};

void graphicsManager::loadCommonsBitmaps() {
	char* name = "KNOB_MEDIUM";
	IBitmap myBitmap = pGraphics->LoadIBitmap(KNOB_MEDIUM_ID, KNOB_MEDIUM_FN, 47);
	tCommonsBitmaps<char*, IBitmap> knobMedium = tCommonsBitmaps(name, myBitmap);
	this->mknobMedium = AddCommonsBitmapsCollection(knobMedium);

	name = "KNOB_MEDIUM";
	myBitmap = pGraphics->LoadIBitmap(KNOB_MEDIUM_PARAM_ID, KNOB_MEDIUM_PARAM_FN, 10);
	tCommonsBitmaps<char*, IBitmap> knobMediumParam = tCommonsBitmaps(name, myBitmap);
	this->mknobMediumParam = AddCommonsBitmapsCollection(knobMediumParam);
};

IBitmap graphicsManager::getBitmapFromCommonsColletion(int idxBitmap) {
	return this->commonsBitmapsCollection[idxBitmap].bitmap;
};

int graphicsManager::AddCommonsBitmapsCollection(tCommonsBitmaps<char*, IBitmap> myInstance)
{
	this->commonsBitmapsCollection.push_back(myInstance);
	return (this->commonsBitmapsCollection.size() - 1);
};


void graphicsManager::loadKeyboard()
{
	//keybooards
	this->whiteKeyImage = pGraphics->LoadIBitmap(WHITE_KEY_ID, WHITE_KEY_FN, 6);
	this->blackKeyImage = pGraphics->LoadIBitmap(BLACK_KEY_ID, BLACK_KEY_FN);
}
//
//void graphicsManager::loadOscWavesModes()
//{
//	this->waveformBitmap = pGraphics->LoadIBitmap(WAVEFORM_ID, WAVEFORM_FN, 4);
//}
//
//void graphicsManager::loadFiltersModes()
//{
//	this->filterModeBitmap = pGraphics->LoadIBitmap(FILTERMODE_ID, FILTERMODE_FN, 3);
//}
//
//void graphicsManager::loadKnobs()
//{
//	this->knobBitmap = pGraphics->LoadIBitmap(KNOB_MEDIUM_ID, KNOB_MEDIUM, 47);
//}
//
//void graphicsManager::loadFaders()
//{
//	//Faders
//	this->fadersHandlerOnOsc1 = pGraphics->LoadIBitmap(FADERHANDLERON_ID, FADERHANDLERON_FN);
//	this->fadersHandlerOnOsc2 = pGraphics->LoadIBitmap(FADERHANDLERON_ID, FADERHANDLERON_FN);
//	this->fadersHandlerOffOsc1 = pGraphics->LoadIBitmap(FADERHANDLEROFF_ID, FADERHANDLEROFF_FN);
//	this->fadersHandlerOffOsc2 = pGraphics->LoadIBitmap(FADERHANDLEROFF_ID, FADERHANDLEROFF_FN);
//	//Glows
//	this->faderGlowBarOsc1 = pGraphics->LoadIBitmap(FADERGLOW_ID, FADERGLOW_FN);
//	this->faderGlowBarOsc2 = pGraphics->LoadIBitmap(FADERGLOW_ID, FADERGLOW_FN);
//}
//
//
//
//
//void graphicsManager::loadOscWavesButtonsBackgrounds()
//{
//	this->bgBtnOscWavesOsc1 = pGraphics->LoadIBitmap(BGBTNOSCWAVES_ID, BGBTNOSCWAVES_FN, 2);
//	this->bgBtnOscWavesOsc2 = pGraphics->LoadIBitmap(BGBTNOSCWAVES_ID, BGBTNOSCWAVES_FN, 2);
//}
//
//void graphicsManager::loadGhrrEqlControls() {
//	this->knobGhrTab1 = pGraphics->LoadIBitmap(GHRRTAB1_ID, GHRRTAB1_FN);
//	this->knobGhrEqlTitleOn = pGraphics->LoadIBitmap();
//	this->knobGhrEqlLow = pGraphics->LoadIBitmap(KNOB_MEDIUM_PARAM_ID, KNOB_MEDIUM_PARAM_FN, 10);
//	this->knobGhrEqlBost = pGraphics->LoadIBitmap(KNOB_MEDIUM_PARAM_ID, KNOB_MEDIUM_PARAM_FN, 10);
//	this->knobGhrEqlHihg = pGraphics->LoadIBitmap(KNOB_MEDIUM_PARAM_ID, KNOB_MEDIUM_PARAM_FN, 10);
//	this->knobGhrEqlShelf = pGraphics->LoadIBitmap(KNOB_MEDIUM_PARAM_ID, KNOB_MEDIUM_PARAM_FN, 10);
//}

//void graphicsManager::attachGraphicsInControls(IPlug* myOhmBass,controlsManager* iControlsManager)
//{
//	for (int i = 0; i < iControlsManager->kNumParams; i++) {
//		controlsManager::parameterProperties_struct properties = iControlsManager->getParameterProperties(i);
//		IParam* param = myOhmBass->GetParam(i);
//		IBitmap* graphic;
//		switch (i) {
//			//Buttons Waves
//		case controlsManager::mBgBtnOscWavesOsc1:
//			graphic = &bgBtnOscWavesOsc1;
//			iControlsManager->control = new IRadioButtonsControl(myOhmBass, IRECT(43, 206, 43 + (56 * 4), 56 + (60 * 4)), i, 4, graphic, kHorizontal);
//			break;
//		case controlsManager::mBgBtnOscWavesOsc2:
//			graphic = &bgBtnOscWavesOsc2;
//			iControlsManager->control = new IRadioButtonsControl(myOhmBass, IRECT(43, 306, 43 + (56 * 4), 126 + (60 * 4)), i, 4, graphic, kHorizontal);
//			break;
//
//			//Faders Oscillators
//		case controlsManager::mFadersHandlerOffOsc1:
//			graphic = &fadersHandlerOffOsc1;
//			iControlsManager->Osc1FaderHandlerOff = new IFaderControl(myOhmBass, properties.x, properties.y, 210, i, graphic, EDirection::kVertical);
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
//	
//			//LFO
//		case iControlsManager->mLFOWaveform:
//			graphic = &waveformBitmap;
//			iControlsManager->control = new ISwitchControl(myOhmBass, properties.x, properties.y, i, graphic);
//			break;
//		case iControlsManager->mFilterMode:
//			graphic = &filterModeBitmap;
//			iControlsManager->control = new ISwitchControl(myOhmBass, properties.x, properties.y, i, graphic);
//			break;
//		//GHRR PLACE
//			//Eq-Librium
//		case iControlsManager->mGhrtab1:
//			graphic = &knobGhrTab1;
//			iControlsManager->control = new IBitmapControl(myOhmBass, properties.x, properties.y, i, graphic);
//			break;
//		case iControlsManager->mGhrEqlOnTitle:
//			graphic = &knobGhrEqlTitleOn;
//			iControlsManager->control = new IKnobMultiControl(myOhmBass, properties.x, properties.y, i, graphic);
//			break;
//		case iControlsManager->mGhrEqlLowFreq:
//			graphic = &knobGhrEqlLow;
//			iControlsManager->control = new IKnobMultiControl(myOhmBass, properties.x, properties.y, i, graphic);
//			break;
//		case iControlsManager->mGhrBostLowFreq:
//			graphic = &knobGhrEqlBost;
//			iControlsManager->control = new IKnobMultiControl(myOhmBass, properties.x, properties.y, i, graphic);
//			break;
//		case iControlsManager->mGhrEqlHihgFreq:
//			graphic = &knobGhrEqlHihg;
//			iControlsManager->control = new IKnobMultiControl(myOhmBass, properties.x, properties.y, i, graphic);
//			break;
//		case iControlsManager->mGhrShelfHihgFreq:
//			graphic = &knobGhrEqlShelf;
//			iControlsManager->control = new IKnobMultiControl(myOhmBass, properties.x, properties.y, i, graphic);
//			break;
//			// Knobs:
//		default:
//			graphic = &knobBitmap;
//			iControlsManager->control = new IKnobMultiControl(myOhmBass, properties.x, properties.y, i, graphic);
//			break;
//		}
//		if (
//			i != iControlsManager->mIconSineWaveOnOsc1 &&
//			i != iControlsManager->mIconSawWaveOnOsc1 &&
//			i != iControlsManager->mIconSqWaveOnOsc1 &&
//			i != iControlsManager->mIconTriangleWaveOnOsc1 &&
//			i != iControlsManager->mIconSineWaveOnOsc2 &&
//			i != iControlsManager->mIconSawWaveOnOsc2 &&
//			i != iControlsManager->mIconSqWaveOnOsc2 &&
//			i != iControlsManager->mIconTriangleWaveOnOsc2 &&
//			i != iControlsManager->mFadersHandlerOffOsc1 &&
//			i != iControlsManager->mFadersHandlerOffOsc2 &&
//			i != iControlsManager->mFadersHandlerOnOsc1 &&
//			i != iControlsManager->mFadersHandlerOnOsc2 &&
//			i != iControlsManager->mFadersGlowOsc1 &&
//			i != iControlsManager->mFadersGlowOsc2) {
//			pGraphics->AttachControl(iControlsManager->control);
//		}
//
//	}
//}


