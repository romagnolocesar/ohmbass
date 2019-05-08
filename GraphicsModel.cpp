#include "GraphicsModel.h"

GraphicsModel::GraphicsModel(IBitmap bitmap, GraphicsModel::EGraphicsType graphicsType, IRECT iRect, EDirection eDirection)
{
	this->bitmap = bitmap;
	this->graphicsType = graphicsType;
	this->iRect = iRect;
	this->eDirection = eDirection;
};

GraphicsModel::GraphicsModel(IBitmap bitmap, GraphicsModel::EGraphicsType graphicsType)
{
	this->bitmap = bitmap;
	this->graphicsType = graphicsType;
};
