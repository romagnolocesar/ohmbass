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

	//LFO Wave Mode
	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(WAVEFORM_ID, WAVEFORM_FN, 4);
	graphicType = GraphicsModel::SWITCHCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::ENUM, "LFO Waveform", 270, 290, Oscillator::OSCILLATOR_MODE_TRIANGLE, Oscillator::kNumOscillatorModes, iGraphic);
	myControl->setGroupName("modal_conflfo");
	IControlsManager->AddModelsCollection(myControl);

	//LFO FREQ
	iGraphic = new GraphicsModel(IGraphicsManager->getBitmapFromCommonsColletion(IGraphicsManager->mknobMedium),GraphicsModel::KNOBMULTICONTROL);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "LFO Frequency", 330, 280, 6.0, 0.01, 30.0, iGraphic);
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
