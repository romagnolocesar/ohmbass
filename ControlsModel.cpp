#include "ControlsModel.h"
#include "Oscillator.h"

ControlsModel::ControlsModel(ModulesModel::EModulesName moduleName, int idx, ControlsModel::EControlsDataType dataType, char* alias, int x, int y, double defaultVal, double minVal, double maxVal, GraphicsModel* graphicsModel, bool hide)
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
	this->hide = hide;
	this->graphicsModel = graphicsModel;
}

ControlsModel::ControlsModel(ModulesModel::EModulesName moduleName, int idx, ControlsModel::EControlsDataType dataType, char* alias, int x, int y, double defaultVal, double minVal, double maxVal, GraphicsModel* graphicsModel)
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
	this->graphicsModel = graphicsModel;
}

ControlsModel::ControlsModel(ModulesModel::EModulesName moduleName, int idx, ControlsModel::EControlsDataType dataType, char* alias, int x, int y, GraphicsModel* graphicsModel, bool hide)
{
	this->moduleName = moduleName;
	this->dataType = dataType;
	this->idx = idx;
	this->alias = alias;
	this->x = x;
	this->y = y;
	this->graphicsModel = graphicsModel;
	this->hide = hide;
}

ControlsModel::ControlsModel(ModulesModel::EModulesName moduleName, int idx, ControlsModel::EControlsDataType dataType, char* alias, int x, int y, bool state, GraphicsModel* graphicsModel, bool hide)
{
	this->moduleName = moduleName;
	this->dataType = dataType;
	this->idx = idx;
	this->alias = alias;
	this->x = x;
	this->y = y;
	this->state = state;
	this->graphicsModel = graphicsModel;
	this->hide = hide;
}

ControlsModel::ControlsModel(ModulesModel::EModulesName moduleName, int idx, ControlsModel::EControlsDataType dataType, char* alias, int x, int y, bool state, GraphicsModel* graphicsModel)
{
	this->moduleName = moduleName;
	this->dataType = dataType;
	this->idx = idx;
	this->alias = alias;
	this->x = x;
	this->y = y;
	this->state = state;
	this->graphicsModel = graphicsModel;
}

ControlsModel::ControlsModel(ModulesModel::EModulesName moduleName, int idx, EControlsDataType dataType, char* alias, int x, int y, int defaultValEnum, int Enums, GraphicsModel* graphicsModel, bool hide)
{
	this->moduleName = moduleName;
	this->dataType = dataType;
	this->idx = idx;
	this->alias = alias;
	this->x = x;
	this->y = y;
	this->defaultValEnum = defaultValEnum;
	this->Enums = Enums;
	this->graphicsModel = graphicsModel;
	this->hide = hide;
}

ControlsModel::ControlsModel(GraphicsModel * graphicsModel, int idx, ModulesModel::EModulesName moduleName, EControlsDataType dataType, char * alias, int x, int y, int lenght, bool hide)
{
	this->moduleName = moduleName;
	this->dataType = dataType;
	this->idx = idx;
	this->alias = alias;
	this->x = x;
	this->y = y;
	this->lenght = lenght;
	this->graphicsModel = graphicsModel;
	this->hide = hide;
}

void ControlsModel::setShape(double shape) {
	this->shape = shape;
}
			