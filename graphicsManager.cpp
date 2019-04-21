#include "OhmBass.h"
#include "graphicsManager.h"




graphicsManager::graphicsManager()
{
}


graphicsManager::~graphicsManager()
{
}

void graphicsManager::AttachBackgroundMainDisplay()
{
	//background
	pGraphics->AttachBackground(BG_ID, BG_FN);
}

void graphicsManager::loadKeyboard()
{
	//keybooards
	this->whiteKeyImage = pGraphics->LoadIBitmap(WHITE_KEY_ID, WHITE_KEY_FN, 6);
	this->blackKeyImage = pGraphics->LoadIBitmap(BLACK_KEY_ID, BLACK_KEY_FN);
}

void graphicsManager::loadOscWavesModes()
{
	this->waveformBitmap = pGraphics->LoadIBitmap(WAVEFORM_ID, WAVEFORM_FN, 4);
}

void graphicsManager::loadFiltersModes()
{
	this->filterModeBitmap = pGraphics->LoadIBitmap(FILTERMODE_ID, FILTERMODE_FN, 3);
}

void graphicsManager::loadKnobs()
{
	this->knobBitmap = pGraphics->LoadIBitmap(KNOB_MEDIUM_ID, KNOB_MEDIUM, 47);
}

void graphicsManager::loadWavesIcons()
{
	this->iconSineWaveOnOsc1 = pGraphics->LoadIBitmap(ICONSINEWAVEON_ID, ICONSINEWAVEON_FN);
	this->iconSineWaveOffOsc1 = pGraphics->LoadIBitmap(ICONSINEWAVEOFF_ID, ICONSINEWAVEOFF_FN);
	this->iconSawWaveOnOsc1 = pGraphics->LoadIBitmap(ICONSAWWAVEON_ID, ICONSAWWAVEON_FN);
	this->iconSawWaveOffOsc1 = pGraphics->LoadIBitmap(ICONSAWWAVEOFF_ID, ICONSAWWAVEOFF_FN);
	this->iconSquareWaveOnOsc1 = pGraphics->LoadIBitmap(ICONSQUAREWAVEON_ID, ICONSQUAREWAVEON_FN);
	this->iconSquareWaveOffOsc1 = pGraphics->LoadIBitmap(ICONSQUAREWAVEOFF_ID, ICONSQUAREWAVEOFF_FN);
	this->iconTriangleWaveOnOsc1 = pGraphics->LoadIBitmap(ICONTRIANGLEWAVEON_ID, ICONTRIANGLEWAVEON_FN);
	this->iconTriangleWaveOffOsc1 = pGraphics->LoadIBitmap(ICONTRIANGLEWAVEOFF_ID, ICONTRIANGLEWAVEOFF_FN);
	this->iconSineWaveOnOsc2 = pGraphics->LoadIBitmap(ICONSINEWAVEON_ID, ICONSINEWAVEON_FN);
	this->iconSineWaveOffOsc2 = pGraphics->LoadIBitmap(ICONSINEWAVEOFF_ID, ICONSINEWAVEOFF_FN);
	this->iconSawWaveOnOsc2 = pGraphics->LoadIBitmap(ICONSAWWAVEON_ID, ICONSAWWAVEON_FN);
	this->iconSawWaveOffOsc2 = pGraphics->LoadIBitmap(ICONSAWWAVEOFF_ID, ICONSAWWAVEOFF_FN);
	this->iconSquareWaveOnOsc2 = pGraphics->LoadIBitmap(ICONSQUAREWAVEON_ID, ICONSQUAREWAVEON_FN);
	this->iconSquareWaveOffOsc2 = pGraphics->LoadIBitmap(ICONSQUAREWAVEOFF_ID, ICONSQUAREWAVEOFF_FN);
	this->iconTriangleWaveOnOsc2 = pGraphics->LoadIBitmap(ICONTRIANGLEWAVEON_ID, ICONTRIANGLEWAVEON_FN);
	this->iconTriangleWaveOffOsc2 = pGraphics->LoadIBitmap(ICONTRIANGLEWAVEOFF_ID, ICONTRIANGLEWAVEOFF_FN);
}

void graphicsManager::loadOscWavesButtonsBackgrounds()
{
	this->bgBtnOscWavesOsc1 = pGraphics->LoadIBitmap(BGBTNOSCWAVES_ID, BGBTNOSCWAVES_FN, 2);
	this->bgBtnOscWavesOsc2 = pGraphics->LoadIBitmap(BGBTNOSCWAVES_ID, BGBTNOSCWAVES_FN, 2);
}

