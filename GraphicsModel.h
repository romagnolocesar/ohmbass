#include <vector> using namespace std; 
#include "IControl.h"


class GraphicsModel
{
public:
	static enum EGraphicsType {
		RADIOBUTTONSCONTROL,
		BITMAPCONTROL,
		KNOBMULTICONTROL,
		KNOBMULTICONTROLPARAM,
		FADERCONTROL,
		SWITCHCONTROL,
		BEZIERCONTROL,
		BITMAPOVERLAYCONTROL,
		TEXT
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
	GraphicsModel(GraphicsModel::EGraphicsType graphicsType);
};