#include "GhrrEQuilibrium.h"



GhrrEQuilibrium::GhrrEQuilibrium()
{
}


GhrrEQuilibrium::~GhrrEQuilibrium()
{
}

void GhrrEQuilibrium::setLowFreq(double newLowFreq)
{
	this->lowFreq = newLowFreq;
}

void GhrrEQuilibrium::setLowBoost(double newLowBoost)
{
	this->lowBoost = newLowBoost;
}

void GhrrEQuilibrium::setHighFreq(double newHighFreq)
{
	this->highFreq = newHighFreq;
}

void GhrrEQuilibrium::setHighShelf(double newHighShelf)
{
	this->highShelf = newHighShelf;
}

double GhrrEQuilibrium::getLowFreq()
{
	return lowFreq;
}

double GhrrEQuilibrium::getLowBoost()
{
	return this->lowBoost;
}

double GhrrEQuilibrium::getHighFreq()
{
	return this->highFreq;
}

double GhrrEQuilibrium::getHighShelf()
{
	return this->highShelf;
}
