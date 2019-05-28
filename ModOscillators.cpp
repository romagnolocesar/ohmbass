#include "ModOscillators.h"

void ModOscillators::init(controlsManager* IControlsManager, graphicsManager* IGraphicsManager) {
	ControlsModel* myControl;
	
	//BitMaps
	IBitmap mBgBtnOscWavesBitmap = IGraphicsManager->pGraphics->LoadIBitmap(BGBTNOSCWAVES_ID, BGBTNOSCWAVES_FN, 2);

	/* Waves Buttons of Oscillator 1*/
	iRect = IRECT(43, 206, 43 + (56 * 4), 56 + (60 * 4));
	iGraphic = new GraphicsModel(mBgBtnOscWavesBitmap, GraphicsModel::RADIOBUTTONSCONTROL, iRect, EDirection::kHorizontal);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::INT, "Bg Btn Osc 1 Waves", 99, 206, 1, 1, 4, iGraphic);
	IControlsManager->AddModelsCollection(myControl);

	/* Waves Buttons of Oscillator 2*/
	iRect = IRECT(43, 306, 43 + (56 * 4), 126 + (60 * 4));
	iGraphic = new GraphicsModel(mBgBtnOscWavesBitmap, GraphicsModel::RADIOBUTTONSCONTROL, iRect, EDirection::kHorizontal);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::INT, "Bg Btn Osc 2 Waves", 99, 306, 1,1, 4, iGraphic);
	IControlsManager->AddModelsCollection(myControl);

	/* Waves Icons */
	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONSINEWAVEOFF_ID, ICONSINEWAVEOFF_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::NONE, "Icon Sine Wave Off OSC1", 58, 218, iGraphic, FALSE);
	IControlsManager->AddModelsCollection(myControl);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONSINEWAVEON_ID, ICONSINEWAVEON_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::NONE, "Icon Sine Wave On OSC1", 58, 218, iGraphic, FALSE);
	IControlsManager->AddModelsCollection(myControl);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONSAWWAVEOFF_ID, ICONSAWWAVEOFF_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::NONE, "Icon Saw Wave Off OSC1", 114, 218, iGraphic, FALSE);
	IControlsManager->AddModelsCollection(myControl);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONSAWWAVEON_ID, ICONSAWWAVEON_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::NONE, "Icon Saw Wave On OSC1", 114, 218, iGraphic, TRUE);
	IControlsManager->AddModelsCollection(myControl);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONSQUAREWAVEOFF_ID, ICONSQUAREWAVEOFF_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::NONE, "Icon Square Wave Off OSC1", 170, 218, iGraphic, FALSE);
	IControlsManager->AddModelsCollection(myControl);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONSQUAREWAVEON_ID, ICONSQUAREWAVEON_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::NONE, "Icon Square Wave On OSC1", 170, 218, iGraphic, TRUE);
	IControlsManager->AddModelsCollection(myControl);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONTRIANGLEWAVEOFF_ID, ICONTRIANGLEWAVEOFF_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::NONE, "Icon Triangle Wave Off OSC1", 226, 218, iGraphic, FALSE);
	IControlsManager->AddModelsCollection(myControl);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONTRIANGLEWAVEON_ID, ICONTRIANGLEWAVEON_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::NONE, "Icon Triangle Wave On OSC1", 226, 218, iGraphic, TRUE);
	IControlsManager->AddModelsCollection(myControl);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONSINEWAVEOFF_ID, ICONSINEWAVEOFF_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::NONE, "Icon Sine Wave Off OSC2", 58, 318, iGraphic, FALSE);
	IControlsManager->AddModelsCollection(myControl);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONSINEWAVEON_ID, ICONSINEWAVEON_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::NONE, "Icon Sine Wave On OSC2", 58, 318, iGraphic, FALSE);
	IControlsManager->AddModelsCollection(myControl);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONSAWWAVEOFF_ID, ICONSAWWAVEOFF_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::NONE, "Icon Saw Wave Off OSC2", 114, 318, iGraphic, FALSE);
	IControlsManager->AddModelsCollection(myControl);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONSAWWAVEON_ID, ICONSAWWAVEON_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::NONE, "Icon Saw Wave On OSC2", 114, 318, iGraphic, TRUE);
	IControlsManager->AddModelsCollection(myControl);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONSQUAREWAVEOFF_ID, ICONSQUAREWAVEOFF_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::NONE, "Icon Square Wave Off OSC2", 170, 318, iGraphic, FALSE);
	IControlsManager->AddModelsCollection(myControl);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONSQUAREWAVEON_ID, ICONSQUAREWAVEON_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::NONE, "Icon Square Wave On OSC2", 170, 318, iGraphic, TRUE);
	IControlsManager->AddModelsCollection(myControl);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONTRIANGLEWAVEOFF_ID, ICONTRIANGLEWAVEOFF_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::NONE, "Icon Triangle Wave Off OSC2", 226, 318, iGraphic, FALSE);
	IControlsManager->AddModelsCollection(myControl);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(ICONTRIANGLEWAVEON_ID, ICONTRIANGLEWAVEON_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::NONE, "Icon Triangle Wave On OSC2", 226, 318, iGraphic, TRUE);
	IControlsManager->AddModelsCollection(myControl);

	/* Oscillators LFO Pitch */
	pBitmap = IGraphicsManager->getBitmapFromCommonsColletion(IGraphicsManager->mknobMedium);
	graphicType = GraphicsModel::KNOBMULTICONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "Osc 1 Pitch Mod", 308, 195, 0.0, 0.0, 1.0, iGraphic);
	IControlsManager->AddModelsCollection(myControl);

	pBitmap = IGraphicsManager->getBitmapFromCommonsColletion(IGraphicsManager->mknobMedium);
	graphicType = GraphicsModel::KNOBMULTICONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "Osc 2 Pitch Mod", 308, 295, 0.0, 0.0, 1.0, iGraphic);
	IControlsManager->AddModelsCollection(myControl);

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
	}

	iControlsManager->AddControlsCollection(control);
	iGraphicsManager->pGraphics->AttachControl(control);
}

void ModOscillators::fillSetOfWavesIcons(controlsManager* iControlsManager) {
	for (int i = 0; i < iControlsManager->getKNumParams(); i++) {
		IParam * param;
		param = iControlsManager->controlsCollection[i]->GetParam();
		if (param != nullptr) {
			if (strcmp(param->GetNameForHost(), "Icon Sine Wave Off OSC1") == 0) {
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
			else if (strcmp(param->GetNameForHost(), "Osc 1 Pitch Mod") == 0) {
				mOsc1PitchMod = i;
			}
			else if (strcmp(param->GetNameForHost(), "Osc 2 Pitch Mod") == 0) {
				mOsc2PitchMod = i;
			}
		}
	}	
}


void ModOscillators::OnParamChange(controlsManager* IControlsManager, int paramIdx, int idxWaveMode, bool isPluginInitialized)
{
	if (isPluginInitialized) {
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




