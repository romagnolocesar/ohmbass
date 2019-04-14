#pragma once
class OscillatorGUIManager
{
public:
	int oscilatorIdx;
	int paramIdx;
	const char* name;
	const int x;
	const int y;
	const double defaultVal;
	const double minVal;
	const double maxVal;
	void CreateGraphics();
private:
	enum EBtnTypes
	{
		mOsc1BtnSaw,
		mOsc1BtnSin,
		mOsc1BtnSq,
		mOsc1BtnTri
	};
};

