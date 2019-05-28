#include "OhmBass.h"
#include "graphicsManager.h"
#include "controlsManager.h"
#include "VectorLib.h"


void graphicsManager::attachBackgroundMainDisplay()
{
	//background
	pGraphics->AttachBackground(BG_ID, BG_FN);
};

void graphicsManager::createTempoInfo(IPlugBase* iOhmBass) {
	IText text = IText(14);
	pGraphics->AttachControl(new ITempoDisplay(iOhmBass, IRECT(300, 10, kWidth, 20), &text, &mTimeInfo));
}

void graphicsManager::createLines(IPlugBase* iOhmBass) {
	pGraphics->AttachControl(new IBezierControl(iOhmBass, IRECT(570, 600, 800, 640), 43, 44));
}

void graphicsManager::loadCommonsBitmaps() {
	char* name = "KNOB_MEDIUM";
	IBitmap myBitmap = pGraphics->LoadIBitmap(KNOB_MEDIUM_ID, KNOB_MEDIUM_FN, 47);
	tCommonsBitmaps<char*, IBitmap>* knobMedium = new tCommonsBitmaps<char*, IBitmap>(name, myBitmap);
	this->mknobMedium = AddCommonsBitmapsCollection(knobMedium);

	name = "KNOB_MEDIUM_PARAM";
	myBitmap = pGraphics->LoadIBitmap(KNOB_MEDIUM_PARAM_ID, KNOB_MEDIUM_PARAM_FN, 10);

	tCommonsBitmaps<char*, IBitmap>* knobMediumParam = new tCommonsBitmaps<char*, IBitmap>(name, myBitmap);
	this->mknobMediumParam = AddCommonsBitmapsCollection(knobMediumParam);
};

IBitmap graphicsManager::getBitmapFromCommonsColletion(int idxBitmap) {
	tCommonsBitmaps<char*, IBitmap> * instance;
	instance = this->commonsBitmapsCollection[idxBitmap];
	return  instance->bitmap;
};

int graphicsManager::AddCommonsBitmapsCollection(tCommonsBitmaps<char*, IBitmap>* myInstance)
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
