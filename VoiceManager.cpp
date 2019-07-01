#include "VoiceManager.h"

Voice* VoiceManager::findFreeVoice() {
	Voice* freeVoice = NULL;
	for (int i = 0; i < NumberOfVoices; i++) {
		if (!voices[i].isActive) {
			freeVoice = &(voices[i]);
			break;
		}
	}
	return freeVoice;
}

void VoiceManager::onNoteOn(int noteNumber, int velocity) {
	Voice* voice = findFreeVoice();
	if (!voice) {
		return;
	}
	
	voice->reset();
	voice->setNoteNumber(noteNumber);
	voice->mVelocity = velocity;
	voice->isActive = true;
	voice->mVolumeEnvelope.enterStage(EnvelopeGenerator::ENVELOPE_STAGE_ATTACK);
	voice->mFilterEnvelope.enterStage(EnvelopeGenerator::ENVELOPE_STAGE_ATTACK);
}

void VoiceManager::onNoteOff(int noteNumber, int velocity) {
	// Find the voice(s) with the given noteNumber:
	for (int i = 0; i < NumberOfVoices; i++) {
		Voice& voice = voices[i];
		if (voice.isActive && voice.mNoteNumber == noteNumber) {
			voice.mVolumeEnvelope.enterStage(EnvelopeGenerator::ENVELOPE_STAGE_RELEASE);
			voice.mFilterEnvelope.enterStage(EnvelopeGenerator::ENVELOPE_STAGE_RELEASE);
		}
	}
}

double VoiceManager::nextSample(bool osc1status, bool osc2status) {
	double output = 0.0;
	double lfo1Value = mLFO1.nextSample();
	double lfo2Value = mLFO2.nextSample();
	double lfo3Value = mLFO3.nextSample();
	for (int i = 0; i < NumberOfVoices; i++) {
		Voice& voice = voices[i];
		voice.setLFOValue(lfo1Value, lfo2Value, lfo3Value);
		output += voice.nextSample(osc1status, osc2status);
	}
	return output; //* 0.6; // 60% of AMP total 
}
