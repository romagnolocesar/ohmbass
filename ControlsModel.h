#pragma once
#include "ModulesModel.h"
class ControlsModel
{
public:
	static enum EControlsDataType {
		INT,
		DOUBLE,
		NONE
	};

	ControlsModel(ModulesModel::EModulesName moduleName, int idx, EControlsDataType dataType, char* alias, int x, int y, double defaultVal, double minVal, double maxVal);
	ControlsModel(ModulesModel::EModulesName moduleName, int idx, EControlsDataType dataType, char* alias, int x, int y, bool state);
	~ControlsModel();

	
	ModulesModel::EModulesName moduleName;
	int idx;
	char* alias;
	int x;
	int y;
	double defaultVal;
	double minVal;
	double maxVal;
	bool state;
	EControlsDataType dataType;
};

