#include "ModGainFaders.h"

void ModGainFaders::init(controlsManager* IControlsManager, graphicsManager* IGraphicsManager) {
	ControlsModel* myControl;

	/* Glows */
	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(FADERGLOW_ID, FADERGLOW_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "Fader Glow Osc1", 452, 219, 0, 0, 1.0, iGraphic);
	IControlsManager->AddModelsCollection(myControl);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(FADERGLOW_ID, FADERGLOW_FN);
	graphicType = GraphicsModel::BITMAPCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "Fader Glow Osc2", 533, 219, 0, 0, 1.0, iGraphic);
	IControlsManager->AddModelsCollection(myControl);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(FADERHANDLERON_ID, FADERHANDLERON_FN);
	graphicType = GraphicsModel::FADERCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "Fader Handler ON Osc1", 429, 210, 0.8, 0.0, 1.0, iGraphic);
	IControlsManager->AddModelsCollection(myControl);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(FADERHANDLEROFF_ID, FADERHANDLEROFF_FN);
	graphicType = GraphicsModel::FADERCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "Fader Handler OFF Osc1", 429, 210, 0.8, 0.0, 1.0, iGraphic, TRUE);
	IControlsManager->AddModelsCollection(myControl);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(FADERHANDLERON_ID, FADERHANDLERON_FN);
	graphicType = GraphicsModel::FADERCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "Fader Handler ON Osc2", 510, 210, 0.0, 0.0, 1.0, iGraphic, TRUE);
	IControlsManager->AddModelsCollection(myControl);

	pBitmap = IGraphicsManager->pGraphics->LoadIBitmap(FADERHANDLEROFF_ID, FADERHANDLEROFF_FN);
	graphicType = GraphicsModel::FADERCONTROL;
	iGraphic = new GraphicsModel(pBitmap, graphicType);
	myControl = new ControlsModel(this->moduleName, IControlsManager->Count(), ControlsModel::DOUBLE, "Fader Handler OFF Osc2", 510, 210, 0.0, 0.0, 1.0, iGraphic);
	IControlsManager->AddModelsCollection(myControl);
}

void ModGainFaders::doModelsControlsInIControlsCollection(IPlug* myOhmBass, controlsManager* iControlsManager, graphicsManager* iGraphicsManager, int i) {
	IBitmap graphic = iControlsManager->controlsModelsCollection[i]->graphicsModel->bitmap;
	IControl * control;

	switch (iControlsManager->controlsModelsCollection[i]->graphicsModel->graphicsType) {
	case GraphicsModel::BITMAPCONTROL:
		control = new IBitmapControl(myOhmBass, iControlsManager->controlsModelsCollection[i]->x, iControlsManager->controlsModelsCollection[i]->y, i, &graphic);
		break;
	case GraphicsModel::FADERCONTROL:
		control = new IFaderControl(myOhmBass, iControlsManager->controlsModelsCollection[i]->x, iControlsManager->controlsModelsCollection[i]->y, 210, i, &graphic, EDirection::kVertical);
		if (iControlsManager->controlsModelsCollection[i]->hide) {
			control->Hide(TRUE);
			control->GrayOut(TRUE/*, 0.99f*/);
		}
		break;
	}

	iControlsManager->AddControlsCollection(control);
	iGraphicsManager->pGraphics->AttachControl(control);
}

void ModGainFaders::fillSetOfFaders(controlsManager* iControlsManager) {
	for (int i = 0; i < iControlsManager->getKNumParams(); i++) {
		IParam * param;
		param = iControlsManager->controlsCollection[i]->GetParam();

		if (param != nullptr) {
			if (strcmp(param->GetNameForHost(), "Fader Handler ON Osc1") == 0) {
				mFadersHandlerOnOsc1 = i;
			}
			else if (strcmp(param->GetNameForHost(), "Fader Handler OFF Osc1") == 0) {
				mFadersHandlerOffOsc1 = i;
			}
			else if (strcmp(param->GetNameForHost(), "Fader Handler ON Osc2") == 0) {
				mFadersHandlerOnOsc2 = i;
			}
			else if (strcmp(param->GetNameForHost(), "Fader Handler OFF Osc2") == 0) {
				mFadersHandlerOffOsc2 = i;
			}
		}
		
	}
}

void ModGainFaders::OnParamChange(controlsManager* IControlsManager, int paramIdx, bool isPluginInitialized, IParam* param)
{
		if (paramIdx == mFadersHandlerOnOsc1) {
			ToggleFaders(IControlsManager, 1, paramIdx, param);
		}
		else if (paramIdx == mFadersHandlerOffOsc1) {
			ToggleFaders(IControlsManager, 1, paramIdx, param);
		}
		else if (paramIdx == mFadersHandlerOnOsc2) {
			ToggleFaders(IControlsManager, 2, paramIdx, param);
		}
		else if (paramIdx == mFadersHandlerOffOsc2) {
			ToggleFaders(IControlsManager, 2, paramIdx, param);
		}
}

void ModGainFaders::ToggleFaders(controlsManager* IControlsManager, int nOsc, int paramIdx, IParam* param)
{
	if (nOsc == 1) {
		if (paramIdx == mFadersHandlerOnOsc1) {
			IControlsManager->controlsCollection[mFadersHandlerOffOsc1]->SetValueFromPlug(param->Value());
			IControlsManager->controlsCollection[mFadersHandlerOnOsc1]->SetValueFromPlug(param->Value());
		}
		else if (paramIdx == mFadersHandlerOffOsc1) {
			IControlsManager->controlsCollection[mFadersHandlerOffOsc1]->Hide(TRUE);
			IControlsManager->controlsCollection[mFadersHandlerOffOsc1]->GrayOut(TRUE/*, 0.99f*/);

			IControlsManager->controlsCollection[mFadersHandlerOnOsc1]->Hide(FALSE);
			IControlsManager->controlsCollection[mFadersHandlerOnOsc1]->GrayOut(FALSE);

			IControlsManager->controlsCollection[mFadersHandlerOnOsc2]->Hide(TRUE);
			IControlsManager->controlsCollection[mFadersHandlerOnOsc2]->GrayOut(TRUE/*, 0.99f*/);

			IControlsManager->controlsCollection[mFadersHandlerOffOsc2]->Hide(FALSE);
			IControlsManager->controlsCollection[mFadersHandlerOffOsc2]->GrayOut(FALSE);

			IControlsManager->controlsCollection[mFadersHandlerOnOsc1]->SetValueFromPlug(param->Value());
			IControlsManager->controlsCollection[mFadersHandlerOffOsc1]->SetValueFromPlug(param->Value());
		}
	}
	else if (nOsc == 2) {
		if (paramIdx == mFadersHandlerOnOsc2) {
			IControlsManager->controlsCollection[mFadersHandlerOffOsc2]->SetValueFromPlug(param->Value());
			IControlsManager->controlsCollection[mFadersHandlerOnOsc2]->SetValueFromPlug(param->Value());
		}
		else if (paramIdx == mFadersHandlerOffOsc2) {
			IControlsManager->controlsCollection[mFadersHandlerOffOsc2]->Hide(TRUE);
			IControlsManager->controlsCollection[mFadersHandlerOffOsc2]->GrayOut(TRUE/*, 0.99f*/);

			IControlsManager->controlsCollection[mFadersHandlerOnOsc2]->Hide(FALSE);
			IControlsManager->controlsCollection[mFadersHandlerOnOsc2]->GrayOut(FALSE);

			IControlsManager->controlsCollection[mFadersHandlerOnOsc1]->Hide(TRUE);
			IControlsManager->controlsCollection[mFadersHandlerOnOsc1]->GrayOut(TRUE/*, 0.99f*/);

			IControlsManager->controlsCollection[mFadersHandlerOffOsc1]->Hide(FALSE);
			IControlsManager->controlsCollection[mFadersHandlerOffOsc1]->GrayOut(FALSE);

			IControlsManager->controlsCollection[mFadersHandlerOnOsc2]->SetValueFromPlug(param->Value());
			IControlsManager->controlsCollection[mFadersHandlerOffOsc2]->SetValueFromPlug(param->Value());
		}
	}
}
