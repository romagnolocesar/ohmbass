#ifndef CONTROLSMODEL_H
#define CONTROLSMODEL_H
#pragma once
#include "ControlsModel.h"
#include "IPlug_include_in_plug_hdr.h"

//Load Modules
#include <vector> using namespace std; 

class controlsManager{
public:
	const double parameterStep = 0.001;
	std::vector<class ControlsModel * > controlsModelsCollection;
	std::vector<class IControl * > controlsCollection;

	std::vector<std::string> controlsGroupsCollection;
	//std::vector<char, std::vector<class IControl * >> wrapperControlsAndGroupsCollection;


	int kNumParams = getKNumParams();

	void addParam(
		ModulesModel::EModulesName moduleName, 
		char* alias, 
		ControlsModel::EControlsDataType dataType,
		int x, 
		int y, 
		double defaultVal, 
		double minVal, 
		double maxVal, 
		GraphicsModel* graphicsModel,
		bool hide = FALSE
	);

	void addParam(
		ModulesModel::EModulesName moduleName, 
		char* alias, 
		ControlsModel::EControlsDataType dataType, 
		int x, 
		int y, 
		bool state,
		GraphicsModel* graphicsModel,
		bool hide = FALSE
	);

	void addParam(
		ModulesModel::EModulesName moduleName, 
		char* alias, 
		ControlsModel::EControlsDataType dataType, 
		int x, 
		int y, 
		int defaultValEnum, 
		int Enums,
		GraphicsModel* graphicsModel,
		bool hide = FALSE
);


	int AddModelsCollection(ControlsModel* myInstance);
	int AddControlsCollection(IControl* myInstance);
	void AddControlsGroupsCollection(std::string groupName);

	int Count(void);

	void createParams(IPlug* myOhmBass);
	void fillControlsGroupCollection();
	static int getKNumParams();

private:

};
#endif