#include "ModOscillators.h"



void ModOscillators::init(controlsManager* IControlsManager, graphicsManager* IGraphicsManager) {

	/* Waves Buttons of Oscillator 1*/
	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(BGBTNOSCWAVES_ID, BGBTNOSCWAVES_FN, 2);
	graphicType = GraphicsModel::RADIOBUTTONSCONTROL;
	iRect = IRECT(43, 206, 43 + (56 * 4), 56 + (60 * 4));
	iGraphic = new GraphicsModel(pBitmap, graphicType, iRect, EDirection::kHorizontal);
	IControlsManager->addParam(this->moduleName, "Bg Btn Osc 1 Waves", ControlsModel::INT, 99, 206, 1, 1, 4, iGraphic);

	/* Waves Buttons of Oscillator 2*/
	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(BGBTNOSCWAVES_ID, BGBTNOSCWAVES_FN, 2);
	graphicType = GraphicsModel::RADIOBUTTONSCONTROL;
	iRect = IRECT(43, 306, 43 + (56 * 4), 126 + (60 * 4));
	iGraphic = new GraphicsModel(pBitmap, graphicType, iRect, EDirection::kHorizontal);
	IControlsManager->addParam(this->moduleName, "Bg Btn Osc 2 Waves", ControlsModel::INT, 99, 306, 1, 1, 4, iGraphic);

	/* Waves Icons */
	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONSINEWAVEOFF_ID, ICONSINEWAVEOFF_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Icon Sine Wave Off OSC1", ControlsModel::NONE, 58, 218, TRUE, iGraphic);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONSINEWAVEON_ID, ICONSINEWAVEON_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Icon Sine Wave On OSC1", ControlsModel::NONE, 58, 218, TRUE, iGraphic);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONSAWWAVEOFF_ID, ICONSAWWAVEOFF_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Icon Saw Wave Off OSC1", ControlsModel::NONE, 114, 218, TRUE, iGraphic);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONSAWWAVEON_ID, ICONSAWWAVEON_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Icon Saw Wave On OSC1", ControlsModel::NONE, 114, 218, FALSE, iGraphic);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONSQUAREWAVEOFF_ID, ICONSQUAREWAVEOFF_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Icon Square Wave Off OSC1", ControlsModel::NONE, 170, 218, TRUE, iGraphic);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONSQUAREWAVEON_ID, ICONSQUAREWAVEON_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Icon Square Wave On OSC1", ControlsModel::NONE, 170, 218, TRUE, iGraphic);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONTRIANGLEWAVEOFF_ID, ICONTRIANGLEWAVEOFF_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Icon Triangle Wave Off OSC1", ControlsModel::NONE, 226, 218, TRUE, iGraphic);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONTRIANGLEWAVEON_ID, ICONTRIANGLEWAVEON_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Icon Triangle Wave On OSC1", ControlsModel::NONE, 226, 218, FALSE, iGraphic);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONSINEWAVEOFF_ID, ICONSINEWAVEOFF_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Icon Sine Wave Off OSC2", ControlsModel::NONE, 58, 318, TRUE, iGraphic);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONSINEWAVEON_ID, ICONSINEWAVEON_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Icon Sine Wave On OSC2", ControlsModel::NONE, 58, 318, TRUE, iGraphic);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONSAWWAVEOFF_ID, ICONSAWWAVEOFF_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Icon Saw Wave Off OSC2", ControlsModel::NONE, 114, 318, TRUE, iGraphic);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONSAWWAVEON_ID, ICONSAWWAVEON_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Icon Saw Wave On OSC2", ControlsModel::NONE, 114, 318, FALSE, iGraphic);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONSQUAREWAVEOFF_ID, ICONSQUAREWAVEOFF_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Icon Square Wave Off OSC2", ControlsModel::NONE, 170, 318, TRUE, iGraphic);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONSQUAREWAVEON_ID, ICONSQUAREWAVEON_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Icon Square Wave On OSC2", ControlsModel::NONE, 170, 318, TRUE, iGraphic);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONTRIANGLEWAVEOFF_ID, ICONTRIANGLEWAVEOFF_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Icon Triangle Wave Off OSC2", ControlsModel::NONE, 226, 318, TRUE, iGraphic);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONTRIANGLEWAVEON_ID, ICONTRIANGLEWAVEON_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Icon Triangle Wave On OSC2", ControlsModel::NONE, 226, 318, FALSE, iGraphic);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(KNOB_MEDIUM_ID, KNOB_MEDIUM_FN);
	graphicType = GraphicsModel::KNOBMULTICONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Osc 1 Pitch Mod", ControlsModel::DOUBLE, 308, 195, 0.0, 0.0, 1.0, iGraphic);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(KNOB_MEDIUM_ID, KNOB_MEDIUM_FN);
	graphicType = GraphicsModel::KNOBMULTICONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Osc 2 Pitch Mod", ControlsModel::DOUBLE, 308, 295, 0.0, 0.0, 1.0, iGraphic);

}







