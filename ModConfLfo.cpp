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

	//LFO Wave Mode
	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(WAVEFORM_ID, WAVEFORM_FN, 4);
	graphicType = GraphicsModel::SWITCHCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::ENUM, "LFO Waveform", 30, 520, Oscillator::OSCILLATOR_MODE_TRIANGLE, Oscillator::kNumOscillatorModes, iGraphic);
	IControlsManager->AddModelsCollection(myControl);

	//Knobs
	iGraphic = new GraphicsModel(
		IGraphicsManager->getBitmapFromCommonsColletion(IGraphicsManager->mknobMedium),
		GraphicsModel::KNOBMULTICONTROL
	);

	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "LFO Frequency", 75, 510, 6.0, 0.01, 30.0, iGraphic);
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
	}

	iControlsManager->AddControlsCollection(control);
	iGraphicsManager->pGraphics->AttachControl(control);
}


void ModConfLfo::createModalBox(IPlug * myOhmBass, IGraphics * pGraphics, int w, int h)
{
	IRECT pRect;
	pRect.L = ((1024 / 2) - (w / 2));
	pRect.T = ((768 / 2) - (h / 2));
	pRect.R = ((1024 / 2) + (w / 2));
	pRect.B = ((768 / 2) + (h / 2));

	this->modalBoxConfLfo = new IModalBox(myOhmBass, pRect, w, h);

	pGraphics->AttachControl(this->modalBoxConfLfo);
}


//Show ModalBackground
void ModConfLfo::showModalBox()
{
	this->modalBoxConfLfo->showModalBox();
}
