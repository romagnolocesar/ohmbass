#pragma once
#include "IPlug_include_in_plug_hdr.h"

class ITempoDisplay : public IControl
{
private:
	ITimeInfo* mTimeInfo;
	WDL_String mDisplay;

public:
	ITempoDisplay(IPlugBase* pPlug, IRECT pR, IText* pText, ITimeInfo* pTimeInfo)
		: IControl(pPlug, pR)
	{
		mText = *pText;
		mTimeInfo = pTimeInfo;
	}

	bool Draw(IGraphics* pGraphics)
	{
		mDisplay.SetFormatted(80, "Tempo: %f, SamplePos: %i, PPQPos: %f", mTimeInfo->mTempo, (int)mTimeInfo->mSamplePos, mTimeInfo->mPPQPos);
		return pGraphics->DrawIText(&mText, mDisplay.Get(), &mRECT);
	}


	bool IsDirty() { return true; }
};