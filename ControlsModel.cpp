#include "ControlsModel.h"
#include "Oscillator.h"

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

ControlsModel::ControlsModel(ModulesModel::EModulesName moduleName, int idx, EControlsDataType dataType, char* alias, int x, int y, int defaultValEnum, int Enums, GraphicsModel* graphicsModel)
{
	this->moduleName = moduleName;
	this->dataType = dataType;
	this->idx = idx;
	this->alias = alias;
	this->x = x;
	this->y = y;
	this->defaultValEnum = Oscillator::OSCILLATOR_MODE_TRIANGLE;
	this->Enums = Oscillator::kNumOscillatorModes;
	this->graphicsModel = graphicsModel;
}
			
ControlsModel::~ControlsModel()
{
}
