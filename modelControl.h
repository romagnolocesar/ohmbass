#pragma once
#include "Modules.h"
class modelControl
{
public:
	modelControl(Modules::EModulesName moduleName, int idx, char* alias, int x, int y, double defaultVal, double minVal, double maxVal);
	~modelControl();

	
	Modules::EModulesName moduleName;
	int idx;
	char* alias;
	int x;
	int y;
	double defaultVal;
	double minVal;
	double maxVal;
};

