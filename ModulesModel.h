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

	ModulesModel::ModulesModel(){}
	ModulesModel::~ModulesModel() {}

	EModulesName moduleName;
};

