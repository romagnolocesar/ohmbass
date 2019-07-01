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

	//MODAL
	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(MODAL_MEDIUM_ONE_ID, MODAL_MEDIUM_ONE_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::NONE, "Modal Box", 236, 215, 0, 0, iGraphic, TRUE);
	myControl->setGroupName("modal_conflfo");
	IControlsManager->AddModelsCollection(myControl);

	//Close Button
	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(MODAL_CLOSE_ICON_ID, MODAL_CLOSE_ICON_FN);
	graphicType = GraphicsModel::SWITCHCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::ENUM, "Modal Close Icon", 763, 232, 0, 0, iGraphic);
	myControl->setGroupName("modal_conflfo");
	IControlsManager->AddModelsCollection(myControl);

	//&&&&&&&&&&&&&&&& OSC 1 &&&&&&&&&&&&&&&&&&&&&&&&&&&&&
	//Wave Mode
	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(WAVEFORM_ID, WAVEFORM_FN, 4);
	graphicType = GraphicsModel::SWITCHCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::ENUM, "LFO Waveform OSC 1", 270, 290, Oscillator::OSCILLATOR_MODE_TRIANGLE, Oscillator::kNumOscillatorModes, iGraphic);
	myControl->setGroupName("modal_conflfo");
	IControlsManager->AddModelsCollection(myControl);

	//FREQ
	iGraphic = new GraphicsModel(IGraphicsManager->getBitmapFromCommonsColletion(IGraphicsManager->mknobMedium),GraphicsModel::KNOBMULTICONTROL);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "LFO Frequency OSC 1", 330, 280, 6.0, 0.01, 30.0, iGraphic);
	myControl->setGroupName("modal_conflfo");
	IControlsManager->AddModelsCollection(myControl);

	/* Pitch Amount*/
	iGraphic = new GraphicsModel(IGraphicsManager->getBitmapFromCommonsColletion(IGraphicsManager->mknobMedium), GraphicsModel::KNOBMULTICONTROL);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "Osc 1 Pitch Mod", 400, 280, 0.0, 0.0, 1.0, iGraphic);
	myControl->setGroupName("modal_conflfo");
	IControlsManager->AddModelsCollection(myControl);

	//&&&&&&&&&&&&&&&& OSC 2 &&&&&&&&&&&&&&&&&&&&&&&&&&&&&
	//Wave Mode
	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(WAVEFORM_ID, WAVEFORM_FN, 4);
	graphicType = GraphicsModel::SWITCHCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::ENUM, "LFO Waveform OSC 2", 270, 390, Oscillator::OSCILLATOR_MODE_TRIANGLE, Oscillator::kNumOscillatorModes, iGraphic);
	myControl->setGroupName("modal_conflfo");
	IControlsManager->AddModelsCollection(myControl);

	//FREQ
	iGraphic = new GraphicsModel(IGraphicsManager->getBitmapFromCommonsColletion(IGraphicsManager->mknobMedium), GraphicsModel::KNOBMULTICONTROL);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "LFO Frequency OSC 2", 330, 380, 6.0, 0.01, 30.0, iGraphic);
	myControl->setGroupName("modal_conflfo");
	IControlsManager->AddModelsCollection(myControl);

	/* Pitch Amount*/
	iGraphic = new GraphicsModel(IGraphicsManager->getBitmapFromCommonsColletion(IGraphicsManager->mknobMedium), GraphicsModel::KNOBMULTICONTROL);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "Osc 2 Pitch Mod", 400, 380, 0.0, 0.0, 1.0, iGraphic);
	myControl->setGroupName("modal_conflfo");
	IControlsManager->AddModelsCollection(myControl);

	//&&&&&&&&&&&&&&&& FILTER AB &&&&&&&&&&&&&&&&&&&&&&&&&&&&&
	//Wave Mode
	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(WAVEFORM_ID, WAVEFORM_FN, 4);
	graphicType = GraphicsModel::SWITCHCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::ENUM, "LFO Waveform Filter AB", 270, 490, Oscillator::OSCILLATOR_MODE_TRIANGLE, Oscillator::kNumOscillatorModes, iGraphic);
	myControl->setGroupName("modal_conflfo");
	IControlsManager->AddModelsCollection(myControl);

	//FREQ
	iGraphic = new GraphicsModel(IGraphicsManager->getBitmapFromCommonsColletion(IGraphicsManager->mknobMedium), GraphicsModel::KNOBMULTICONTROL);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "LFO Frequency Filter AB", 330, 480, 6.0, 0.01, 30.0, iGraphic);
	myControl->setGroupName("modal_conflfo");
	IControlsManager->AddModelsCollection(myControl);

	/* Filter AB Amount*/
	iGraphic = new GraphicsModel(IGraphicsManager->getBitmapFromCommonsColletion(IGraphicsManager->mknobMedium), GraphicsModel::KNOBMULTICONTROL);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "Filter LFO Amount", 400, 480, 0.0, 0.0, 1.0, iGraphic);
	myControl->setGroupName("modal_conflfo");
	IControlsManager->AddModelsCollection(myControl);

	

}

void ModConfLfo::doModelsControlsInIControlsCollection(IPlug* myOhmBass, controlsManager* iControlsManager, graphicsManager* iGraphicsManager, int i) {
	IBitmap graphic = iControlsManager->controlsModelsCollection[i]->graphicsModel->bitmap;
	IControl * control;

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
			}
		}
	}
}