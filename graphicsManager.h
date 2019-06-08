#include <vector> using namespace std; 
#pragma once
#include "controlsManager.h"


class graphicsManager
{
public:
	ITimeInfo mTimeInfo;

	enum ELayout
	{
		kWidth = GUI_WIDTH,
		kHeight = GUI_HEIGHT,
		kKeybX = 36,
		kKeybY = 606
	};

	
	IPlugBase* iOhmBass;
	IControl* mVirtualKeyboard;
	IGraphics* pGraphics;
	IBitmap whiteKeyImage, blackKeyImage;

	static const int virtualKeyboardMinimumNoteNumber = 24;
	static int lastVirtualKeyboardNoteNumber;
	

	//Template class of commons bitmaps
	template<class N, class B>
	class tCommonsBitmaps
	{
	public:
		N name;
		B bitmap;

		tCommonsBitmaps::tCommonsBitmaps(N name, B bitmap) {
			this->name = name;
			this->bitmap = bitmap;
		};

		tCommonsBitmaps::tCommonsBitmaps() {};
	};


	//Collection of commonsBitmaps
	std::vector<class tCommonsBitmaps<char*, IBitmap> * > commonsBitmapsCollection;

	int mknobMedium;
	int mknobMediumParam;

	IBitmap getBitmapFromCommonsColletion(int idxBitmap);
	int AddCommonsBitmapsCollection(tCommonsBitmaps<char*, IBitmap> * myInstance);
	void loadCommonsBitmaps();
	void attachBackgroundMainDisplay();
	void createTempoInfo(IPlugBase* iOhmBass);
	void loadKeyboard();

	graphicsManager(IPlugBase* iOhmBass) {
		this->iOhmBass = iOhmBass;
	};
	

private:
	

};

