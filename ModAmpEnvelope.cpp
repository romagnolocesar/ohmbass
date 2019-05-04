#include "ModAmpEnvelope.h"



ModAmpEnvelope::ModAmpEnvelope()
{
}


ModAmpEnvelope::~ModAmpEnvelope()
{
}

void ModAmpEnvelope::init(controlsManager* IControlsManager, graphicsManager* IGraphicsManager) {

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(KNOB_MEDIUM_ID, KNOB_MEDIUM_FN, 47);
	graphicType = GraphicsModel::KNOBMULTICONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);

	IControlsManager->addParam(this->moduleName, "Volume Env Attack", ControlsModel::DOUBLE, 35, 15, 0.01, 0.01, 10.0, iGraphic);
	IControlsManager->addParam(this->moduleName, "Volume Env Decay", ControlsModel::DOUBLE, 130, 15, 0.5, 0.01, 15.0, iGraphic);
	IControlsManager->addParam(this->moduleName, "Volume Env Sustain", ControlsModel::DOUBLE, 225, 15, 0.1, 0.001, 1.0, iGraphic);
	IControlsManager->addParam(this->moduleName, "Volume Env Release", ControlsModel::DOUBLE, 320, 15, 1.0, 0.01, 15.0, iGraphic);

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
		