#pragma once
#include "IPlug_include_in_plug_hdr.h"

class IEQLineDisplay : public IControl
{
private:
	
public:
	IEQLineDisplay(IPlugBase* pPlug, IRECT pR)
		: IControl(pPlug, pR)
	{
		
	}

	bool Draw(IGraphics* pGraphics)
	{
		const IColor COLOR_WHITE(255, 255, 255, 255);
		return pGraphics->DrawHorizontalLine(&COLOR_WHITE, &mRECT, 1.3f);
		//return pGraphics->DrawRadialLine(&COLOR_WHITE,)
	}


	bool IsDirty() { return true; }
};