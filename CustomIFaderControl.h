#pragma once
#include "IControl.h"
class CustomIFaderControl :
	public IControl
{
public:
	CustomIFaderControl(IPlugBase* pPlug, int x, int y, int len, int paramIdx, IBitmap* pBitmap, EDirection direction, bool onlyHandle)
		: IControl(pPlug, pR)
	{
		
	}
	~CustomIFaderControl();
};

