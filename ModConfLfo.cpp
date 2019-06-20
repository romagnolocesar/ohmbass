#include "ModConfLfo.h"



ModConfLfo::ModConfLfo()
{
}


ModConfLfo::~ModConfLfo()
{
}


void ModConfLfo::createModalBox(IPlug * myOhmBass, IGraphics * pGraphics, int w, int h)
{
	IRECT pRect;
	pRect.L = ((1024 / 2) - (w / 2));
	pRect.T = ((768 / 2) - (h / 2));
	pRect.R = ((1024 / 2) + (w / 2));
	pRect.B = ((768 / 2) + (h / 2));

	modalBox = new IModalBox(myOhmBass, pRect, w, h);

	pGraphics->AttachControl(modalBox);
}


//Show ModalBackground
void ModConfLfo::showModalBox()
{
	modalBox->showModalBox();
}
