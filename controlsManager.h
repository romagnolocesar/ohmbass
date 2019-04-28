#ifndef CONTROLSMODEL_H
#define CONTROLSMODEL_H
#pragma once
#include "ControlsModel.h"
#include "IPlug_include_in_plug_hdr.h"

//Load Modules
#include <vector> using namespace std; 

class controlsManager{
public:

	const double parameterStep = 0.001;
	std::vector<class ControlsModel * > controlsModelsCollection;
	std::vector<class IControl * > controlsCollection;

	IControl* control;

	int kNumParams = getKNumParams();

	void addParam(
		ModulesModel::EModulesName moduleName, 
		char* alias, 
		ControlsModel::EControlsDataType dataType,
		int x, 
		int y, 
		double defaultVal, 
		double minVal, 
		double maxVal, 
		GraphicsModel* graphicsModel
	);


	void addParam(
		ModulesModel::EModulesName moduleName, 
		char* alias, 
		ControlsModel::EControlsDataType dataType, 
		int x, 
		int y, 
		bool state,
		GraphicsModel* graphicsModel
	);

	void addParam(
		ModulesModel::EModulesName moduleName,
		char* alias,
		ControlsModel::EControlsDataType dataType,
		int x,
		int y,
		int defaultValEnum,
		int Enums,
		GraphicsModel* graphicsModel
	);


	int AddModelsCollection(ControlsModel* myInstance);
	int AddControlsCollection(IControl* myInstance);

	int Count(void);


	//enum EParams
	//{
	//	// Oscillator Section:
	//	mBgBtnOscWavesOsc1 = 0,
	//	mBgBtnOscWavesOsc2,
	//	mIconSineWaveOffOsc1,
	//	mIconSineWaveOnOsc1,
	//	mIconSawWaveOffOsc1,
	//	mIconSawWaveOnOsc1,
	//	mIconSqWaveOffOsc1,
	//	mIconSqWaveOnOsc1,
	//	mIconTriangleWaveOffOsc1,
	//	mIconTriangleWaveOnOsc1,
	//	mIconSineWaveOffOsc2,
	//	mIconSineWaveOnOsc2,
	//	mIconSawWaveOffOsc2,
	//	mIconSawWaveOnOsc2,
	//	mIconSqWaveOffOsc2,
	//	mIconSqWaveOnOsc2,
	//	mIconTriangleWaveOffOsc2,
	//	mIconTriangleWaveOnOsc2,
	//	mOsc1PitchMod,
	//	mOsc2PitchMod,
	//	//Faders
	//	mFadersGlowOsc1,
	//	mFadersGlowOsc2,
	//	mFadersHandlerOffOsc1,
	//	mFadersHandlerOffOsc2,
	//	mFadersHandlerOnOsc1,
	//	mFadersHandlerOnOsc2,
	//	// Filter Section:
	//	mFilterMode,
	//	mFilterCutoff,
	//	mFilterResonance,
	//	mFilterLfoAmount,
	//	mFilterEnvAmount,
	//	// LFO:
	//	mLFOWaveform,
	//	mLFOFrequency,
	//	// Volume Envelope:
	//	mVolumeEnvAttack,
	//	mVolumeEnvDecay,
	//	mVolumeEnvSustain,
	//	mVolumeEnvRelease,
	//	// Filter Envelope:
	//	mFilterEnvAttack,
	//	mFilterEnvDecay,
	//	mFilterEnvSustain,
	//	mFilterEnvRelease,
	//	//GHRR PLACE
	//	//Eq-Librium
	//	mGhrtab1,
	//	mGhrEqlOnTitle,
	//	mGhrEqlLowFreq,
	//	mGhrBostLowFreq,
	//	mGhrEqlHihgFreq,
	//	mGhrShelfHihgFreq,
	//	kNumParams
	//};

	/*typedef struct {
		const char* name;
		const int x;
		const int y;
		const double defaultVal;
		const double minVal;
		const double maxVal;
	} parameterProperties_struct;*/

	/*IControl* control;
	IControl* Osc1ControlSineOn;
	IControl* Osc1ControlSawOn;
	IControl* Osc1ControlSquareOn;
	IControl* Osc1ControlTriagleOn;
	IControl* Osc2ControlSineOn;
	IControl* Osc2ControlSawOn;
	IControl* Osc2ControlSquareOn;
	IControl* Osc2ControlTriagleOn;

	IControl* Osc1FaderHandlerOff;
	IControl* Osc2FaderHandlerOff;
	IControl* Osc1FaderHandlerOn;
	IControl* Osc2FaderHandlerOn;
	IControl* Osc1FaderGlow;
	IControl* Osc2FaderGlow;*/
	



	/*parameterProperties_struct getParameterProperties(int idx) {
		return parameterProperties[idx];
	};*/

	void createParams(IPlug* myOhmBass);
	static int getKNumParams();
	void ToggleIconsWavesButtons(int nOsc, int idxWaveMode);

private:

};
#endif