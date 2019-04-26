#include "ModEQuilibrium.h"


void ModEQuilibrium::setLowFreq(double newLowFreq)
{
	this->lowFreq = newLowFreq;
}

void ModEQuilibrium::setLowBoost(double newLowBoost)
{
	this->lowBoost = newLowBoost;
}

void ModEQuilibrium::setHighFreq(double newHighFreq)
{
	this->highFreq = newHighFreq;
}

void ModEQuilibrium::setHighShelf(double newHighShelf)
{
	this->highShelf = newHighShelf;
}

double ModEQuilibrium::getLowFreq()
{
	return lowFreq;
}

double ModEQuilibrium::getLowBoost()
{
	return this->lowBoost;
}

double ModEQuilibrium::getHighFreq()
{
	return this->highFreq;
}

double ModEQuilibrium::getHighShelf()
{
	return this->highShelf;
}

//void ModEQuilibrium::init(controlsManager* IControlsManager) {
//	IControlsManager->addParam(this->moduleName, "Tab1 Ghrr", ControlsModel::DOUBLE, 548, 522, 0.0, 0.0, 1.0);
//	IControlsManager->addParam(this->moduleName, "Knb Eql title on", ControlsModel::DOUBLE, 552, 530, 0.0, 0.0, 1.0);
//	IControlsManager->addParam(this->moduleName, "Knb Eql Low freq", ControlsModel::DOUBLE, 560, 640, 0.3, 0.0, 1.0);
//	IControlsManager->addParam(this->moduleName, "Knb Bost Low freq", ControlsModel::DOUBLE, 639, 640, 0.5, 0.0, 1.0);
//	IControlsManager->addParam(this->moduleName, "Knb Eql High freq", ControlsModel::DOUBLE, 718, 640, 0.5, 0.0, 1.0);
//	IControlsManager->addParam(this->moduleName, "Knb Shelf Hihg freq", ControlsModel::DOUBLE, 797, 640, 0.1, 0.0, 1.0);
//}
//
//
