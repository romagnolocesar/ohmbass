#include "MyParameters.h"

MyParameters::MyParameters(){}
MyParameters::~MyParameters(){}

void MyParameters::setName(char mName){
	this->name = mName;
}

char MyParameters::getName(){
	return this->name;
}

void MyParameters::setX(int mX){
	this->x = mX;
}

int MyParameters::getX(){
	return this->x;
}

void MyParameters::setY(int mY){
	this->y = mY;
}

int MyParameters::getY(){
	return this->y;
}

void MyParameters::setDefaultVal(double mDefaultVal){
	this->defaultVal = mDefaultVal;
}

double MyParameters::setDefaultVal(){
	return this->defaultVal;
}

void MyParameters::setMinValue(double mMinVal){
	this->minVal = mMinVal;
}

double MyParameters::getMinValue(){
	return this->minVal;
}

void MyParameters::setMaxValue(double mMaxVal){
	this->maxVal = mMaxVal;
}

double MyParameters::getMaxValue(){
	return this->maxVal;
}

void MyParameters::setHidden(bool hidden){
	this->isHidden = hidden;
}

bool MyParameters::getHidden(){
	return this->isHidden;
}
