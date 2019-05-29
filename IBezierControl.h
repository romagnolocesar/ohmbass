#pragma once
#include "IPlug_include_in_plug_hdr.h"
#include <algorithm>


class IBezierControl : public IControl
{
public:
	bool showPoints = FALSE;
	
	//LowBell
	int lowBell[7][2];
	float lowBellFreq;
	float lowBellGain;

	//HighBell
	int highBell[7][2];
	float highBellFreq;
	float highBellGain;

	//Groups


	//Wrapper (container)
	int wrapperXstart, wrapperYstart, wrapperXend, wrapperYend;

	//Dimensions
	int wrapperWidth, wrapperHeight;

	//Paddings
	int paddingTop = 10, paddingRight = 10, paddingBottom = 10, paddingLeft = 10;

	int minX, minY, maxX, maxY;


	IBezierControl(IPlugBase *pPlug, IRECT pR)
		: IControl(pPlug, pR)
	{
		this->wrapperXstart = pR.L;
		this->wrapperYstart = pR.T;
		this->wrapperXend = pR.R;
		this->wrapperYend = pR.B;
		this->wrapperWidth = pR.R - pR.L;
		this->wrapperHeight = pR.B - pR.T;
		setRangeLock();

	}

	void setRangeLock() {
		this->minX = this->wrapperXstart + this->paddingLeft;
		this->minY = this->wrapperYstart + this->paddingTop;
		this->maxX = this->wrapperXend - this->paddingRight;
		this->maxY = this->wrapperYend - this->paddingBottom;
	}

	bool Draw(IGraphics* pGraphics)
	{
		//Bezier default position
		int bezierXstartFixed = wrapperXstart + paddingLeft;
		int bezierXstart = ((wrapperXstart + paddingLeft) - 32) + (this->lowBellFreq*0.2);
		int bezierYstart = (wrapperYstart + paddingTop);
		int bezierXend = wrapperXend - paddingRight;
		int bezierYend = wrapperYend - paddingBottom;
		int bezierWidth = bezierXend - bezierXstartFixed;
		int bezierHeight = bezierYend - bezierYstart;
		int bezierXstartHigh = ((bezierXstartFixed + paddingLeft) + bezierWidth/3 + (this->highBellFreq*0.2) / 2.3);	



		//====================LOW KNOB================================
		//RATIOS LOW BELL
		float lowBellFreqRatio = this->lowBellFreq*0.2; //LowBellGain
		float lowBellGainRatio = this->lowBellGain * bezierHeight*0.1; //LowBellGain

		double unityVariance = bezierWidth * 0.05 + (lowBellFreqRatio/20);


		lowBell[0][0] = bezierXstart;
		lowBell[0][1] = bezierYend;

		lowBell[1][0] = bezierXstart + (unityVariance * 2);
		lowBell[1][1] = bezierYend;

		lowBell[2][0] = bezierXstart + (unityVariance * 1);
		lowBell[2][1] = (bezierYstart + bezierHeight) - lowBellGainRatio;
	
		lowBell[3][0] = bezierXstart + (unityVariance * 3);
		lowBell[3][1] = (bezierYstart + bezierHeight) - lowBellGainRatio;

		lowBell[4][0] = bezierXstart + (unityVariance * 5);
		lowBell[4][1] = (bezierYstart + bezierHeight) - lowBellGainRatio;

		lowBell[5][0] = bezierXstart + (unityVariance * 4);
		lowBell[5][1] = bezierYend;

		lowBell[6][0] = bezierXstart + (unityVariance * 6);
		lowBell[6][1] = bezierYend;

		//====================HIGH KNOB================================
		//RATIOS HIGH BELL
		float highBellFreqRatio = this->highBellFreq*0.2; //LowBellGain
		float highBellGainRatio = this->highBellGain * bezierHeight*0.1; //LowBellGain

		double highUnityVariance = bezierWidth * 0.03 + (highBellFreqRatio / 20);


		highBell[0][0] = bezierXstartHigh;
		highBell[0][1] = bezierYend;

		highBell[1][0] = bezierXstartHigh + (highUnityVariance * 2);
		highBell[1][1] = bezierYend;

		highBell[2][0] = bezierXstartHigh + (highUnityVariance * 1);
		highBell[2][1] = (bezierYstart + bezierHeight) - highBellGainRatio;

		highBell[3][0] = bezierXstartHigh + (highUnityVariance * 3);
		highBell[3][1] = (bezierYstart + bezierHeight) - highBellGainRatio;

		highBell[4][0] = bezierXstartHigh + (highUnityVariance * 5);
		highBell[4][1] = (bezierYstart + bezierHeight) - highBellGainRatio;

		highBell[5][0] = bezierXstartHigh + (highUnityVariance * 4);
		highBell[5][1] = bezierYend;

		highBell[6][0] = bezierXstartHigh + (highUnityVariance * 6);
		highBell[6][1] = bezierYend;
		


		//----------- LINE ------------------
		LICE_Line(pGraphics->GetDrawBitmap(), bezierXstartFixed, bezierYend, lowBell[0][0], lowBell[0][1], LICE_RGBA(0, 0, 0, 255), 0.5);
		LICE_Line(pGraphics->GetDrawBitmap(), bezierXstartFixed, bezierYend, lowBell[0][0], lowBell[0][1], LICE_RGBA(255, 255, 255, 255));

		//-----------LOW BELL ------------------
		//BEZIER1
		LICE_DrawCBezier(pGraphics->GetDrawBitmap(), lowBell[0][0], lowBell[0][1], lowBell[1][0], lowBell[1][1], lowBell[2][0], lowBell[2][1], lowBell[3][0], lowBell[3][1], LICE_RGBA(0, 0, 0, 255), 0.5);
		LICE_DrawCBezier(pGraphics->GetDrawBitmap(), lowBell[0][0], lowBell[0][1], lowBell[1][0], lowBell[1][1], lowBell[2][0], lowBell[2][1], lowBell[3][0], lowBell[3][1], LICE_RGBA(255, 255, 255, 255));

		//BEZIER2
		LICE_DrawCBezier(pGraphics->GetDrawBitmap(), lowBell[3][0], lowBell[3][1], lowBell[4][0], lowBell[4][1], lowBell[5][0], lowBell[5][1], lowBell[6][0], lowBell[6][1], LICE_RGBA(0, 0, 0, 255), 0.5);
		LICE_DrawCBezier(pGraphics->GetDrawBitmap(), lowBell[3][0], lowBell[3][1], lowBell[4][0], lowBell[4][1], lowBell[5][0], lowBell[5][1], lowBell[6][0], lowBell[6][1], LICE_RGBA(255, 255, 255, 255));



		//----------- LINE MIDDLE------------------
		LICE_Line(pGraphics->GetDrawBitmap(), lowBell[6][0], lowBell[6][1], highBell[0][0], highBell[0][1], LICE_RGBA(0, 0, 0, 255), 0.5);
		LICE_Line(pGraphics->GetDrawBitmap(), lowBell[6][0], lowBell[6][1], highBell[0][0], highBell[0][1], LICE_RGBA(255, 255, 255, 255));




		//-----------HIGH BELL ------------------
		//BEZIER1
		LICE_DrawCBezier(pGraphics->GetDrawBitmap(), highBell[0][0], highBell[0][1], highBell[1][0], highBell[1][1], highBell[2][0], highBell[2][1], highBell[3][0], highBell[3][1], LICE_RGBA(0, 0, 0, 255), 0.5);
		LICE_DrawCBezier(pGraphics->GetDrawBitmap(), highBell[0][0], highBell[0][1], highBell[1][0], highBell[1][1], highBell[2][0], highBell[2][1], highBell[3][0], highBell[3][1], LICE_RGBA(255, 255, 255, 255));

		//BEZIER2
		LICE_DrawCBezier(pGraphics->GetDrawBitmap(), highBell[3][0], highBell[3][1], highBell[4][0], highBell[4][1], highBell[5][0], highBell[5][1], highBell[6][0], highBell[6][1], LICE_RGBA(0, 0, 0, 255), 0.5);
		LICE_DrawCBezier(pGraphics->GetDrawBitmap(), highBell[3][0], highBell[3][1], highBell[4][0], highBell[4][1], highBell[5][0], lowBell[5][1], highBell[6][0], highBell[6][1], LICE_RGBA(255, 255, 255, 255));


		//----------- LINE END ------------------
		LICE_Line(pGraphics->GetDrawBitmap(), highBell[6][0], highBell[6][1], wrapperXend, bezierYend, LICE_RGBA(0, 0, 0, 255), 0.5);
		LICE_Line(pGraphics->GetDrawBitmap(), highBell[6][0], highBell[6][1], wrapperXend, bezierYend, LICE_RGBA(255, 255, 255, 255));



		if (this->showPoints) {
			//POINTERS 
			LICE_Circle(pGraphics->GetDrawBitmap(), lowBell[0][0], lowBell[0][1], 2, LICE_RGBA(255, 0, 0, 0));
			LICE_Circle(pGraphics->GetDrawBitmap(), lowBell[1][0], lowBell[1][1], 2, LICE_RGBA(0, 255, 0, 0));
			LICE_Circle(pGraphics->GetDrawBitmap(), lowBell[2][0], lowBell[2][1], 2, LICE_RGBA(0, 0, 255, 0));
			LICE_Circle(pGraphics->GetDrawBitmap(), lowBell[3][0], lowBell[3][1], 2, LICE_RGBA(255, 0, 255, 0));
			LICE_Circle(pGraphics->GetDrawBitmap(), lowBell[4][0], lowBell[4][1], 2, LICE_RGBA(255, 0, 0, 0));
			LICE_Circle(pGraphics->GetDrawBitmap(), lowBell[5][0], lowBell[5][1], 2, LICE_RGBA(0, 255, 0, 0));
			LICE_Circle(pGraphics->GetDrawBitmap(), lowBell[6][0], lowBell[6][1], 2, LICE_RGBA(255, 0, 255, 0));

			LICE_Circle(pGraphics->GetDrawBitmap(), highBell[0][0], highBell[0][1], 2, LICE_RGBA(255, 0, 0, 0));
			LICE_Circle(pGraphics->GetDrawBitmap(), highBell[1][0], highBell[1][1], 2, LICE_RGBA(0, 255, 0, 0));
			LICE_Circle(pGraphics->GetDrawBitmap(), highBell[2][0], highBell[2][1], 2, LICE_RGBA(0, 0, 255, 0));
			LICE_Circle(pGraphics->GetDrawBitmap(), highBell[3][0], highBell[3][1], 2, LICE_RGBA(255, 0, 255, 0));
			LICE_Circle(pGraphics->GetDrawBitmap(), highBell[4][0], highBell[4][1], 2, LICE_RGBA(255, 0, 0, 0));
			LICE_Circle(pGraphics->GetDrawBitmap(), highBell[5][0], highBell[5][1], 2, LICE_RGBA(0, 255, 0, 0));
			LICE_Circle(pGraphics->GetDrawBitmap(), highBell[6][0], highBell[6][1], 2, LICE_RGBA(255, 0, 255, 0));
		}


		
		return true;
	}

	void OnMouseDown(int x, int y, IMouseMod* pMod)
	{
		/*return SnapToMouse(x, y);*/
	}

	void OnMouseDrag(int x, int y, int dX, int dY, IMouseMod* pMod)
	{
		/*return SnapToMouse(x, y);*/
	}

	void SnapToMouse(int x, int y)
	{
		/*GetAuxParam(0)->mValue = BOUNDED((double)x / (double)mRECT.W(), 0, 1);
		GetAuxParam(1)->mValue = BOUNDED((double)y / (double)mRECT.H(), 0, 1);

		SetDirty();*/
	}

	void SetDirty(bool pushParamToPlug = true)
	{
		/*mDirty = true;

		if (pushParamToPlug && mPlug)
		{
			SetAllAuxParamsFromGUI();
		}*/
	}

	bool IsDirty() { return true; }
};
