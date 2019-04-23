#include <vector> using namespace std; 


class ModulesManager {
public:
	std::vector<class Modules * > collection;
	
	int Add(Modules* myInstance)
	{
			collection.push_back(myInstance);
			return (collection.size() - 1);
	}

	int Count(void)
	{
		return collection.size();
	}

private:

};