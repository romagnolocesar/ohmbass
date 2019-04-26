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

	static enum EGraphicsType {
		RADIOBUTTONSCONTROL
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

	~ControlsModel();

	
	ModulesModel::EModulesName moduleName;
	int idx;
	char* alias;
	int x;
	int y;
	double defaultVal;
	int defaultValEnum;
	double minVal;
	double maxVal;
	bool state;
	EControlsDataType dataType;
	int Enums;
	GraphicsModel* graphicsModel;
};