#define PLUG_MFR "Act"
#define PLUG_NAME "OhmBass"

#define PLUG_CLASS_NAME OhmBass

#define BUNDLE_MFR "Cesar"
#define BUNDLE_NAME "Acto"

#define PLUG_ENTRY OhmBass_Entry
#define PLUG_VIEW_ENTRY OhmBass_ViewEntry

#define PLUG_ENTRY_STR "OhmBass_Entry"
#define PLUG_VIEW_ENTRY_STR "OhmBass_ViewEntry"

#define VIEW_CLASS OhmBass_Synth
#define VIEW_CLASS_STR "OhmBass_Synth"

// Format        0xMAJR.MN.BG - in HEX! so version 10.1.5 would be 0x000A0105
#define PLUG_VER 0x00010000
#define VST3_VER_STR "1.0.0"

// http://service.steinberg.de/databases/plugin.nsf/plugIn?openForm
// 4 chars, single quotes. At least one capital letter
#define PLUG_UNIQUE_ID 'Ohmb'
// make sure this is not the same as BUNDLE_MFR
#define PLUG_MFR_ID 'act'

// ProTools stuff

#if (defined(AAX_API) || defined(RTAS_API)) && !defined(_PIDS_)
#define _PIDS_
const int PLUG_TYPE_IDS[2] = { 'EFN1', 'EFN2' };
const int PLUG_TYPE_IDS_AS[2] = { 'EFA1', 'EFA2' }; // AudioSuite
#endif

#define PLUG_MFR_PT "CRoma\ActiOhm"
#define PLUG_NAME_PT "Ohmbs\Ohmb"
#define PLUG_TYPE_PT "instrument"
#define PLUG_DOES_AUDIOSUITE 1

/* PLUG_TYPE_PT can be "None", "EQ", "Dynamics", "PitchShift", "Reverb", "Delay", "Modulation",
"Harmonic" "NoiseReduction" "Dither" "SoundField" "Effect"
instrument determined by PLUG _IS _INST
*/

// #define PLUG_CHANNEL_IO "1-1 2-2"
#if (defined(AAX_API) || defined(RTAS_API))
#define PLUG_CHANNEL_IO "1-1 2-2"
#else
// no audio input. mono or stereo output
#define PLUG_CHANNEL_IO "0-1 0-2"
#endif

#define PLUG_LATENCY 0
#define PLUG_IS_INST 1

// if this is 0 RTAS can't get tempo info
#define PLUG_DOES_MIDI 1

#define PLUG_DOES_STATE_CHUNKS 0


// ===== UNIQUE IDS =====================
// --- Regular Interface ----
#define BG_ID						101
#define WHITE_KEY_ID				102
#define BLACK_KEY_ID				103
#define WAVEFORM_ID					104
#define MODAL_BG_ID					132

#define KNOB_MEDIUM_ID				108
// --- Waves Buttons ----
#define BGBTNOSCWAVES_ID			113
#define ICONSAWWAVEON_ID			114					
#define ICONSAWWAVEOFF_ID			115		
#define ICONSINEWAVEON_ID			116		
#define ICONSINEWAVEOFF_ID			117		
#define ICONSQUAREWAVEON_ID			118	    
#define ICONSQUAREWAVEOFF_ID		119	    
#define ICONTRIANGLEWAVEON_ID		120		
#define ICONTRIANGLEWAVEOFF_ID		121	
// --- Faders ---- //
#define FADERHANDLEROFF_ID			122
#define FADERHANDLERON_ID			123
#define FADERGLOW_ID				124
// --- GRRH Place ---- //
#define GHRRTAB1_ID					125
#define GHREQLONTITLE_ID			126
#define KNOB_MEDIUM_PARAM_ID		127

#define BTN_MAGIC_ACTIOHM_ID		128
#define DROP_DOWN_FILTERS_MODES_ID	129
#define SWITCH_DROP_ID				130
#define BUTTON_POWER_WHITE_ID		131

#define ICONLFO_ID					133
#define MODAL_CLOSE_ICON_ID			134
#define MODAL_MEDIUM_ONE_ID			135



// ===== IMAGES LOCATIONS =====================//
// --- Regular Interface ---- //
#define BG_FN								"resources/img/bg.png"
#define WHITE_KEY_FN						"resources/img/whitekey.png"
#define BLACK_KEY_FN						"resources/img/blackkey.png"
#define WAVEFORM_FN							"resources/img/waveform.png"
#define KNOB_MEDIUM_FN						"resources/img/knob_medium.png"
#define MODAL_BG_FN							"resources/img/modal_bg.png"

// --- Waves Buttons ---- //
#define BGBTNOSCWAVES_FN					"resources/img/wavesbuttons/bg_btn_osc_waves.png"
#define ICONSAWWAVEON_FN					"resources/img/wavesbuttons/icon_saw_wave_on.png"
#define ICONSAWWAVEOFF_FN					"resources/img/wavesbuttons/icon_saw_wave_off.png"
#define ICONSINEWAVEON_FN					"resources/img/wavesbuttons/icon_sine_wave_on.png"
#define ICONSINEWAVEOFF_FN					"resources/img/wavesbuttons/icon_sine_wave_off.png"
#define ICONSQUAREWAVEON_FN					"resources/img/wavesbuttons/icon_square_wave_on.png"
#define ICONSQUAREWAVEOFF_FN				"resources/img/wavesbuttons/icon_square_wave_off.png"
#define ICONTRIANGLEWAVEON_FN				"resources/img/wavesbuttons/icon_triangle_wave_on.png"
#define ICONTRIANGLEWAVEOFF_FN				"resources/img/wavesbuttons/icon_triangle_wave_off.png"
// --- Faders ---- //
#define FADERHANDLEROFF_FN 					"resources/img/faders/faderoff.png"
#define FADERHANDLERON_FN 					"resources/img/faders/faderon.png"
#define FADERGLOW_FN 						"resources/img/faders/glow.png"
// --- GHRR MODE ---- //
#define GHRRTAB1_FN							"resources/img/ghrrmode/tab1.png"
#define GHREQLONTITLE_FN					"resources/img/ghrrmode/eqlibrium/ontitle.png"
#define KNOB_MEDIUM_PARAM_FN				"resources/img/knob_medium_param.png"

#define BTN_MAGIC_ACTIOHM_FN				"resources/img/ghrrmode/eqlibrium/act_wave.png"
#define DROP_DOWN_FILTERS_MODES_FN			"resources/img/drop_down_filters_modes.png"
#define SWITCH_DROP_FN						"resources/img/switch_plug.png"
#define BUTTON_POWER_WHITE_FN				"resources/img/button_power_white.png"

#define ICONLFO_FN							"resources/img/lfoicon.png"
#define MODAL_CLOSE_ICON_FN					"resources/img/modal_close_icon.png"
#define MODAL_MEDIUM_ONE_FN					"resources/img/modals/medium_one.png"






// GUI default dimensions
#define GUI_WIDTH 1024
#define GUI_HEIGHT 768

// on MSVC, you must define SA_API in the resource editor preprocessor macros as well as the c++ ones
#if defined(SA_API) && !defined(OS_IOS)
#include "app_wrapper/app_resource.h"
#endif

// vst3 stuff
#define MFR_URL "www.actiohm.com.br"
#define MFR_EMAIL "cesar.romagnolo@hotmail.com"
#define EFFECT_TYPE_VST3 "Instrument|Synth"

/* "Fx|Analyzer"", "Fx|Delay", "Fx|Distortion", "Fx|Dynamics", "Fx|EQ", "Fx|Filter",
"Fx", "Fx|Instrument", "Fx|InstrumentExternal", "Fx|Spatial", "Fx|Generator",
"Fx|Mastering", "Fx|Modulation", "Fx|PitchShift", "Fx|Restoration", "Fx|Reverb",
"Fx|Surround", "Fx|Tools", "Instrument", "Instrument|Drum", "Instrument|Sampler",
"Instrument|Synth", "Instrument|Synth|Sampler", "Instrument|External", "Spatial",
"Spatial|Fx", "OnlyRT", "OnlyOfflineProcess", "Mono", "Stereo",
"Surround"
*/
