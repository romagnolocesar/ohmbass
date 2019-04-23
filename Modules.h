#pragma once

class Modules
{
public:
	static enum EModulesType {
		EQUILIBRIUM,
	};

	Modules::Modules(){}
	Modules::~Modules() {}

	EModulesType myType;
};

