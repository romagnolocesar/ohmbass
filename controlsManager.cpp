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
		param->SetShape(controlsModelsCollection[i]->shape);
	}
	for (int i = 0; i < kNumParams; i++) {
		myOhmBass->OnParamChange(i);
	}
}


int controlsManager::getKNumParams()
{
	//return this->kNumParams;
	return 48;
}



