#include "ControlsModel.h"



ControlsModel::ControlsModel(ModulesModel::EModulesName moduleName, int idx, EControlsDataType dataType, char* alias, int x, int y, double defaultVal, double minVal, double maxVal)
{
	this->moduleName = moduleName;
	this->idx = idx;
	this->dataType = dataType;
	this->alias = alias;
	this->x = x;
	this->y = y;
	this->defaultVal = defaultVal;
	this->minVal = minVal;
	this->maxVal = maxVal;
}

ControlsModel::ControlsModel(ModulesModel::EModulesName moduleName, int idx, EControlsDataType dataType, char* alias, int x, int y, bool state)
{
	this->moduleName = moduleName;
	this->dataType = dataType;
	this->idx = idx;
	this->alias = alias;
	this->x = x;
	this->y = y;
	this->state = state;
}


ControlsModel::~ControlsModel()
{
}
