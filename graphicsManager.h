#pragma once
#include "OhmBass.h"

class graphicsManager
{
public:
	enum ELayout
	{
		kWidth = GUI_WIDTH,
		kHeight = GUI_HEIGHT,
		kKeybX = 36,
		kKeybY = 606
	};

	IControl* mVirtualKeyboard;

	IBitmap //icons
		iconSineWaveOnOsc1,
		iconSineWaveOffOsc1,
		iconSawWaveOnOsc1,
		iconSawWaveOffOsc1,
		iconSquareWaveOnOsc1,
		iconSquareWaveOffOsc1,
		iconTriangleWaveOnOsc1,
		iconTriangleWaveOffOsc1,
		iconSineWaveOnOsc2,
		iconSineWaveOffOsc2,
		iconSawWaveOnOsc2,
		iconSawWaveOffOsc2,
		iconSquareWaveOnOsc2,
		iconSquareWaveOffOsc2,
		iconTriangleWaveOnOsc2,
		iconTriangleWaveOffOsc2,
		//backgrounds
		bgBtnOscWavesOsc1,
		bgBtnOscWavesOsc2,
		//keyboards
		whiteKeyImage,
		blackKeyImage,
		//waveforms
		waveformBitmap,
		//filters
		filterModeBitmap,
		//knobs
		knobBitmap;
			

	IGraphics* pGraphics;
	static const int virtualKeyboardMinimumNoteNumber = 23;
	static int lastVirtualKeyboardNoteNumber;

	graphicsManager();
	~graphicsManager();

	void AttachBackgroundMainDisplay();
	void loadKeyboard();
	void loadOscWavesModes();
	void loadFiltersModes();
	void loadKnobs();
	void loadWavesIcons();
	void loadOscWavesButtonsBackgrounds();

private:
	

};

