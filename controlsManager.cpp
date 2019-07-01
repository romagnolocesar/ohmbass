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
		for (int i = 0; i < controlsGroupsNamesCollection.size(); i++)
		{
			std::string auxGroupNameCollection = controlsGroupsNamesCollection.at(i);
			const std::string tempGroupNameCollection = auxGroupNameCollection;
			if (tempGroupNameCollection == tempGroupName) {
				groupIdx = i;
				isGroupExist = TRUE;
			}

		}

		//If the group was not initialized, initialize it in the group
		if (!isGroupExist) {
			controlsGroupsNamesCollection.push_back(groupName);
			groupIdx = controlsGroupsNamesCollection.size() - 1;
		}
	}
};

//Return quantity of Model's Controls in Controls Models Collection
int controlsManager::Count(void)
{
	return controlsModelsCollection.size();
};

//Load Modal Background
void controlsManager::LoadModalStructure(IPlug* myOhmBass, IGraphics* pGraphics)
{
	IBitmap modalBackground;
	modalBackground = pGraphics->LoadIBitmap(MODAL_BG_ID, MODAL_BG_FN);
	this->modalBackgroundControl = new IBitmapControl(myOhmBass, 0, 0, -1, &modalBackground);
	pGraphics->AttachControl(this->modalBackgroundControl);

	hideModalBackground();
}

//Show ModalBackground
void controlsManager::showModalBackground()
{
	this->modalBackgroundControl->Hide(FALSE);
}

//Hide ModalBackground
void controlsManager::hideModalBackground()
{
	this->modalBackgroundControl->Hide(TRUE);
}



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

void controlsManager::fillWrapperControlsGroupCollection() {
	for (int i = 0; i < controlsGroupsNamesCollection.size(); i++)
	{
		std::vector<class IControl *> tempListControls;	
		for (int j = 0; j < controlsModelsCollection.size(); j++)
		{
			
			if (controlsGroupsNamesCollection[i] == controlsModelsCollection[j]->getGroupName()) {
				tempListControls.push_back(controlsCollection[j]);
			}
		}
		wrapperControlsAndGroupsCollection[controlsGroupsNamesCollection[i]].swap(tempListControls);
	}
	

}

//Return how much Params the Application has
int controlsManager::getKNumParams()
{
	//return this->kNumParams;
	return 71;
}



