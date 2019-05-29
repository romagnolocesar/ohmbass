#include "ModulesModel.h"
#include "GraphicsModel.h"
#include <IPlugStructs.h>

//Customs Controls
#include "ITempoDisplay.h"
#include "IBezierControl.h"


class ControlsModel
{
public:
	static enum EControlsDataType {
		INT,
		DOUBLE,
		ENUM,
		NONE,
		BOOL
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
		GraphicsModel* graphicsModel,
		bool hide
	);
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
		GraphicsModel* graphicsModel,
		bool hide
	);
	//bezier
	ControlsModel(
		ModulesModel::EModulesName moduleName,
		int idx,
		EControlsDataType dataType,
		char* alias,
		float x,
		float y,
		float x2,
		float y2,
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
		GraphicsModel* graphicsModel,
		bool hide
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
		GraphicsModel* graphicsModel,
		bool hide
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
		int lenght,
		bool hide
	);

	void setShape(double shape);
	
	ModulesModel::EModulesName moduleName;
	int idx;
	char* alias;
	int x;
	int y;
	int x2;
	int y2;
	int lenght;
	double defaultVal;
	int defaultValEnum;
	double minVal;
	double maxVal;
	bool state;
	int Enums;
	bool hide = FALSE;
	double shape = 1.0;
	EControlsDataType dataType;
	GraphicsModel* graphicsModel;
};