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


//Add a Model into a Models Collection 
int controlsManager::AddModelsCollection(ControlsModel* myInstance)
{
	controlsModelsCollection.push_back(myInstance);
	return (controlsModelsCollection.size() - 1);
};

//Add a Control into a Controls Collection 
int controlsManager::AddControlsCollection(IControl* myInstance)
{
	controlsCollection.push_back(myInstance);
	return (controlsCollection.size() - 1);
}

//Add a group Control into a group Controls Collection 
void controlsManager::AddControlsGroupsCollection(std::string groupName){
	if (groupName != "") {
		bool isGroupExist = FALSE;
		int groupIdx = NULL;
		const std::string tempGroupName = groupName;

		//Check if group exist and get the index 
		for (int i = 0; i < controlsGroupsCollection.size(); i++)
		{
			std::string auxGroupNameCollection = controlsGroupsCollection.at(i);
			const std::string tempGroupNameCollection = auxGroupNameCollection;
			if (tempGroupNameCollection == tempGroupName) {
				groupIdx = i;
				isGroupExist = TRUE;
			}

		}

		//If the group was not initialized, initialize it in the group
		if (!isGroupExist) {
			controlsGroupsCollection.push_back(groupName);
			groupIdx = controlsGroupsCollection.size() - 1;
		}
	}
};

//Return quantity of Model's Controls in Controls Models Collection
int controlsManager::Count(void)
{
	return controlsModelsCollection.size();
};

//Create all need Params
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
				parameterStep
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

void controlsManager::fillControlsGroupCollection() {
	for (int i = 0; i < controlsModelsCollection.size(); i++)
	{
		AddControlsGroupsCollection(controlsModelsCollection[i]->getGroupName());
	}
	
}

//Return how much Params the Application has
int controlsManager::getKNumParams()
{
	//return this->kNumParams;
	return 51;
}



