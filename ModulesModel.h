class ModulesModel
{
public:
	static enum EModulesName {
		OSCILATORS,
		GAINFADERS,
		FILTERS,
		AMPENVELOPE,
		FILTERENVELOPE,
		EQUILIBRIUM

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

