#pragma once
#include <vector>
#include <algorithm>

class VectorLib
{
public:
	VectorLib();
	~VectorLib();

	//Find vector generic function
	template < typename T>
	std::pair<bool, int > findInVector(const std::vector<T>  & vecOfElements, const T  & element)
	{
		std::pair<bool, int > result;

		// Find given element in vector
		auto it = std::find(vecOfElements.begin(), vecOfElements.end(), element);

		if (it != vecOfElements.end())
		{
			result.second = distance(vecOfElements.begin(), it);
			result.first = true;
		}
		else
		{
			result.first = false;
			result.second = -1;
		}

		return result;
	}
	//END Find vector generic function
};



VectorLib::VectorLib()
{
}


VectorLib::~VectorLib()
{
}
