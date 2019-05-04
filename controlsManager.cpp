#include "OhmBass.h"
#include "controlsManager.h"

void controlsManager::addParam(
	ModulesModel::EModulesName moduleName,
	char* alias,
	ControlsModel::EControlsDataType dataType,
	int x,
	int y,
	double defaultVal,
	double minVal,
	double maxVal,
	GraphicsModel* graphicsModel,
	EDirection mDirection,
	bool hide
){
	int idx = this->Count();
	ControlsModel* myControl = new ControlsModel(moduleName, idx, dataType, alias, x, y, defaultVal, minVal, maxVal, graphicsModel, hide);
	
	this->AddModelsCollection(myControl);
};

void controlsManager::addParam(
	ModulesModel::EModulesName moduleName,
	char* alias,
	ControlsModel::EControlsDataType dataType,
	int x,
	int y,
	bool state,
	GraphicsModel* graphicsModel,
	bool hide
) {
	int idx = this->Count();
	ControlsModel* myControl = new ControlsModel(moduleName, idx, dataType, alias, x, y, state, graphicsModel, hide);
	this->AddModelsCollection(myControl);
};

void controlsManager::addParam(
	ModulesModel::EModulesName moduleName,
	char* alias,
	ControlsModel::EControlsDataType dataType,
	int x,
	int y,
	int defaultValEnum,
	int Enums,
	GraphicsModel* graphicsModel,
	bool hide
) {
	int idx = this->Count();
	ControlsModel* myControl = new ControlsModel(moduleName, idx, dataType, alias, x, y, defaultValEnum, Enums, graphicsModel, hide);
	this->AddModelsCollection(myControl);
}



int controlsManager::AddModelsCollection(ControlsModel* myInstance)
{
	controlsModelsCollection.push_back(myInstance);
	return (controlsModelsCollection.size() - 1);
};

int controlsManager::AddControlsCollection(IControl* myInstance)
{
	controlsCollection.push_back(myInstance);
	return (controlsCollection.size() - 1);
};

int controlsManager::Count(void)
{
	return controlsModelsCollection.size();
};

void controlsManager::createParams(IPlug* myOhmBass)
{
	for (int i = 0; i < kNumParams; i++) {
		IParam* param = myOhmBass->GetParam(i);
		switch (controlsModelsCollection[i]->dataType) {
		case ControlsModel::DOUBLE:
			param->InitDouble(
				controlsModelsCollection[i]->alias,
				controlsModelsCollection[i]->defaultVal,
				controlsModelsCollection[i]->minVal,
				controlsModelsCollection[i]->maxVal,
				1
			);
			break;
		case ControlsModel::INT:
			param->InitInt(
				controlsModelsCollection[i]->alias,
				controlsModelsCollection[i]->defaultVal,
				controlsModelsCollection[i]->minVal,
				controlsModelsCollection[i]->maxVal,
				controlsModelsCollection[i]->alias
			);
			break;
		case ControlsModel::ENUM:
			param->InitEnum(
				controlsModelsCollection[i]->alias,
				controlsModelsCollection[i]->defaultValEnum,
				controlsModelsCollection[i]->Enums
			);
			break;
		default:
			param->InitDouble(
				controlsModelsCollection[i]->alias,
				controlsModelsCollection[i]->defaultVal,
				controlsModelsCollection[i]->minVal,
				controlsModelsCollection[i]->maxVal,
				parameterStep
			);
		}
		//param->SetShape(controlsModelsCollection[i]->shape);
	}
	for (int i = 0; i < kNumParams; i++) {
		myOhmBass->OnParamChange(i);
	}
}
	

	//for (int i = 0; i < kNumParams; i++) {
	//	IParam* param = myOhmBass->GetParam(i);
	//	parameterProperties_struct properties = this->getParameterProperties(i);
	//	switch (i) {
	//	case mBgBtnOscWavesOsc1:
	//		param->InitInt(properties.name, 1, 1, 4, "osc1waves");
	//		break;
	//	case mBgBtnOscWavesOsc2:
	//		param->InitInt(properties.name, 1, 1, 4, "osc2waves");
	//		break;
	//		//Faders Oscillators
	//	case mFadersGlowOsc1:
	//		param->InitDouble(properties.name, properties.defaultVal, properties.minVal, properties.maxVal, 1);
	//		break;
	//	case mFadersGlowOsc2:
	//		param->InitDouble(properties.name, properties.defaultVal, properties.minVal, properties.maxVal, 1);
	//		break;
	//	case mFadersHandlerOffOsc1:
	//		param->InitDouble(properties.name, properties.defaultVal, properties.minVal, properties.maxVal, 1);
	//		break;
	//	case mFadersHandlerOffOsc2:
	//		param->InitDouble(properties.name, properties.defaultVal, properties.minVal, properties.maxVal, 1);
	//		break;
	//	case mFadersHandlerOnOsc1:
	//		param->InitDouble(properties.name, properties.defaultVal, properties.minVal, properties.maxVal, 1);
	//		break;
	//	case mFadersHandlerOnOsc2:
	//		param->InitDouble(properties.name, properties.defaultVal, properties.minVal, properties.maxVal, 1);
	//		break;
	//	case mLFOWaveform:
	//		param->InitEnum(properties.name,
	//			Oscillator::OSCILLATOR_MODE_TRIANGLE,
	//			Oscillator::kNumOscillatorModes);
	//		// For VST3:
	//		param->SetDisplayText(0, properties.name);
	//		break;
	//	case mFilterMode:
	//		param->InitEnum(properties.name,
	//			Filter::FILTER_MODE_LOWPASS,
	//			Filter::kNumFilterModes);
	//		break;
	//	//GHRR PLACE
	//		//eQ-Librium
	//	case mGhrtab1:
	//		param->InitDouble(properties.name, properties.defaultVal, properties.minVal, properties.maxVal, 1);
	//		break;
	//	case mGhrEqlOnTitle:
	//		param->InitDouble(properties.name, properties.defaultVal, properties.minVal, properties.maxVal, 1);
	//		break;
	//	case mGhrEqlLowFreq:
	//		param->InitDouble(properties.name, properties.defaultVal, properties.minVal, properties.maxVal, 1);
	//		break;
	//	case mGhrBostLowFreq:
	//		param->InitDouble(properties.name, properties.defaultVal, properties.minVal, properties.maxVal, 1);
	//		break;
	//	case mGhrEqlHihgFreq:
	//		param->InitDouble(properties.name, properties.defaultVal, properties.minVal, properties.maxVal, 1);
	//		break;
	//	case mGhrShelfHihgFreq:
	//		param->InitDouble(properties.name, properties.defaultVal, properties.minVal, properties.maxVal, 1);
	//		break;
	//	default:
	//		param->InitDouble(properties.name,
	//			properties.defaultVal,
	//			properties.minVal,
	//			properties.maxVal,
	//			parameterStep);
	//		break;
	//	}
	//}

	//myOhmBass->GetParam(mFilterCutoff)->SetShape(2);
	//myOhmBass->GetParam(mVolumeEnvAttack)->SetShape(3);
	//myOhmBass->GetParam(mFilterEnvAttack)->SetShape(3);
	//myOhmBass->GetParam(mVolumeEnvDecay)->SetShape(3);
	//myOhmBass->GetParam(mFilterEnvDecay)->SetShape(3);
	//myOhmBass->GetParam(mVolumeEnvSustain)->SetShape(2);
	//myOhmBass->GetParam(mFilterEnvSustain)->SetShape(2);
	//myOhmBass->GetParam(mVolumeEnvRelease)->SetShape(3);
	//myOhmBass->GetParam(mFilterEnvRelease)->SetShape(3);

	//for (int i = 0; i < kNumParams; i++) {
	//	myOhmBass->OnParamChange(i);
	//}


int controlsManager::getKNumParams()
{
	//return this->kNumParams;
	return 41;
}



