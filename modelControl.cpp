#include "modelControl.h"



modelControl::modelControl(Modules::EModulesName moduleName, int idx, char* alias, int x, int y, double defaultVal, double minVal, double maxVal)
{
	this->moduleName = moduleName;
	this->idx = idx;
	this->alias = alias;
	this->x = x;
	this->y = y;
	this->defaultVal = defaultVal;
	this->minVal = minVal;
	this->maxVal = maxVal;
}


modelControl::~modelControl()
{
}
