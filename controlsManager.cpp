#include "OhmBass.h";
#include "controlsManager.h"


void controlsManager::createParams(IPlug* myOhmBass)
{
	for (int i = 0; i < kNumParams; i++) {
		IParam* param = myOhmBass->GetParam(i);
		parameterProperties_struct properties = this->getParameterProperties(i);
		switch (i) {
		case mBgBtnOscWavesOsc1:
			param->InitInt(properties.name, 1, 1, 4, "osc1waves");
			break;
		case mBgBtnOscWavesOsc2:
			param->InitInt(properties.name, 1, 1, 4, "osc2waves");
			break;
		case mLFOWaveform:
			param->InitEnum(properties.name,
				Oscillator::OSCILLATOR_MODE_TRIANGLE,
				Oscillator::kNumOscillatorModes);
			// For VST3:
			param->SetDisplayText(0, properties.name);
			break;
		case mFilterMode:
			param->InitEnum(properties.name,
				Filter::FILTER_MODE_LOWPASS,
				Filter::kNumFilterModes);
			break;
		default:
			param->InitDouble(properties.name,
				properties.defaultVal,
				properties.minVal,
				properties.maxVal,
				parameterStep);
			break;
		}
	}

	myOhmBass->GetParam(mFilterCutoff)->SetShape(2);
	myOhmBass->GetParam(mVolumeEnvAttack)->SetShape(3);
	myOhmBass->GetParam(mFilterEnvAttack)->SetShape(3);
	myOhmBass->GetParam(mVolumeEnvDecay)->SetShape(3);
	myOhmBass->GetParam(mFilterEnvDecay)->SetShape(3);
	myOhmBass->GetParam(mVolumeEnvSustain)->SetShape(2);
	myOhmBass->GetParam(mFilterEnvSustain)->SetShape(2);
	myOhmBass->GetParam(mVolumeEnvRelease)->SetShape(3);
	myOhmBass->GetParam(mFilterEnvRelease)->SetShape(3);

	for (int i = 0; i < kNumParams; i++) {
		myOhmBass->OnParamChange(i);
	}
}

