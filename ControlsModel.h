#include "ModulesModel.h"
#include "GraphicsModel.h"
#include <IPlugStructs.h>

//Customs Controls
#include "ITempoDisplay.h"
#include "IBezierControl.h"

#include <string>


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
		ModulesModel::EModulesName moduleName,
		int idx,
		EControlsDataType dataType,
		char * alias,
		int L,
		int T,
		int R,
		int B,
		char * pText,
		GraphicsModel * graphicsModel,
		int textSize
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

	void setGroupName(std::string groupName);
	std::string getGroupName();
	
	ModulesModel::EModulesName moduleName;
	int idx;
	char* alias;
	int x;
	int y;
	int x2;
	int y2;
	int L, T, R, B;
	char* pText;
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
	std::string groupName;
	int textSize;
};