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
