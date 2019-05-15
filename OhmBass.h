#ifndef __OHMBASS__
#define __OHMBASS__
#include "IPlug_include_in_plug_hdr.h"
#pragma clang diagnostic pop
//Managers
#include "controlsManager.h"
#include "graphicsManager.h"
//#include "ModulesModel.h"

//Modules
#include "ModOscillators.h"
#include "ModGainFaders.h"
#include "ModFilters.h"
#include "ModAmpEnvelope.h"
#include "ModEQuilibrium.h"
//Voices
#include "VoiceManager.h"
//MIDI
#include "MIDIReceiver.h"
#include <functional>



class OhmBass : public IPlug
{
//protected:
//	static OhmBass iOhmBass;
public:
	

	/*OhmBass* OhmBass::GetInstance();*/

	OhmBass(IPlugInstanceInfo instanceInfo);


	~OhmBass();

	//Managers
	controlsManager* iControlsManager = new controlsManager();
	graphicsManager* iGraphicsManager = new graphicsManager();

	//Create Modules
	ModOscillators* iModOscillators = new ModOscillators();
	ModGainFaders* iModGainFaders = new ModGainFaders();
	ModFilters* iModFilters = new ModFilters();
	ModAmpEnvelope* iModAmpEnvelope = new ModAmpEnvelope();
	ModEQuilibrium* iModEQuilibrium = new ModEQuilibrium();
		

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
	int lastVirtualKeyboardNoteNumber = graphicsManager::lastVirtualKeyboardNoteNumber;
	int virtualKeyboardMinimumNoteNumber = graphicsManager::virtualKeyboardMinimumNoteNumber;


	//Create all controls based on Models Controls Collection 
	void doModelsControlsInIControlsCollection();

	
private:
	

	bool isParametersInitialized = FALSE; // All parameters were trigged when opening the GUI for the first time
	double mFrequency;
	void CreatePresets();
	MIDIReceiver mMIDIReceiver;
	
	void processVirtualKeyboard();
	VoiceManager voiceManager;

	EnvelopeGenerator mFilterEnvelopeGenerator;

	Oscillator mLFO;

	void CreateKeyboard();
	void CreateMainDisplay();
};

#endif
