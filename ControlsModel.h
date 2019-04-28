#include "ModulesModel.h"
#include "GraphicsModel.h"
#include <IPlugStructs.h>


class ControlsModel
{
public:
	static enum EControlsDataType {
		INT,
		DOUBLE,
		ENUM,
		NONE
	};

	ControlsModel(
		ModulesModel::EModulesName moduleName,
		int idx,
		EControlsDataType dataType,
		char* alias,
		int x,
		int y,
		double defaultVal,
		double minVal,
		double maxVal,
		GraphicsModel* graphicsModel
	);
	ControlsModel(
		ModulesModel::EModulesName moduleName,
		int idx,
		EControlsDataType dataType,
		char* alias,
		int x,
		int y,
		bool state,
		GraphicsModel* graphicsModel
	);
	ControlsModel(
		ModulesModel::EModulesName moduleName,
		int idx,
		EControlsDataType dataType,
		char* alias,
		int x,
		int y,
		int defaultValEnum,
		int Enums,
		GraphicsModel* graphicsModel
	);
	ControlsModel(
		GraphicsModel* graphicsModel,
		int idx,
		ModulesModel::EModulesName moduleName,
		EControlsDataType dataType,
		char* alias,
		int x,
		int y,
		int lenght	
	);

	~ControlsModel();

	
	ModulesModel::EModulesName moduleName;
	int idx;
	char* alias;
	int x;
	int y;
	int lenght;
	double defaultVal;
	int defaultValEnum;
	double minVal;
	double maxVal;
	bool state;
	int Enums;
	EControlsDataType dataType;
	GraphicsModel* graphicsModel;
};