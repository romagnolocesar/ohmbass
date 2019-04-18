//
//  MyParameters.h
//  OhmBass


#ifndef __OhmBass__MyParameters__
#define __OhmBass__MyParameters__

class MyParameters
{
public:
	MyParameters();
	virtual ~MyParameters();

	void setName(char name);
	char getName();

	void setX(int x);
	int getX();

	void setY(int y);
	int getY();

	void setDefaultVal(double defaultVal);
	double setDefaultVal();

	void setMinValue(double minVal);
	double getMinValue();

	void setMaxValue(double maxVal);
	double getMaxValue();

	void setHidden(bool isHidden);
	bool getHidden();


private:
	char name;
	int x;
	int y;
	double defaultVal;
	double minVal;
	double maxVal;
	bool isHidden;
};

#endif
