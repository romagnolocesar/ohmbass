#pragma once

class ModulesModel
{
public:
	static enum EModulesName {
		EQUILIBRIUM,
		OSCILATORS
	};

	ModulesModel::ModulesModel(){}
	ModulesModel::~ModulesModel() {}

	EModulesName moduleName;
};

