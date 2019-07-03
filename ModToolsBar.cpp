#include "ModToolsBar.h"



ModToolsBar::ModToolsBar()
{
}


ModToolsBar::~ModToolsBar()
{
}

void ModToolsBar::init(controlsManager* IControlsManager, graphicsManager* IGraphicsManager) {
	ControlsModel* myControl;


	/* ToolBar */
	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONLFO_ID, ICONLFO_FN, 2);
	graphicType = GraphicsModel::SWITCHCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::ENUM, "ToolsBar LFO", 140, 466, ModulesModel::OFF, ModulesModel::kNumModulesOnOff, iGraphic);
	myControl->setGroupName("ModToolsBar");
	IControlsManager->AddModelsCollection(myControl);
}

void ModToolsBar::doModelsControlsInIControlsCollection(IPlug* myOhmBass, controlsManager* iControlsManager, graphicsManager* iGraphicsManager, int i) {
	IBitmap graphic = iControlsManager->controlsModelsCollection[i]->graphicsModel->bitmap;
	IControl * control;

	switch (iControlsManager->controlsModelsCollection[i]->graphicsModel->graphicsType) {
	case GraphicsModel::SWITCHCONTROL:
		control = new ISwitchControl(myOhmBass, iControlsManager->controlsModelsCollection[i]->x, iControlsManager->controlsModelsCollection[i]->y, i, &graphic);
		break;
	}
	iControlsManager->AddControlsCollection(control);
	iGraphicsManager->pGraphics->AttachControl(control);
}
