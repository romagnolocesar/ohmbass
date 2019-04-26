#pragma once
#include "controlsManager.h"

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
		knobBitmap,
		//Faders
		faderGlowBarOsc1,
		faderGlowBarOsc2,
		fadersHandlerOffOsc1,
		fadersHandlerOffOsc2,
		fadersHandlerOnOsc1,
		fadersHandlerOnOsc2,
		//GHRR PLACE
			//Eq-Librium
		knobGhrTab1,
		knobGhrEqlTitleOn,
		knobGhrEqlLow,
		knobGhrEqlBost,
		knobGhrEqlHihg,
		knobGhrEqlShelf;
		
			

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
	void loadFaders();
	void loadOscWavesButtonsBackgrounds();
	void loadGhrrEqlControls();
	void attachGraphicsInControls(IPlug* myOhmBass, controlsManager* iControlsManager);

private:
	

};

