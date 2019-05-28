#pragma once
#include "IPlug_include_in_plug_hdr.h"


class IBezierControl : public IControl
{
public:
	struct beziers {
		LICE_pixel color;
		float alpha;
	} beziers[1];

	IBezierControl(IPlugBase *pPlug, IRECT pR, int paramA, int paramB)
		: IControl(pPlug, pR)
	{
		AddAuxParam(paramA);
		AddAuxParam(paramB);
	}

	bool Draw(IGraphics* pGraphics)
	{
		/*double xpos = GetAuxParam(0)->mValue * mRECT.W();
		double ypos = GetAuxParam(1)->mValue * mRECT.H();*/

		/*LICE_DrawQBezier(pGraphics->GetDrawBitmap(), mRECT.MW(), mRECT.T, xpos + 5, ypos + 5, mRECT.MW(), mRECT.B, LICE_RGBA(0, 0, 0, 255), 0.5);
		LICE_DrawQBezier(pGraphics->GetDrawBitmap(), mRECT.MW(), mRECT.T, xpos, ypos, mRECT.MW(), mRECT.B, LICE_RGBA(255, 255, 255, 255));*/

		double xpos = GetAuxParam(0)->mValue;
		double ypos = GetAuxParam(1)->mValue;


		beziers[0].color = LICE_RGBA(0, 0, 0, 255);
		beziers[0].alpha = 0.5f;
		beziers[1].color = LICE_RGBA(255, 255, 255, 255);
		beziers[1].alpha = 1.0f;

		for (int i = 0; i < 2; i++)
		{
			LICE_DrawQBezier(pGraphics->GetDrawBitmap(), 562, 640, 600, 570, 803, 640, beziers[i].color, beziers[i].alpha);
		}
		

		return true;
	}

	void OnMouseDown(int x, int y, IMouseMod* pMod)
	{
		//return SnapToMouse(x, y);
	}

	void OnMouseDrag(int x, int y, int dX, int dY, IMouseMod* pMod)
	{
		//return SnapToMouse(x, y);
	}

	void SnapToMouse(int x, int y)
	{
		//GetAuxParam(0)->mValue = BOUNDED((double)x / (double)mRECT.W(), 0, 1);
		//GetAuxParam(1)->mValue = BOUNDED((double)y / (double)mRECT.H(), 0, 1);

		//SetDirty();
	}

	void SetDirty(bool pushParamToPlug = true)
	{
		//mDirty = true;

		//if (pushParamToPlug && mPlug)
		//{
		//	SetAllAuxParamsFromGUI();
		//}
	}
};
