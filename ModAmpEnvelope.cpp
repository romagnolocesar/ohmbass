#include "ModAmpEnvelope.h"



ModAmpEnvelope::ModAmpEnvelope()
{
}


ModAmpEnvelope::~ModAmpEnvelope()
{
}

void ModAmpEnvelope::init(controlsManager* IControlsManager, graphicsManager* IGraphicsManager) {
	ControlsModel* myControl;

	//Knobs
	iGraphic = new GraphicsModel(
		IGraphicsManager->getBitmapFromCommonsColletion(IGraphicsManager->mknobMedium),
		GraphicsModel::KNOBMULTICONTROL
	);

	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "Volume Env Attack", 35, 15, 0.01, 0.01, 10.0, iGraphic);
	myControl->setShape(3.0);
	IControlsManager->AddModelsCollection(myControl);

	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "Volume Env Decay", 130, 15, 0.5, 0.01, 15.0, iGraphic);
	myControl->setShape(3.0);
	IControlsManager->AddModelsCollection(myControl);

	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "Volume Env Sustain", 225, 15, 0.1, 0.001, 1.0, iGraphic);
	myControl->setShape(2.0);
	IControlsManager->AddModelsCollection(myControl);

	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "Volume Env Release", 320, 15, 1.0, 0.01, 15.0, iGraphic);
	myControl->setShape(3.0);
	IControlsManager->AddModelsCollection(myControl);

}

void ModAmpEnvelope::doModelsControlsInIControlsCollection(IPlug* myOhmBass, controlsManager* iControlsManager, graphicsManager* iGraphicsManager, int i) {
	IBitmap graphic = iControlsManager->controlsModelsCollection[i]->graphicsModel->bitmap;
	IControl * control;

	switch (iControlsManager->controlsModelsCollection[i]->graphicsModel->graphicsType) {
	case GraphicsModel::KNOBMULTICONTROL:
		control = new IKnobMultiControl(myOhmBass, iControlsManager->controlsModelsCollection[i]->x, iControlsManager->controlsModelsCollection[i]->y, i, &graphic);
		break;
	}

	iControlsManager->AddControlsCollection(control);
	iGraphicsManager->pGraphics->AttachControl(control);
}
		