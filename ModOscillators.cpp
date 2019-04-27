#include "ModOscillators.h"



ModOscillators::ModOscillators()
{
}


ModOscillators::~ModOscillators()
{
}

void ModOscillators::init(controlsManager* IControlsManager) {

	pBitmap = pGraphics->LoadIBitmap(BGBTNOSCWAVES_ID, BGBTNOSCWAVES_FN, 2);
	graphicType = GraphicsModel::RADIOBUTTONSCONTROL;
	IRECT iRect = IRECT(43, 206, 43 + (56 * 4), 56 + (60 * 4));
	EDirection* EDirection;
	iGraphic = new GraphicsModel(&pBitmap, graphicType, iRect, EDirection);
	
	IControlsManager->addParam(this->moduleName, "Bg Btn Osc 1 Waves", ControlsModel::INT, 99, 206, 1, 1, 4, iGraphic);




	/*IControlsManager->addParam(this->moduleName, "Bg Btn Osc 2 Waves", ControlsModel::INT, 99, 306, 1, 1, 4);
	IControlsManager->addParam(this->moduleName, "Icon Sine Wave Off OSC1", ControlsModel::NONE, 58, 218, TRUE);
	IControlsManager->addParam(this->moduleName, "Icon Sine Wave On OSC1", ControlsModel::NONE, 58, 218, TRUE);
	IControlsManager->addParam(this->moduleName, "Icon Saw Wave Off OSC1", ControlsModel::NONE, 114, 218, TRUE);
	IControlsManager->addParam(this->moduleName, "Icon Saw Wave On OSC1", ControlsModel::NONE, 114, 218, FALSE);
	IControlsManager->addParam(this->moduleName, "Icon Square Wave Off OSC1", ControlsModel::NONE, 170, 218, TRUE);
	IControlsManager->addParam(this->moduleName, "Icon Square Wave On OSC1", ControlsModel::NONE, 170, 218, FALSE);
	IControlsManager->addParam(this->moduleName, "Icon Triangle Wave Off OSC1", ControlsModel::NONE, 226, 218, TRUE);
	IControlsManager->addParam(this->moduleName, "Icon Triangle Wave On OSC1", ControlsModel::NONE, 226, 218, FALSE);
	IControlsManager->addParam(this->moduleName, "Icon Sine Wave Off OSC2", ControlsModel::NONE, 58, 318, TRUE);
	IControlsManager->addParam(this->moduleName, "Icon Sine Wave On OSC2", ControlsModel::NONE, 58, 318, TRUE);
	IControlsManager->addParam(this->moduleName, "Icon Saw Wave Off OSC2", ControlsModel::NONE, 114, 318, TRUE);
	IControlsManager->addParam(this->moduleName, "Icon Saw Wave On OSC2", ControlsModel::NONE, 114, 318, FALSE);
	IControlsManager->addParam(this->moduleName, "Icon Square Wave Off OSC2", ControlsModel::NONE, 170, 318, TRUE);
	IControlsManager->addParam(this->moduleName, "Icon Square Wave On OSC2", ControlsModel::NONE, 170, 318, FALSE);
	IControlsManager->addParam(this->moduleName, "Icon Triangle Wave Off OSC2", ControlsModel::NONE, 226, 318, TRUE);
	IControlsManager->addParam(this->moduleName, "Icon Triangle Wave On OSC2", ControlsModel::NONE, 226, 318, FALSE);
	IControlsManager->addParam(this->moduleName, "Osc 1 Pitch Mod", ControlsModel::NONE, 308, 195, 0.0, 0.0, 1.0);
	IControlsManager->addParam(this->moduleName, "Osc 2 Pitch Mod", ControlsModel::NONE, 308, 295, 0.0, 0.0, 1.0);*/
}