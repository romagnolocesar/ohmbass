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
		this->modalBox = new IPanelControl(pPlug, pR, &pColor);
		this->hideModalBox();

		this->createDividerLine(pGraphics);
		
		return pGraphics->AttachControl(this->modalBox);
	}

	void createDividerLine(IGraphics* pGraphics) {
		IColor pColorLine;
		pColorLine.A = 255; //255 = Without Alpha
		pColorLine.R = 0;
		pColorLine.G = 0;
		pColorLine.B = 0;
		pGraphics->DrawLine(&pColorLine, 200, 200, 500, 200, 0, FALSE);
	}

	//Show ModalBackground
	void showModalBox()
	{
		this->GrayOut(FALSE);
		this->modalBox->Hide(FALSE);
	}

	//Hide ModalBackground
	void hideModalBox()
	{
		this->GrayOut(TRUE);
		this->modalBox->Hide(TRUE);
	}


	bool IsDirty() { return true; }
};