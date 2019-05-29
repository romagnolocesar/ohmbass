#pragma once
#include "IPlug_include_in_plug_hdr.h"
#include <algorithm>


class IBezierControl : public IControl
{
public:
	bool showPoints = FALSE;
	float xstart;
	float ystart;
	float xctl;
	float yctl;
	float xend;
	float yend;

	//Set Properties
	void setxStart(float xstart) {
		this->xstart = xstart;
	}

	void setyStart(float ystart) {
		this->ystart = ystart;
	}

	void setxctl(float xctl) {
		this->xctl = xctl;
	}

	void setyctl(float yctl) {
		this->yctl = yctl;
	}

	void setxend(float xend) {
		this->xend = xend;
	}

	void setyend(float yend) {
		this->yend = yend;
	}

	//Get Properties
	float getxStart() {
		return this->xstart;
	}

	float getyStart() {
		return this->ystart;
	}

	float getxctl() {
		return this->ystart;
	}

	float getyctl() {
		return this->ystart;
	}

	float getxend() {
		return this->xend;
	}

	float getyend() {
		return this->yend;
	}


	IBezierControl(IPlugBase *pPlug, IRECT pR, float xstart, float ystart, float xctl, float yctl, float xend, float yend)
		: IControl(pPlug, pR)
	{
		this->xstart = xstart;
		this->ystart = ystart;
		this->xctl = xctl;
		this->yctl = yctl;
		this->xend = xend;
		this->yend = yend;
	}

	bool Draw(IGraphics* pGraphics)
	{

		//Wrapper (container)
		int wrapperXstart = 555;
		int wrapperYstart = 570;
		int wrapperXend = 815;
		int wrapperYend = 645;

		//Dimensions
		int wrapperWidth = wrapperXend - wrapperXstart;
		int wrapperHeight = wrapperYend - wrapperYstart;

		//Paddings
		int paddingTop = 10;
		int paddingRight = 10;
		int paddingBottom = 10;
		int paddingLeft = 10;

		//Range Lock
		int minX = wrapperXstart + paddingLeft;
		int minY = wrapperYstart + paddingTop;
		int maxX = wrapperXend - paddingRight;
		int maxY = wrapperYend - paddingBottom;

		//Bezier default position
		int bezierXstart = wrapperXstart + paddingLeft;
		int bezierYstart = (wrapperYstart + paddingTop);
		int bezierXend = wrapperXend - paddingRight;
		int bezierYend = wrapperYend - paddingBottom;
		int bezierWidth = bezierXend - bezierXstart;
		int bezierHeight = bezierYend - bezierYstart;

		double unityVariance = bezierWidth * 0.05;


		int p1x = bezierXstart;
		int p1y = bezierYend;

		int p2x = bezierXstart + (unityVariance * 2);
		int p2y = bezierYend;

		int p3x = bezierXstart + (unityVariance * 1);
		int p3y = bezierYstart;
	
		int p4x = bezierXstart + (unityVariance * 3);
		int p4y = bezierYstart;

		int p5x = bezierXstart + (unityVariance * 5);
		int p5y = bezierYstart;

		int p6x = bezierXstart + (unityVariance * 4);
		int p6y = bezierYend;

		int p7x = bezierXstart + (unityVariance * 6);
		int p7y = bezierYend;


		if (this->showPoints) {
			//POINTERS 
			LICE_Circle(pGraphics->GetDrawBitmap(), p1x, p1y, 2, LICE_RGBA(255, 0, 0, 0));
			LICE_Circle(pGraphics->GetDrawBitmap(), p2x, p2y, 2, LICE_RGBA(0, 255, 0, 0));
			LICE_Circle(pGraphics->GetDrawBitmap(), p3x, p3y, 2, LICE_RGBA(0, 0, 255, 0));
			LICE_Circle(pGraphics->GetDrawBitmap(), p4x, p4y, 2, LICE_RGBA(255, 0, 255, 0));
			LICE_Circle(pGraphics->GetDrawBitmap(), p5x, p5y, 2, LICE_RGBA(255, 0, 0, 0));
			LICE_Circle(pGraphics->GetDrawBitmap(), p6x, p6y, 2, LICE_RGBA(0, 255, 0, 0));
			LICE_Circle(pGraphics->GetDrawBitmap(), p7x, p7y, 2, LICE_RGBA(255, 0, 255, 0));
		}
		


		//BEZIER1
		LICE_DrawCBezier(pGraphics->GetDrawBitmap(), p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y, LICE_RGBA(0, 0, 0, 255), 0.5);
		LICE_DrawCBezier(pGraphics->GetDrawBitmap(), p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y, LICE_RGBA(255, 255, 255, 255));

		//BEZIER2
		LICE_DrawCBezier(pGraphics->GetDrawBitmap(), p4x, p4y, p5x, p5y, p6x, p6y, p7x, p7y, LICE_RGBA(0, 0, 0, 255), 0.5);
		LICE_DrawCBezier(pGraphics->GetDrawBitmap(), p4x, p4y, p5x, p5y, p6x, p6y, p7x, p7y, LICE_RGBA(255, 255, 255, 255));


		
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
