#ifndef __OHMBASS__
#define __OHMBASS__

#include "IPlug_include_in_plug_hdr.h"
#pragma clang diagnostic pop

#include "VoiceManager.h"
#include "MIDIReceiver.h"
#include <functional>


class OhmBass : public IPlug
{
public:
	OhmBass(IPlugInstanceInfo instanceInfo);
	~OhmBass();

	void Reset();
	void OnParamChange(int paramIdx);
	void ProcessDoubleReplacing(double** inputs, double** outputs, int nFrames);
	// to receive MIDI messages:
	void ProcessMidiMsg(IMidiMsg* pMsg);

	// Needed for the GUI keyboard:
	// Should return non-zero if one or more keys are playing.
	inline int GetNumKeys() const { return mMIDIReceiver.getNumKeys(); };
	// Should return true if the specified key is playing.
	inline bool GetKeyStatus(int key) const { return mMIDIReceiver.getKeyStatus(key); };
	static const int virtualKeyboardMinimumNoteNumber = 23;
	int lastVirtualKeyboardNoteNumber;
	

private:
	bool isParametersInitialized = FALSE; // All parameters were trigged when opening the GUI for the first time
	double mFrequency;
	void CreatePresets();
	MIDIReceiver mMIDIReceiver;
	IControl* mVirtualKeyboard;
	void processVirtualKeyboard();
	VoiceManager voiceManager;

	EnvelopeGenerator mFilterEnvelopeGenerator;

	Oscillator mLFO;

	void CreateParams();
	void CreateGraphics();
};

#endif
