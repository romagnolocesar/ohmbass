#pragma once
#include "IControl.h"
class myFaderControl :
	public IControl
{
public:
	myFaderControl(IPlugBase *pPlug, IRECT pR, int handleRadius, int paramA, int paramB)
	: IControl(pPlug, pR){
	
	}
	~myFaderControl();
};

