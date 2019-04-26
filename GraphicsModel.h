#include "IPlugStructs.h"
#include <vector> using namespace std; 


class GraphicsModel
{
public:
	static enum EGraphicsType {
		RADIOBUTTONSCONTROL
	};

	IBitmap* bitmap;
	EGraphicsType graphicsType;


	GraphicsModel();
	~GraphicsModel();

	GraphicsModel::GraphicsModel(
		IBitmap* bitmap,
		GraphicsModel::EGraphicsType graphicsType
	);
};

//Buttons Waves
	//	case controlsManager::mBgBtnOscWavesOsc1:
	//		graphic = &bgBtnOscWavesOsc1;
	//		iControlsManager->control = new IRadioButtonsControl(myOhmBass, IRECT(43, 206, 43 + (56 * 4), 56 + (60 * 4)), i, 4, graphic, kHorizontal);
	//		break;
	//	case controlsManager::mBgBtnOscWavesOsc2:
	//		graphic = &bgBtnOscWavesOsc2;
	//		iControlsManager->control = new IRadioButtonsControl(myOhmBass, IRECT(43, 306, 43 + (56 * 4), 126 + (60 * 4)), i, 4, graphic, kHorizontal);
	//		break;