#pragma once
#include "controlsManager.h"
#include "graphicsManager.h"

class ModConfLfo :
	public ModulesModel
{
public:
	EModulesName moduleName = CONFLFO;

	ModConfLfo();
	~ModConfLfo();


	void createModalBox(IPlug* myOhmBass, IGraphics* pGraphics, int w, int h);
	void showModalBox();

	IModalBox* modalBox;
};

