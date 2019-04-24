#include "OhmBass.h"
#include "controlsManager.h"
#include "graphicsManager.h"



void controlsManager::createParams(IPlug* myOhmBass)
{
	
	for (int i = 0; i < Count(); i++) {
		IParam* param = myOhmBass->GetParam(i);
		switch (collection[i]->dataType){
			case ControlsModel::DOUBLE:
				param->InitDouble(
					collection[i]->alias,
					collection[i]->defaultVal,
					collection[i]->minVal,
					collection[i]->maxVal,
					1
				);
				break;
			case ControlsModel::INT:
				param->InitInt(
					collection[i]->alias,
					collection[i]->defaultVal,
					collection[i]->minVal,
					collection[i]->maxVal,
					collection[i]->alias
				);
				break;
			default:
				param->InitDouble(
					collection[i]->alias,
					collection[i]->defaultVal,
					collection[i]->minVal,
					collection[i]->maxVal,
					parameterStep
				);
	}

		
	}
	for (int i = 0; i < Count(); i++) {
		myOhmBass->OnParamChange(i);
	}

	

	//for (int i = 0; i < kNumParams; i++) {
	//	IParam* param = myOhmBass->GetParam(i);
	//	parameterProperties_struct properties = this->getParameterProperties(i);
	//	switch (i) {
	//	case mBgBtnOscWavesOsc1:
	//		param->InitInt(properties.name, 1, 1, 4, "osc1waves");
	//		break;
	//	case mBgBtnOscWavesOsc2:
	//		param->InitInt(properties.name, 1, 1, 4, "osc2waves");
	//		break;
	//		//Faders Oscillators
	//	case mFadersGlowOsc1:
	//		param->InitDouble(properties.name, properties.defaultVal, properties.minVal, properties.maxVal, 1);
	//		break;
	//	case mFadersGlowOsc2:
	//		param->InitDouble(properties.name, properties.defaultVal, properties.minVal, properties.maxVal, 1);
	//		break;
	//	case mFadersHandlerOffOsc1:
	//		param->InitDouble(properties.name, properties.defaultVal, properties.minVal, properties.maxVal, 1);
	//		break;
	//	case mFadersHandlerOffOsc2:
	//		param->InitDouble(properties.name, properties.defaultVal, properties.minVal, properties.maxVal, 1);
	//		break;
	//	case mFadersHandlerOnOsc1:
	//		param->InitDouble(properties.name, properties.defaultVal, properties.minVal, properties.maxVal, 1);
	//		break;
	//	case mFadersHandlerOnOsc2:
	//		param->InitDouble(properties.name, properties.defaultVal, properties.minVal, properties.maxVal, 1);
	//		break;
	//	case mLFOWaveform:
	//		param->InitEnum(properties.name,
	//			Oscillator::OSCILLATOR_MODE_TRIANGLE,
	//			Oscillator::kNumOscillatorModes);
	//		// For VST3:
	//		param->SetDisplayText(0, properties.name);
	//		break;
	//	case mFilterMode:
	//		param->InitEnum(properties.name,
	//			Filter::FILTER_MODE_LOWPASS,
	//			Filter::kNumFilterModes);
	//		break;
	//	//GHRR PLACE
	//		//eQ-Librium
	//	case mGhrtab1:
	//		param->InitDouble(properties.name, properties.defaultVal, properties.minVal, properties.maxVal, 1);
	//		break;
	//	case mGhrEqlOnTitle:
	//		param->InitDouble(properties.name, properties.defaultVal, properties.minVal, properties.maxVal, 1);
	//		break;
	//	case mGhrEqlLowFreq:
	//		param->InitDouble(properties.name, properties.defaultVal, properties.minVal, properties.maxVal, 1);
	//		break;
	//	case mGhrBostLowFreq:
	//		param->InitDouble(properties.name, properties.defaultVal, properties.minVal, properties.maxVal, 1);
	//		break;
	//	case mGhrEqlHihgFreq:
	//		param->InitDouble(properties.name, properties.defaultVal, properties.minVal, properties.maxVal, 1);
	//		break;
	//	case mGhrShelfHihgFreq:
	//		param->InitDouble(properties.name, properties.defaultVal, properties.minVal, properties.maxVal, 1);
	//		break;
	//	default:
	//		param->InitDouble(properties.name,
	//			properties.defaultVal,
	//			properties.minVal,
	//			properties.maxVal,
	//			parameterStep);
	//		break;
	//	}
	//}

	//myOhmBass->GetParam(mFilterCutoff)->SetShape(2);
	//myOhmBass->GetParam(mVolumeEnvAttack)->SetShape(3);
	//myOhmBass->GetParam(mFilterEnvAttack)->SetShape(3);
	//myOhmBass->GetParam(mVolumeEnvDecay)->SetShape(3);
	//myOhmBass->GetParam(mFilterEnvDecay)->SetShape(3);
	//myOhmBass->GetParam(mVolumeEnvSustain)->SetShape(2);
	//myOhmBass->GetParam(mFilterEnvSustain)->SetShape(2);
	//myOhmBass->GetParam(mVolumeEnvRelease)->SetShape(3);
	//myOhmBass->GetParam(mFilterEnvRelease)->SetShape(3);

	//for (int i = 0; i < kNumParams; i++) {
	//	myOhmBass->OnParamChange(i);
	//}
}

int controlsManager::getKNumParams()
{
	//return this->kNumParams;
	return 50;
}

void controlsManager::ToggleIconsWavesButtons(int nOsc, int idxWaveMode)
{
	if (nOsc == 1) {
		switch (idxWaveMode) {
		case 0:
			Osc1ControlSineOn->Hide(FALSE);
			Osc1ControlSawOn->Hide(TRUE);
			Osc1ControlSquareOn->Hide(TRUE);
			Osc1ControlTriagleOn->Hide(TRUE);
			break;
		case 1:
			Osc1ControlSineOn->Hide(TRUE);
			Osc1ControlSawOn->Hide(FALSE);
			Osc1ControlSquareOn->Hide(TRUE);
			Osc1ControlTriagleOn->Hide(TRUE);
			break;
		case 2:
			Osc1ControlSineOn->Hide(TRUE);
			Osc1ControlSawOn->Hide(TRUE);
			Osc1ControlSquareOn->Hide(FALSE);
			Osc1ControlTriagleOn->Hide(TRUE);
			break;
		case 3:
			Osc1ControlSineOn->Hide(TRUE);
			Osc1ControlSawOn->Hide(TRUE);
			Osc1ControlSquareOn->Hide(TRUE);
			Osc1ControlTriagleOn->Hide(FALSE);
			break;
		}

	}
	else if (nOsc == 2) {
		switch (idxWaveMode) {
		case 0:
			Osc2ControlSineOn->Hide(FALSE);
			Osc2ControlSawOn->Hide(TRUE);
			Osc2ControlSquareOn->Hide(TRUE);
			Osc2ControlTriagleOn->Hide(TRUE);
			break;
		case 1:
			Osc2ControlSineOn->Hide(TRUE);
			Osc2ControlSawOn->Hide(FALSE);
			Osc2ControlSquareOn->Hide(TRUE);
			Osc2ControlTriagleOn->Hide(TRUE);
			break;
		case 2:
			Osc2ControlSineOn->Hide(TRUE);
			Osc2ControlSawOn->Hide(TRUE);
			Osc2ControlSquareOn->Hide(FALSE);
			Osc2ControlTriagleOn->Hide(TRUE);
			break;
		case 3:
			Osc2ControlSineOn->Hide(TRUE);
			Osc2ControlSawOn->Hide(TRUE);
			Osc2ControlSquareOn->Hide(TRUE);
			Osc2ControlTriagleOn->Hide(FALSE);
			break;
		}

	}
}



