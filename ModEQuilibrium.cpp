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

void ModEQuilibrium::init(controlsManager* IControlsManager) {
	IControlsManager->addParam(EQUILIBRIUM, "Tab1 Ghrr", 548, 522, 0.0, 0.0, 1.0);
	IControlsManager->addParam(EQUILIBRIUM, "Knb Eql title on", 552, 530, 0.0, 0.0, 1.0);
	IControlsManager->addParam(EQUILIBRIUM, "Knb Eql Low freq", 560, 640, 0.3, 0.0, 1.0);
	IControlsManager->addParam(EQUILIBRIUM, "Knb Bost Low freq", 639, 640, 0.5, 0.0, 1.0);
	IControlsManager->addParam(EQUILIBRIUM, "Knb Eql High freq", 718, 640, 0.5, 0.0, 1.0);
	IControlsManager->addParam(EQUILIBRIUM, "Knb Shelf Hihg freq", 797, 640, 0.1, 0.0, 1.0);
}


