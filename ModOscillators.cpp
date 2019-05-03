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
	IControlsManager->addParam(this->moduleName, "Icon Sine Wave Off OSC1", ControlsModel::NONE, 58, 218, FALSE, iGraphic);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONSINEWAVEON_ID, ICONSINEWAVEON_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Icon Sine Wave On OSC1", ControlsModel::NONE, 58, 218, FALSE, iGraphic);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONSAWWAVEOFF_ID, ICONSAWWAVEOFF_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Icon Saw Wave Off OSC1", ControlsModel::NONE, 114, 218, FALSE, iGraphic);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONSAWWAVEON_ID, ICONSAWWAVEON_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Icon Saw Wave On OSC1", ControlsModel::NONE, 114, 218, TRUE, iGraphic);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONSQUAREWAVEOFF_ID, ICONSQUAREWAVEOFF_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Icon Square Wave Off OSC1", ControlsModel::NONE, 170, 218, FALSE, iGraphic);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONSQUAREWAVEON_ID, ICONSQUAREWAVEON_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Icon Square Wave On OSC1", ControlsModel::NONE, 170, 218, TRUE, iGraphic);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONTRIANGLEWAVEOFF_ID, ICONTRIANGLEWAVEOFF_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Icon Triangle Wave Off OSC1", ControlsModel::NONE, 226, 218, FALSE, iGraphic);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONTRIANGLEWAVEON_ID, ICONTRIANGLEWAVEON_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Icon Triangle Wave On OSC1", ControlsModel::NONE, 226, 218, TRUE, iGraphic);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONSINEWAVEOFF_ID, ICONSINEWAVEOFF_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Icon Sine Wave Off OSC2", ControlsModel::NONE, 58, 318, FALSE, iGraphic);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONSINEWAVEON_ID, ICONSINEWAVEON_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Icon Sine Wave On OSC2", ControlsModel::NONE, 58, 318, FALSE, iGraphic);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONSAWWAVEOFF_ID, ICONSAWWAVEOFF_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Icon Saw Wave Off OSC2", ControlsModel::NONE, 114, 318, FALSE, iGraphic);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONSAWWAVEON_ID, ICONSAWWAVEON_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Icon Saw Wave On OSC2", ControlsModel::NONE, 114, 318, TRUE, iGraphic);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONSQUAREWAVEOFF_ID, ICONSQUAREWAVEOFF_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Icon Square Wave Off OSC2", ControlsModel::NONE, 170, 318, FALSE, iGraphic);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONSQUAREWAVEON_ID, ICONSQUAREWAVEON_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Icon Square Wave On OSC2", ControlsModel::NONE, 170, 318, TRUE, iGraphic);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONTRIANGLEWAVEOFF_ID, ICONTRIANGLEWAVEOFF_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Icon Triangle Wave Off OSC2", ControlsModel::NONE, 226, 318, FALSE, iGraphic);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONTRIANGLEWAVEON_ID, ICONTRIANGLEWAVEON_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Icon Triangle Wave On OSC2", ControlsModel::NONE, 226, 318, TRUE, iGraphic);

	/* Oscillators LFO Pitch */
	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(KNOB_MEDIUM_ID, KNOB_MEDIUM_FN, 47);
	graphicType = GraphicsModel::KNOBMULTICONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Osc 1 Pitch Mod", ControlsModel::DOUBLE, 308, 195, 0.0, 0.0, 1.0, iGraphic);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(KNOB_MEDIUM_ID, KNOB_MEDIUM_FN, 47);
	graphicType = GraphicsModel::KNOBMULTICONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	IControlsManager->addParam(this->moduleName, "Osc 2 Pitch Mod", ControlsModel::DOUBLE, 308, 295, 0.0, 0.0, 1.0, iGraphic);

}

void ModOscillators::doModelsControlsInIControlsCollection(IPlug* myOhmBass, controlsManager* iControlsManager, graphicsManager* iGraphicsManager, int i) {
	IBitmap graphic = iControlsManager->controlsModelsCollection[i]->graphicsModel->bitmap;
	IControl * control;
	
	switch (iControlsManager->controlsModelsCollection[i]->graphicsModel->graphicsType) {
	case GraphicsModel::RADIOBUTTONSCONTROL:
		control = new IRadioButtonsControl(myOhmBass, iControlsManager->controlsModelsCollection[i]->graphicsModel->iRect, i, 4, &graphic, kHorizontal);
		break;
	case GraphicsModel::BITMAPCONTROL:
		control = new IBitmapControl(myOhmBass, iControlsManager->controlsModelsCollection[i]->x, iControlsManager->controlsModelsCollection[i]->y, i, &graphic);
		if (iControlsManager->controlsModelsCollection[i]->state) {
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
	}

	iControlsManager->AddControlsCollection(control);
	iGraphicsManager->pGraphics->AttachControl(control);
}

void ModOscillators::fillSetOfWavesIcons(IPlug* myOhmBass, controlsManager* iControlsManager) {
	for (int i = 0; i < iControlsManager->getKNumParams(); i++) {
		IParam * param;
		param = iControlsManager->controlsCollection[i]->GetParam();

		if (strcmp(param->GetNameForHost(),"Icon Sine Wave Off OSC1") == 0) {
			mapWavesIconsIdx[0][0][0] = i;
		}
		else if (strcmp(param->GetNameForHost(), "Icon Sine Wave On OSC1") == 0) {
			mapWavesIconsIdx[0][0][1] = i;
		}
		else if (strcmp(param->GetNameForHost(), "Icon Saw Wave Off OSC1") == 0) {
			mapWavesIconsIdx[0][1][0] = i;
		}
		else if (strcmp(param->GetNameForHost(), "Icon Saw Wave On OSC1") == 0) {
			mapWavesIconsIdx[0][1][1] = i;
		}
		else if (strcmp(param->GetNameForHost(), "Icon Square Wave Off OSC1") == 0) {
			mapWavesIconsIdx[0][2][0] = i;
		}
		else if (strcmp(param->GetNameForHost(), "Icon Square Wave On OSC1") == 0) {
			mapWavesIconsIdx[0][2][1] = i;
		}
		else if (strcmp(param->GetNameForHost(), "Icon Triangle Wave Off OSC1") == 0) {
			mapWavesIconsIdx[0][3][0] = i;
		}
		else if (strcmp(param->GetNameForHost(), "Icon Triangle Wave On OSC1") == 0) {
			mapWavesIconsIdx[0][3][1] = i;
		}
		else if (strcmp(param->GetNameForHost(), "Icon Sine Wave Off OSC2") == 0) {
			mapWavesIconsIdx[1][0][0] = i;
		}
		else if (strcmp(param->GetNameForHost(), "Icon Sine Wave On OSC2") == 0) {
			mapWavesIconsIdx[1][0][1] = i;
		}
		else if (strcmp(param->GetNameForHost(), "Icon Saw Wave Off OSC2") == 0) {
			mapWavesIconsIdx[1][1][0] = i;
		}
		else if (strcmp(param->GetNameForHost(), "Icon Saw Wave On OSC2") == 0) {
			mapWavesIconsIdx[1][1][1] = i;
		}
		else if (strcmp(param->GetNameForHost(), "Icon Square Wave Off OSC2") == 0) {
			mapWavesIconsIdx[1][2][0] = i;
		}
		else if (strcmp(param->GetNameForHost(), "Icon Square Wave On OSC2") == 0) {
			mapWavesIconsIdx[1][2][1] = i;
		}
		else if (strcmp(param->GetNameForHost(), "Icon Triangle Wave Off OSC2") == 0) {
			mapWavesIconsIdx[1][3][0] = i;
		}
		else if (strcmp(param->GetNameForHost(), "Icon Triangle Wave On OSC2") == 0) {
			mapWavesIconsIdx[1][3][1] = i;
		}
		else if (strcmp(param->GetNameForHost(), "Bg Btn Osc 1 Waves") == 0) {
			mBgBtnOscWavesOsc1 = i;
		}
		else if (strcmp(param->GetNameForHost(), "Bg Btn Osc 2 Waves") == 0) {
			mBgBtnOscWavesOsc2 = i;
		}
	}	
}


void ModOscillators::OnParamChange(controlsManager* IControlsManager, int paramIdx, bool isPluginInitialized)
{
	if (isPluginInitialized) {
		IParam * param;
		param = IControlsManager->controlsCollection[paramIdx]->GetParam();
		int idxWaveMode = param->Int();
		idxWaveMode--;

		if (paramIdx == mBgBtnOscWavesOsc1) {
			ToggleIconsWavesButtons(IControlsManager, 1, idxWaveMode);
		}
		else if (paramIdx == mBgBtnOscWavesOsc2) {
			ToggleIconsWavesButtons(IControlsManager, 2, idxWaveMode);
		}
		
	}
}
void ModOscillators::ToggleIconsWavesButtons(controlsManager* IControlsManager, int nOsc, int idxWaveMode)
{
	if (nOsc == 1) {
		switch (idxWaveMode) {
		case 0:
			IControlsManager->controlsCollection[mapWavesIconsIdx[0][0][1]]->Hide(FALSE);
			IControlsManager->controlsCollection[mapWavesIconsIdx[0][1][1]]->Hide(TRUE);
			IControlsManager->controlsCollection[mapWavesIconsIdx[0][2][1]]->Hide(TRUE);
			IControlsManager->controlsCollection[mapWavesIconsIdx[0][3][1]]->Hide(TRUE);
			break;
		case 1:
			IControlsManager->controlsCollection[mapWavesIconsIdx[0][0][1]]->Hide(TRUE);
			IControlsManager->controlsCollection[mapWavesIconsIdx[0][1][1]]->Hide(FALSE);
			IControlsManager->controlsCollection[mapWavesIconsIdx[0][2][1]]->Hide(TRUE);
			IControlsManager->controlsCollection[mapWavesIconsIdx[0][3][1]]->Hide(TRUE);
			break;
		case 2:
			IControlsManager->controlsCollection[mapWavesIconsIdx[0][0][1]]->Hide(TRUE);
			IControlsManager->controlsCollection[mapWavesIconsIdx[0][1][1]]->Hide(TRUE);
			IControlsManager->controlsCollection[mapWavesIconsIdx[0][2][1]]->Hide(FALSE);
			IControlsManager->controlsCollection[mapWavesIconsIdx[0][3][1]]->Hide(TRUE);
			break;
		case 3:
			IControlsManager->controlsCollection[mapWavesIconsIdx[0][0][1]]->Hide(TRUE);
			IControlsManager->controlsCollection[mapWavesIconsIdx[0][1][1]]->Hide(TRUE);
			IControlsManager->controlsCollection[mapWavesIconsIdx[0][2][1]]->Hide(TRUE);
			IControlsManager->controlsCollection[mapWavesIconsIdx[0][3][1]]->Hide(FALSE);
			break;
		}

	}
	else if (nOsc == 2) {
		switch (idxWaveMode) {
		case 0:
			IControlsManager->controlsCollection[mapWavesIconsIdx[1][0][1]]->Hide(FALSE);
			IControlsManager->controlsCollection[mapWavesIconsIdx[1][1][1]]->Hide(TRUE);
			IControlsManager->controlsCollection[mapWavesIconsIdx[1][2][1]]->Hide(TRUE);
			IControlsManager->controlsCollection[mapWavesIconsIdx[1][3][1]]->Hide(TRUE);
			break;
		case 1:
			IControlsManager->controlsCollection[mapWavesIconsIdx[1][0][1]]->Hide(TRUE);
			IControlsManager->controlsCollection[mapWavesIconsIdx[1][1][1]]->Hide(FALSE);
			IControlsManager->controlsCollection[mapWavesIconsIdx[1][2][1]]->Hide(TRUE);
			IControlsManager->controlsCollection[mapWavesIconsIdx[1][3][1]]->Hide(TRUE);
			break;
		case 2:
			IControlsManager->controlsCollection[mapWavesIconsIdx[1][0][1]]->Hide(TRUE);
			IControlsManager->controlsCollection[mapWavesIconsIdx[1][1][1]]->Hide(TRUE);
			IControlsManager->controlsCollection[mapWavesIconsIdx[1][2][1]]->Hide(FALSE);
			IControlsManager->controlsCollection[mapWavesIconsIdx[1][3][1]]->Hide(TRUE);
			break;
		case 3:
			IControlsManager->controlsCollection[mapWavesIconsIdx[1][0][1]]->Hide(TRUE);
			IControlsManager->controlsCollection[mapWavesIconsIdx[1][1][1]]->Hide(TRUE);
			IControlsManager->controlsCollection[mapWavesIconsIdx[1][2][1]]->Hide(TRUE);
			IControlsManager->controlsCollection[mapWavesIconsIdx[1][3][1]]->Hide(FALSE);
			break;
		}
	}
}




