#include "OhmBass.h"
#include "graphicsManager.h"
#include "controlsManager.h"
#include "VectorLib.h"


void graphicsManager::attachBackgroundMainDisplay()
{
	//background
	pGraphics->AttachBackground(BG_ID, BG_FN);
};

void graphicsManager::loadCommonsBitmaps() {
	char* name = "KNOB_MEDIUM";
	IBitmap myBitmap = pGraphics->LoadIBitmap(KNOB_MEDIUM_ID, KNOB_MEDIUM_FN, 47);
	tCommonsBitmaps<char*, IBitmap> knobMedium = tCommonsBitmaps(name, myBitmap);
	this->mknobMedium = AddCommonsBitmapsCollection(knobMedium);

	name = "KNOB_MEDIUM";
	myBitmap = pGraphics->LoadIBitmap(KNOB_MEDIUM_PARAM_ID, KNOB_MEDIUM_PARAM_FN, 10);
	tCommonsBitmaps<char*, IBitmap> knobMediumParam = tCommonsBitmaps(name, myBitmap);
	this->mknobMediumParam = AddCommonsBitmapsCollection(knobMediumParam);
};

IBitmap graphicsManager::getBitmapFromCommonsColletion(int idxBitmap) {
	return this->commonsBitmapsCollection[idxBitmap].bitmap;
};

int graphicsManager::AddCommonsBitmapsCollection(tCommonsBitmaps<char*, IBitmap> myInstance)
{
	this->commonsBitmapsCollection.push_back(myInstance);
	return (this->commonsBitmapsCollection.size() - 1);
};


void graphicsManager::loadKeyboard()
{
	//keybooards
	this->whiteKeyImage = pGraphics->LoadIBitmap(WHITE_KEY_ID, WHITE_KEY_FN, 6);
	this->blackKeyImage = pGraphics->LoadIBitmap(BLACK_KEY_ID, BLACK_KEY_FN);
}
