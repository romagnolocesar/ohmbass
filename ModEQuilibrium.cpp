	#include "ModEQuilibrium.h"


void ModEQuilibrium::setLowFreq(double newLowFreq)
{
	this->lowFreq = newLowFreq;
}

void ModEQuilibrium::setLowBoost(double newLowBoost)
{
	this->lowBoost = newLowBoost;
}

void ModEQuilibrium::setHighFreq(double newHighFreq)
{
	this->highFreq = newHighFreq;
}

void ModEQuilibrium::setHighShelf(double newHighShelf)
{
	this->highShelf = newHighShelf;
}

double ModEQuilibrium::getLowFreq()
{
	return lowFreq;
}

double ModEQuilibrium::getLowBoost()
{
	return this->lowBoost;
}

double ModEQuilibrium::getHighFreq()
{
	return this->highFreq;
}

double ModEQuilibrium::getHighShelf()
{
	return this->highShelf;
}

void ModEQuilibrium::init(controlsManager* IControlsManager, graphicsManager* IGraphicsManager) {
	ControlsModel* myControl;

	//Tab1
	iGraphic = new GraphicsModel(
		IGraphicsManager->pGraphics->LoadIBitmap(GHRRTAB1_ID, GHRRTAB1_FN),
		GraphicsModel::BITMAPCONTROL
	);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "Tab1 Ghrr", 548, 522, 0.0, 0.0, 1.0, iGraphic);
	IControlsManager->AddModelsCollection(myControl);

	//Titles
	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(GHREQLONTITLE_ID, GHREQLONTITLE_FN);
	graphicType = GraphicsModel::KNOBMULTICONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "Knb Eql title on", 552, 530, 0.0, 0.0, 1.0, iGraphic);
	IControlsManager->AddModelsCollection(myControl);

	//Knobs
	iGraphic = new GraphicsModel(
		IGraphicsManager->getBitmapFromCommonsColletion(IGraphicsManager->mknobMediumParam),
		GraphicsModel::KNOBMULTICONTROLPARAM
	);

	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "Knb Eql Low freq", 560, 640, 0.1, 0.1, 0.99, iGraphic);
	myControl->setShape(2.0);
	IControlsManager->AddModelsCollection(myControl);

	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "Knb Bost Low boost", 639, 640, 0.01, 0.01, 0.99, iGraphic);
	IControlsManager->AddModelsCollection(myControl);

	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "Knb Eql High freq", 718, 640, 0.5, 0.0, 1.0, iGraphic);
	IControlsManager->AddModelsCollection(myControl);

	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "Knb Shelf Hihg shelf", 797, 640, 0.1, 0.0, 1.0, iGraphic);
	IControlsManager->AddModelsCollection(myControl);

}

void ModEQuilibrium::doModelsControlsInIControlsCollection(IPlug* myOhmBass, controlsManager* iControlsManager, graphicsManager* iGraphicsManager, int i) {
	IBitmap graphic = iControlsManager->controlsModelsCollection[i]->graphicsModel->bitmap;
	IControl * control;

	switch (iControlsManager->controlsModelsCollection[i]->graphicsModel->graphicsType) {
	case GraphicsModel::BITMAPCONTROL:
		control = new IBitmapControl(myOhmBass, iControlsManager->controlsModelsCollection[i]->x, iControlsManager->controlsModelsCollection[i]->y, i, &graphic);
		if (iControlsManager->controlsModelsCollection[i]->hide) {
			control->Hide(TRUE);
		}
		else {
			control->Hide(FALSE);
		}
		control->GrayOut(TRUE, 0.99f);
		break;
	case GraphicsModel::KNOBMULTICONTROL:
		control = new IKnobMultiControl(myOhmBass, iControlsManager->controlsModelsCollection[i]->x, iControlsManager->controlsModelsCollection[i]->y, i, &graphic);
		break;
	case GraphicsModel::KNOBMULTICONTROLPARAM:
		control = new IKnobMultiControl(myOhmBass, iControlsManager->controlsModelsCollection[i]->x, iControlsManager->controlsModelsCollection[i]->y, i, &graphic);
		break;
	}

	iControlsManager->AddControlsCollection(control);
	iGraphicsManager->pGraphics->AttachControl(control);
}

void ModEQuilibrium::process() {
	
}


