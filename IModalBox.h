#pragma once
#include "IPlug_include_in_plug_hdr.h"

class IModalBox : public IControl
{
private:
	

public:
	IControl* modalBox;
	int w, h;
	IPlugBase* pPlug;
	IRECT pR;
	IGraphics* pGraphics;


	IModalBox(IPlugBase* pPlug, IRECT pR, int w, int h)
		: IControl(pPlug, pR)
	{
		this->w = w;
		this->h = h;
		this->pPlug = pPlug;
		this->pR = pR;
	}

	bool Draw(IGraphics* pGraphics)
	{
		this->pGraphics = pGraphics;


		IColor pColor;
		pColor.A = 255; //255 = Without Alpha
		pColor.R = 78;
		pColor.G = 78;
		pColor.B = 84;
		modalBox = new IPanelControl(pPlug, pR, &pColor);
		hideModalBox();
		
		return pGraphics->AttachControl(modalBox);
	}

	//Show ModalBackground
	void showModalBox()
	{
		modalBox->GrayOut(FALSE);
		modalBox->Hide(FALSE);
	}

	//Hide ModalBackground
	void hideModalBox()
	{
		modalBox->GrayOut(TRUE);
		modalBox->Hide(TRUE);
	}


	bool IsDirty() { return true; }
};