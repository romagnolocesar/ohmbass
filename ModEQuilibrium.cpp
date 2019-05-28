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

void ModEQuilibrium::setActiOhmBassMagic(bool newState)
{
	actiOhmBassMagic = newState;
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

bool ModEQuilibrium::getActiOhmBassMagic()
{
	return actiOhmBassMagic;
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


	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "Knb Bost Low boost", 639, 640, 0.0, 0.0, 20.0, iGraphic);
	myControl->setShape(2.0);
	IControlsManager->AddModelsCollection(myControl);

	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "Knb Eql High freq", 718, 640, 418.6, 418.6, 790.2, iGraphic);
	myControl->setShape(3.0);
	IControlsManager->AddModelsCollection(myControl);

	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "Knb Shelf Hihg shelf", 797, 640, 0.0, 0.0, 20.0, iGraphic);
	myControl->setShape(2.0);
	IControlsManager->AddModelsCollection(myControl);

	//Magic ActiOhm Button
	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(BTN_MAGIC_ACTIOHM_ID, BTN_MAGIC_ACTIOHM_FN, 2);
	graphicType = GraphicsModel::SWITCHCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::ENUM, "ActiOhm Bass Magic", 819, 568, ModulesModel::OFF, ModulesModel::kNumModulesOnOff, iGraphic);
	IControlsManager->AddModelsCollection(myControl);

	//LINE TEST
	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(BTN_MAGIC_ACTIOHM_ID, BTN_MAGIC_ACTIOHM_FN, 2);
	graphicType = GraphicsModel::SWITCHCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::ENUM, "test", 560, 568, ModulesModel::OFF, ModulesModel::kNumModulesOnOff, iGraphic);
	IControlsManager->AddModelsCollection(myControl);


}

void ModEQuilibrium::doModelsControlsInIControlsCollection(IPlug* myOhmBass, controlsManager* iControlsManager, graphicsManager* iGraphicsManager, int i) {
	IBitmap graphic = iControlsManager->controlsModelsCollection[i]->graphicsModel->bitmap;
	IControl * control;

	switch (iControlsManager->controlsModelsCollection[i]->graphicsModel->graphicsType) {
	case GraphicsModel::SWITCHCONTROL:
		control = new ISwitchControl(myOhmBass, iControlsManager->controlsModelsCollection[i]->x, iControlsManager->controlsModelsCollection[i]->y, i, &graphic);
		break;
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
	filterPeakLow->setType(bq_type_peak);
	filterPeakLow->setFc(getLowFreq() / 44100);
	filterPeakLow->setQ(0.01 * getLowFreq());
	filterPeakLow->setPeakGain(getLowBoost());
}

void ModEQuilibrium::updateHighFilterValues() {
	filterPeakHigh->setType(bq_type_peak);
	filterPeakHigh->setFc((getHighFreq()*10) / 44100);
	filterPeakHigh->setQ(1.3);
	filterPeakHigh->setPeakGain(getHighShelf());
}

void ModEQuilibrium::updateLowShelfFilter() {
	filterLowShelf->setType(bq_type_lowshelf);
	filterLowShelf->setFc(120.0 / 44100);
	filterLowShelf->setQ(0.47);
	filterLowShelf->setPeakGain(-3.5);
}

void ModEQuilibrium::updateControlNasalHighFreq(){
	filterNasalHighFreq->setType(bq_type_peak);
	filterNasalHighFreq->setFc(1600.0 /44100);
	filterNasalHighFreq->setQ(2);
	filterNasalHighFreq->setPeakGain(-3.0);
}

void ModEQuilibrium::updateControlNasalLowFreq(){
	filterNasalLowFreq->setType(bq_type_peak);
	filterNasalLowFreq->setFc(350.0 / 44100);
	filterNasalLowFreq->setQ(3.2);
	filterNasalLowFreq->setPeakGain(-3.0);
}

void ModEQuilibrium::updateHighCutFilter(){
	filterHighCut->setType(bq_type_lowpass);
	filterHighCut->setFc(15400.0 / 44100);
	filterHighCut->setQ(1);
}

double ModEQuilibrium::process(double output) {
	//(EQLIBRIUM) Filters	
	output = filterPeakLow->process(output);
	output = filterPeakHigh->process(output);
	if (this->getActiOhmBassMagic()) {
		output = filterLowShelf->process(output);
		output = filterNasalHighFreq->process(output);
		output = filterNasalLowFreq->process(output);
		output = filterHighCut->process(output);
	}
	
	return output;
}


