#include "ModConfLfo.h"
#include "Oscillator.h"



ModConfLfo::ModConfLfo()
{
}


ModConfLfo::~ModConfLfo()
{
}

void ModConfLfo::init(controlsManager* IControlsManager, graphicsManager* IGraphicsManager) {
	ControlsModel* myControl;

	//&&&&&&&&&&&&&&&& MODAL &&&&&&&&&&&&&&&&&&&&&&&&&&&&&
	//BOX
	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(MODAL_MEDIUM_ONE_ID, MODAL_MEDIUM_ONE_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::NONE, "Modal Box", 236, 190, 0, 0, iGraphic, TRUE);
	myControl->setGroupName("modal_conflfo");
	IControlsManager->AddModelsCollection(myControl);

	//Title
	graphicType = GraphicsModel::TEXT;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "MODAL LFO TITLE", 236, 207, 236 + 80, 207 + 30, "LFOs", iGraphic, 17);
	myControl->setGroupName("modal_conflfo");
	IControlsManager->AddModelsCollection(myControl);

	//CLOSE BUTTON
	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(MODAL_CLOSE_ICON_ID, MODAL_CLOSE_ICON_FN);
	graphicType = GraphicsModel::SWITCHCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::ENUM, "Modal Close Icon", 763, 210, 0, 0, iGraphic);
	myControl->setGroupName("modal_conflfo");
	IControlsManager->AddModelsCollection(myControl);

	//&&&&&&&&&&&&&&&& OSC 1 &&&&&&&&&&&&&&&&&&&&&&&&&&&&&
	//Title
	graphicType = GraphicsModel::TEXT;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "MODAL LFO TITLE OSC 1", 270, 250, 270 + 80, 250 + 30, "OSCILLATOR 1", iGraphic, 15);
	myControl->setGroupName("modal_conflfo");
	IControlsManager->AddModelsCollection(myControl);
	//Wave Mode
	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(WAVEFORM_ID, WAVEFORM_FN, 4);
	graphicType = GraphicsModel::SWITCHCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::ENUM, "LFO Waveform OSC 1", 270, 290, Oscillator::OSCILLATOR_MODE_TRIANGLE, Oscillator::kNumOscillatorModes, iGraphic);
	myControl->setGroupName("modal_conflfo");
	IControlsManager->AddModelsCollection(myControl);

	//Wave Mode Label
	graphicType = GraphicsModel::TEXT;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "LFO Waveform OSC 1 Label", 250, 340, 250+80, 340+30, "WAVE STYLE", iGraphic, 12);
	myControl->setGroupName("modal_conflfo");
	IControlsManager->AddModelsCollection(myControl);

	//Frequency
	iGraphic = new GraphicsModel(IGraphicsManager->getBitmapFromCommonsColletion(IGraphicsManager->mknobMedium),GraphicsModel::KNOBMULTICONTROL);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "LFO Frequency OSC 1", 350, 270, 6.0, 0.01, 30.0, iGraphic);
	myControl->setGroupName("modal_conflfo");
	IControlsManager->AddModelsCollection(myControl);

	//Frequency Mode Label
	graphicType = GraphicsModel::TEXT;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "LFO Frequency OSC 1 Label", 340, 340, 340 + 80, 340 + 30, "FREQUENCY", iGraphic, 12);
	myControl->setGroupName("modal_conflfo");
	IControlsManager->AddModelsCollection(myControl);

	//Sync Button 
	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(BUTTON_GLOW_ID, BUTTON_GLOW_FN, 2);
	graphicType = GraphicsModel::SWITCHCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::ENUM, "Sync Button Osc 1", 420, 280, ModulesModel::OFF, ModulesModel::kNumModulesOnOff, iGraphic);
	myControl->setGroupName("modal_conflfo");
	IControlsManager->AddModelsCollection(myControl);

	//Sync Button Label
	graphicType = GraphicsModel::TEXT;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "Sync Button Osc 1 Label", 440, 280, 440 + 40, 280 + 30, "SYNC", iGraphic, 10);
	myControl->setGroupName("modal_conflfo");
	IControlsManager->AddModelsCollection(myControl);

	//Sync Options
	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(SELECT_BOX_ONE_ID, SELECT_BOX_ONE_FN, 2);
	graphicType = GraphicsModel::SWITCHCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::ENUM, "Sync Options Osc 1", 425, 300, ModulesModel::OFF, ModulesModel::kNumModulesOnOff, iGraphic);
	myControl->setGroupName("modal_conflfo");
	IControlsManager->AddModelsCollection(myControl);

	//Pitch Amount
	iGraphic = new GraphicsModel(IGraphicsManager->getBitmapFromCommonsColletion(IGraphicsManager->mknobMedium), GraphicsModel::KNOBMULTICONTROL);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "Osc 1 Pitch Mod", 580, 270, 0.0, 0.0, 1.0, iGraphic);
	myControl->setGroupName("modal_conflfo");
	IControlsManager->AddModelsCollection(myControl);

	//Pitch Amount Label
	graphicType = GraphicsModel::TEXT;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "Osc 1 Pitch Mod Label", 570, 340, 570 + 80, 340 + 30, "PITCH AMOUNT", iGraphic, 12);
	myControl->setGroupName("modal_conflfo");
	IControlsManager->AddModelsCollection(myControl);

	//&&&&&&&&&&&&&&&& OSC 2 &&&&&&&&&&&&&&&&&&&&&&&&&&&&&
	//Title
	graphicType = GraphicsModel::TEXT;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "MODAL LFO TITLE OSC 2", 270, 380, 270 + 100, 380 + 30, "OSCILLATOR 2", iGraphic, 15);
	myControl->setGroupName("modal_conflfo");
	IControlsManager->AddModelsCollection(myControl);
	//Wave Mode
	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(WAVEFORM_ID, WAVEFORM_FN, 4);
	graphicType = GraphicsModel::SWITCHCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::ENUM, "LFO Waveform OSC 2", 270, 420, Oscillator::OSCILLATOR_MODE_TRIANGLE, Oscillator::kNumOscillatorModes, iGraphic);
	myControl->setGroupName("modal_conflfo");
	IControlsManager->AddModelsCollection(myControl);

	//Wave Mode Label
	graphicType = GraphicsModel::TEXT;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "LFO Waveform OSC 2 Label", 250, 470, 250 + 80, 470 + 30, "WAVE STYLE", iGraphic, 12);
	myControl->setGroupName("modal_conflfo");
	IControlsManager->AddModelsCollection(myControl);

	//Frequency
	iGraphic = new GraphicsModel(IGraphicsManager->getBitmapFromCommonsColletion(IGraphicsManager->mknobMedium), GraphicsModel::KNOBMULTICONTROL);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "LFO Frequency OSC 2", 350, 400, 6.0, 0.01, 30.0, iGraphic);
	myControl->setGroupName("modal_conflfo");
	IControlsManager->AddModelsCollection(myControl);

	//Frequency Mode Label
	graphicType = GraphicsModel::TEXT;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "LFO Frequency OSC 2 Label", 340, 470, 340 + 80, 470 + 30, "FREQUENCY", iGraphic, 12);
	myControl->setGroupName("modal_conflfo");
	IControlsManager->AddModelsCollection(myControl);

	//Pitch Amount
	iGraphic = new GraphicsModel(IGraphicsManager->getBitmapFromCommonsColletion(IGraphicsManager->mknobMedium), GraphicsModel::KNOBMULTICONTROL);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "Osc 2 Pitch Mod", 580, 400, 0.0, 0.0, 1.0, iGraphic);
	myControl->setGroupName("modal_conflfo");
	IControlsManager->AddModelsCollection(myControl);

	//Pitch Amount Label
	graphicType = GraphicsModel::TEXT;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "Osc 2 Pitch Mod Label", 570, 470, 570 + 80, 470 + 30, "PITCH AMOUNT", iGraphic, 12);
	myControl->setGroupName("modal_conflfo");
	IControlsManager->AddModelsCollection(myControl);


	//&&&&&&&&&&&&&&&& FILTER AB &&&&&&&&&&&&&&&&&&&&&&&&&&&&&
	//Title
	graphicType = GraphicsModel::TEXT;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "MODAL LFO TITLE FILTER AB", 270, 510, 270 + 45, 510 + 30, "FILTER AB", iGraphic, 15);
	myControl->setGroupName("modal_conflfo");
	IControlsManager->AddModelsCollection(myControl);
	//Wave Mode
	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(WAVEFORM_ID, WAVEFORM_FN, 4);
	graphicType = GraphicsModel::SWITCHCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::ENUM, "LFO Waveform Filter AB", 270, 550, Oscillator::OSCILLATOR_MODE_TRIANGLE, Oscillator::kNumOscillatorModes, iGraphic);
	myControl->setGroupName("modal_conflfo");
	IControlsManager->AddModelsCollection(myControl);

	//Wave Mode Label
	graphicType = GraphicsModel::TEXT;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "LFO Waveform Filter AB Label", 250, 600, 250 + 80, 600 + 30, "WAVE STYLE", iGraphic, 12);
	myControl->setGroupName("modal_conflfo");
	IControlsManager->AddModelsCollection(myControl);

	//Frequency
	iGraphic = new GraphicsModel(IGraphicsManager->getBitmapFromCommonsColletion(IGraphicsManager->mknobMedium), GraphicsModel::KNOBMULTICONTROL);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "LFO Frequency Filter AB", 350, 530, 6.0, 0.01, 30.0, iGraphic);
	myControl->setGroupName("modal_conflfo");
	IControlsManager->AddModelsCollection(myControl);

	//Frequency Mode Label
	graphicType = GraphicsModel::TEXT;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "LFO Frequency Filter AB Label", 340, 600, 340 + 80, 600 + 30, "FREQUENCY", iGraphic, 12);
	myControl->setGroupName("modal_conflfo");
	IControlsManager->AddModelsCollection(myControl);

	//Filter AB Amount
	iGraphic = new GraphicsModel(IGraphicsManager->getBitmapFromCommonsColletion(IGraphicsManager->mknobMedium), GraphicsModel::KNOBMULTICONTROL);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "Filter AB LFO Amount", 580, 530, 0.0, 0.0, 1.0, iGraphic);
	myControl->setGroupName("modal_conflfo");
	IControlsManager->AddModelsCollection(myControl);

	//Pitch Amount Label
	graphicType = GraphicsModel::TEXT;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "Filter AB LFO Amount Label", 570, 600, 570 + 80, 600 + 30, "FILTER AMOUNT", iGraphic, 12);
	myControl->setGroupName("modal_conflfo");
	IControlsManager->AddModelsCollection(myControl);

	

}

void ModConfLfo::doModelsControlsInIControlsCollection(IPlug* myOhmBass, controlsManager* iControlsManager, graphicsManager* iGraphicsManager, int i) {
	IBitmap graphic = iControlsManager->controlsModelsCollection[i]->graphicsModel->bitmap;
	IControl * control;
	IColor * color;

	switch (iControlsManager->controlsModelsCollection[i]->graphicsModel->graphicsType) {
	case GraphicsModel::SWITCHCONTROL:
		control = new ISwitchControl(myOhmBass, iControlsManager->controlsModelsCollection[i]->x, iControlsManager->controlsModelsCollection[i]->y, i, &graphic);
		break;
	case GraphicsModel::KNOBMULTICONTROL:
		control = new IKnobMultiControl(myOhmBass, iControlsManager->controlsModelsCollection[i]->x, iControlsManager->controlsModelsCollection[i]->y, i, &graphic);
		break;
	case GraphicsModel::BITMAPCONTROL:
		control = new IBitmapControl(myOhmBass, iControlsManager->controlsModelsCollection[i]->x, iControlsManager->controlsModelsCollection[i]->y, i, &graphic);
		control->Hide(iControlsManager->controlsModelsCollection[i]->hide);
		control->GrayOut(iControlsManager->controlsModelsCollection[i]->hide);
		break;
	case GraphicsModel::TEXT:
		IRECT pR;
		pR.L = iControlsManager->controlsModelsCollection[i]->L;
		pR.T = iControlsManager->controlsModelsCollection[i]->T;
		pR.R = iControlsManager->controlsModelsCollection[i]->R;
		pR.B = iControlsManager->controlsModelsCollection[i]->B;
		color = new IColor(255, 255, 255, 255);
		IText pText(color);
		pText.mSize = iControlsManager->controlsModelsCollection[i]->textSize;
		pText.mStyle = IText::EStyle::kStyleBold;

		control = new ITextControl(myOhmBass, pR, &pText, iControlsManager->controlsModelsCollection[i]->pText);
		control->Hide(iControlsManager->controlsModelsCollection[i]->hide);
		control->GrayOut(iControlsManager->controlsModelsCollection[i]->hide);
		break;
	}
	control->GrayOut(TRUE);
	control->Hide(TRUE);
	iControlsManager->AddControlsCollection(control);
	iGraphicsManager->pGraphics->AttachControl(control);
}


//void ModConfLfo::createModalBox(IPlug * myOhmBass, IGraphics * pGraphics, int w, int h)
//{
//	IRECT pRect;
//	pRect.L = ((1024 / 2) - (w / 2));
//	pRect.T = ((768 / 2) - (h / 2));
//	pRect.R = ((1024 / 2) + (w / 2));
//	pRect.B = ((768 / 2) + (h / 2));
//
//	this->modalBoxConfLfo = new IModalBox(myOhmBass, pRect, w, h);
//
//	pGraphics->AttachControl(this->modalBoxConfLfo);
//}
//
//

//Hide Frequency Knob
void ModConfLfo::showLFOFrequency(controlsManager* iControlsManager, int lfoNumber)
{
	IParam * param;
	if (lfoNumber == 1) {
		IControl * element;
		element = iControlsManager->controlsCollection[frequencyKnobLFO1];
		element->GrayOut(FALSE);
	}
	else if (lfoNumber == 2) {
		IControl * element;
		element = iControlsManager->controlsCollection[frequencyKnobLFO2];
		element->GrayOut(FALSE);
	}
	else if (lfoNumber == 3) {
		IControl * element;
		element = iControlsManager->controlsCollection[frequencyKnobLFO3];
		element->GrayOut(FALSE);
	}
}

//Hide Frequency Knob
void ModConfLfo::hideLFOFrequency(controlsManager* iControlsManager, int lfoNumber)
{
	IParam * param;
	if (lfoNumber == 1) {
		IControl * element;
		element = iControlsManager->controlsCollection[frequencyKnobLFO1];
		element->GrayOut(TRUE);
	}
	else if (lfoNumber == 2) {
		IControl * element;
		element = iControlsManager->controlsCollection[frequencyKnobLFO2];
		element->GrayOut(TRUE);
	}
	else if (lfoNumber == 3) {
		IControl * element;
		element = iControlsManager->controlsCollection[frequencyKnobLFO3];
		element->GrayOut(TRUE);
	}
}

//Show ModalBackground
void ModConfLfo::showModalBox(controlsManager* iControlsManager)
{
	for (int i = 0; i < iControlsManager->wrapperControlsAndGroupsCollection.find("modal_conflfo")->second.size(); i++) {
		IControl * element;
		element = iControlsManager->wrapperControlsAndGroupsCollection.find("modal_conflfo")->second.at(i);
		element->GrayOut(FALSE);
		element->Hide(FALSE);
	}
}


//Hide ModalBackground
void ModConfLfo::hideModalBox(controlsManager* iControlsManager)
{
	for (int i = 0; i < iControlsManager->wrapperControlsAndGroupsCollection.find("modal_conflfo")->second.size(); i++) {
		IControl * element;
		element = iControlsManager->wrapperControlsAndGroupsCollection.find("modal_conflfo")->second.at(i);
		element->GrayOut(TRUE);
		element->Hide(TRUE);
	}
}

void ModConfLfo::fillAuxParams(controlsManager* iControlsManager) {
	for (int i = 0; i < iControlsManager->getKNumParams(); i++) {
		IParam * param;
		param = iControlsManager->controlsCollection[i]->GetParam();
		if (param != nullptr) {
			if (strcmp(param->GetNameForHost(), "Osc 1 Pitch Mod") == 0) {
				mOsc1PitchMod = i;
			}else if (strcmp(param->GetNameForHost(), "Osc 2 Pitch Mod") == 0) {
				mOsc2PitchMod = i;
			}else if (strcmp(param->GetNameForHost(), "LFO Frequency OSC 1") == 0) {
				frequencyKnobLFO1 = i;
			}
		}
	}
}