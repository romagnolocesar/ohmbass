	#include "ModEQuilibrium.h"


void ModEQuilibrium::setLowFreq(double newLowFreq)
{
	lowFreq = newLowFreq;
}

void ModEQuilibrium::setLowBoost(double newLowBoost)
{
	lowBoost = newLowBoost;
}

void ModEQuilibrium::setHighFreq(double newHighFreq)
{
	highFreq = newHighFreq;
}

void ModEQuilibrium::setHighShelf(double newHighShelf)
{
	highShelf = newHighShelf;
}

double ModEQuilibrium::getLowFreq()
{
	return lowFreq;
}

double ModEQuilibrium::getLowBoost()
{
	return lowBoost;
}

double ModEQuilibrium::getHighFreq()
{
	return highFreq;
}

double ModEQuilibrium::getHighShelf()
{
	return highShelf;
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

	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "Knb Eql Low freq", 560, 640, 150.0, 150.0, 350.0, iGraphic);
	myControl->setShape(3.0);
	IControlsManager->AddModelsCollection(myControl);

	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "Knb Bost Low boost", 639, 640, 0.0, 0.0, 10.0, iGraphic);
	myControl->setShape(2.0);
	IControlsManager->AddModelsCollection(myControl);

	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "Knb Eql High freq", 718, 640, 418.6, 418.6, 790.2, iGraphic);
	myControl->setShape(3.0);
	IControlsManager->AddModelsCollection(myControl);

	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "Knb Shelf Hihg shelf", 797, 640, 0.0, 0.0, 10.0, iGraphic);
	myControl->setShape(2.0);
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

void ModEQuilibrium::updateLowFilterValues() {
	//Biquad *filterPeakLow = new Biquad(bq_type_peak, 2000.0 /*lowFreq*/ / 44100, 12.0, 20.0/*lowBoost*/);
	filterPeakLow->setType(bq_type_peak);
	filterPeakLow->setFc(getLowFreq() /44100);
	//filterPeakLow->setQ(0.0027 * getLowFreq()); //Razão para um bom Q
	filterPeakLow->setQ(0.01 * getLowFreq());
	filterPeakLow->setPeakGain(getLowBoost());
}

void ModEQuilibrium::updateHighFilterValues() {
	filterPeakHigh->setType(bq_type_peak);
	filterPeakHigh->setFc((getHighFreq()*10) / 44100);
	filterPeakHigh->setQ(0.9);
	filterPeakHigh->setPeakGain(getHighShelf()*10);
}

void ModEQuilibrium::process() {
	
}


