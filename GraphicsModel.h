#include <vector> using namespace std; 
#include "IControl.h"


class GraphicsModel
{
public:
	static enum EGraphicsType {
		RADIOBUTTONSCONTROL,
		BITMAPCONTROL,
		KNOBMULTICONTROL
	};

	IBitmap bitmap;
	EGraphicsType graphicsType;
	IRECT iRect;
	EDirection eDirection;

	GraphicsModel::GraphicsModel(
		IBitmap bitmap,
		GraphicsModel::EGraphicsType graphicsType,
		IRECT iRect,
		EDirection eDirection
	);

	GraphicsModel::GraphicsModel(
		IBitmap bitmap,
		GraphicsModel::EGraphicsType graphicsType
	);
};