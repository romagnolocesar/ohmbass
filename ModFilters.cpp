#include "ModFilters.h"
#include "Filter.h"
#include "Oscillator.h"



ModFilters::ModFilters()
{
}


ModFilters::~ModFilters()
{
}

void ModFilters::init(controlsManager* IControlsManager, graphicsManager* IGraphicsManager) {
	//Filter Mode
	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(FILTERMODE_ID, FILTERMODE_FN, 3);
	graphicType = GraphicsModel::SWITCHCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Filter Mode", ControlsModel::ENUM, 875, 300, Filter::FILTER_MODE_LOWPASS, Filter::kNumFilterModes, iGraphic);

	//Knobs
	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(KNOB_MEDIUM_ID, KNOB_MEDIUM_FN, 47);
	graphicType = GraphicsModel::KNOBMULTICONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Filter Cutoff", ControlsModel::DOUBLE, 635, 343, 0.99, 0.0, 0.99, iGraphic);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(KNOB_MEDIUM_ID, KNOB_MEDIUM_FN, 47);
	graphicType = GraphicsModel::KNOBMULTICONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Filter Resonance", ControlsModel::DOUBLE, 730, 343, 0.0, 0.0, 1.0, iGraphic);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(KNOB_MEDIUM_ID, KNOB_MEDIUM_FN, 47);
	graphicType = GraphicsModel::KNOBMULTICONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Filter LFO Amount", ControlsModel::DOUBLE, 840, 343, 0.0, 0.0, 1.0, iGraphic);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(KNOB_MEDIUM_ID, KNOB_MEDIUM_FN, 47);
	graphicType = GraphicsModel::KNOBMULTICONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Filter Envelope Amount", ControlsModel::DOUBLE, 915, 343, 0.0, -1.0, 1.0, iGraphic);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(WAVEFORM_ID, WAVEFORM_FN, 4);
	graphicType = GraphicsModel::SWITCHCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "LFO Waveform", ControlsModel::ENUM, 30, 520, Oscillator::OSCILLATOR_MODE_TRIANGLE, Oscillator::kNumOscillatorModes, iGraphic);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(KNOB_MEDIUM_ID, KNOB_MEDIUM_FN, 47);
	graphicType = GraphicsModel::KNOBMULTICONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "LFO Frequency", ControlsModel::DOUBLE, 75, 510, 6.0, 0.01, 30.0, iGraphic);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(KNOB_MEDIUM_ID, KNOB_MEDIUM_FN, 47);
	graphicType = GraphicsModel::KNOBMULTICONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Filter Env Attack", ControlsModel::DOUBLE, 635, 193, 0.01, 0.01, 10.0, iGraphic);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(KNOB_MEDIUM_ID, KNOB_MEDIUM_FN, 47);
	graphicType = GraphicsModel::KNOBMULTICONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Filter Env Decay", ControlsModel::DOUBLE, 730, 193, 0.5, 0.01, 15.0, iGraphic);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(KNOB_MEDIUM_ID, KNOB_MEDIUM_FN, 47);
	graphicType = GraphicsModel::KNOBMULTICONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Filter Env Sustain", ControlsModel::DOUBLE, 820, 193, 0.1, 0.001, 1.0, iGraphic);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(KNOB_MEDIUM_ID, KNOB_MEDIUM_FN, 47);
	graphicType = GraphicsModel::KNOBMULTICONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Filter Env Release", ControlsModel::DOUBLE, 915, 193, 1.0, 0.01, 15.0, iGraphic);

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