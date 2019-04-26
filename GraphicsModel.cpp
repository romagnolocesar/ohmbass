#include "GraphicsModel.h"


GraphicsModel::GraphicsModel()
{
}


GraphicsModel::~GraphicsModel()
{
}

GraphicsModel::GraphicsModel(IBitmap* bitmap, EGraphicsType graphicsType) {

	this->bitmap = bitmap;
	this->graphicsType = graphicsType;
};