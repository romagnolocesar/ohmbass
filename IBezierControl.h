#pragma once
#include "IPlug_include_in_plug_hdr.h"


class IBezierControl : public IControl
{
public:
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

	//Structure
	struct beziers {
		LICE_pixel color;
		float alpha;
	} beziers[1];

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


		beziers[0].color = LICE_RGBA(0, 0, 0, 255);
		beziers[0].alpha = 0.5f;
		beziers[1].color = LICE_RGBA(255, 255, 255, 255);
		beziers[1].alpha = 1.0f;

		for (int i = 0; i < 2; i++)
		{
			LICE_DrawQBezier(pGraphics->GetDrawBitmap(), this->xstart, this->ystart, this->xctl, this->yctl, this->xend, this->yend, beziers[i].color, beziers[i].alpha);
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
