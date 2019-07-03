class ModulesModel
{
public:
	static enum EModulesName {
		OSCILATORS,
		GAINFADERS,
		FILTERS,
		AMPENVELOPE,
		FILTERENVELOPE,
		EQUILIBRIUM,
		CONFLFO,
		TOOLSBAR

	};

	enum EModulesOnOff {
		OFF = 0,
		ON,
		kNumModulesOnOff

	};

	ModulesModel::ModulesModel(){}
	ModulesModel::~ModulesModel() {}

	EModulesName moduleName;
};

