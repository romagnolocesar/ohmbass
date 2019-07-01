#include "ModFilters.h"
#include "Filter.h"



ModFilters::ModFilters()
{
}


ModFilters::~ModFilters()
{
}

void ModFilters::init(controlsManager* IControlsManager, graphicsManager* IGraphicsManager) {
	ControlsModel* myControl;

	//Drop Down Menu Filters Mode
	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(DROP_DOWN_FILTERS_MODES_ID, DROP_DOWN_FILTERS_MODES_FN, 3);
	graphicType = GraphicsModel::SWITCHCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::ENUM, "Drop Down Filters Mode", 695, 303, Filter::FILTER_MODE_LOWPASS, Filter::kNumFilterModes, iGraphic);
	IControlsManager->AddModelsCollection(myControl);

	//Slope of Filter
	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(SWITCH_DROP_ID, SWITCH_DROP_FN, 2);
	graphicType = GraphicsModel::SWITCHCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::ENUM, "Slope Filter", 873, 302, Filter::FILTER_SLOPE_24, Filter::kNumSlopeModes, iGraphic);
	IControlsManager->AddModelsCollection(myControl);

	//Knobs
	iGraphic = new GraphicsModel(
		IGraphicsManager->getBitmapFromCommonsColletion(IGraphicsManager->mknobMedium), 
		GraphicsModel::KNOBMULTICONTROL
	);

	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "Filter Cutoff", 635, 343, 0.99, 0.01, 0.99, iGraphic);
	myControl->setShape(2);
	IControlsManager->AddModelsCollection(myControl);

	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "Filter Resonance", 730, 343, 0.01, 0.01, 1.0, iGraphic);
	IControlsManager->AddModelsCollection(myControl);


	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "Filter Envelope Amount", 820, 343, 0.0, -1.0, 1.0, iGraphic);
	IControlsManager->AddModelsCollection(myControl);

	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "Filter Env Attack", 635, 193, 0.01, 0.01, 10.0, iGraphic);
	myControl->setShape(3);
	IControlsManager->AddModelsCollection(myControl);

	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "Filter Env Decay", 730, 193, 0.5, 0.01, 15.0, iGraphic);
	myControl->setShape(3);
	IControlsManager->AddModelsCollection(myControl);

	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "Filter Env Sustain", 820, 193, 0.1, 0.001, 1.0, iGraphic);
	myControl->setShape(2);
	IControlsManager->AddModelsCollection(myControl);

	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "Filter Env Release", 915, 193, 1.0, 0.001, 15.0, iGraphic);
	myControl->setShape(3);
	IControlsManager->AddModelsCollection(myControl);

}


void ModFilters::doModelsControlsInIControlsCollection(IPlug* myOhmBass, controlsManager* iControlsManager, graphicsManager* iGraphicsManager, int i) {
	IBitmap graphic = iControlsManager->controlsModelsCollection[i]->graphicsModel->bitmap;
	IControl * control;

	switch (iControlsManager->controlsModelsCollection[i]->graphicsModel->graphicsType) {
	case GraphicsModel::SWITCHCONTROL:
		control = new ISwitchControl(myOhmBass, iControlsManager->controlsModelsCollection[i]->x, iControlsManager->controlsModelsCollection[i]->y, i, &graphic);
		break;
	case GraphicsModel::KNOBMULTICONTROL:
		control = new IKnobMultiControl(myOhmBass, iControlsManager->controlsModelsCollection[i]->x, iControlsManager->controlsModelsCollection[i]->y, i, &graphic);
		break;
	}

	iControlsManager->AddControlsCollection(control);
	iGraphicsManager->pGraphics->AttachControl(control);
}