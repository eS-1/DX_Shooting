#include "../header/setup.h"
#include "DxLib.h"


unsigned int mySetup::X = 1600;
unsigned int mySetup::Y = 900;
unsigned int mySetup::gameScore = 0;

std::vector<scorePair> mySetup::resultScores { 
	{0, "No name"},
    {0, "No name"},
    {0, "No name"},
    {0, "No name"},
    {0, "No name"}
};

difficulty mySetup::diff = difficulty::normal;

int keyInput::W            = 0;
int keyInput::A            = 0;
int keyInput::S            = 0;
int keyInput::D            = 0;
int keyInput::E            = 0;
int keyInput::Q            = 0;
int keyInput::pad          = 0;
int keyInput::space        = 0;
int keyInput::analog_x     = 0;
int keyInput::analog_y     = 0;
int keyInput::old_W        = 0;
int keyInput::old_A        = 0;
int keyInput::old_S        = 0;
int keyInput::old_D        = 0;
int keyInput::old_E        = 0;
int keyInput::old_Q        = 0;
int keyInput::old_space    = 0;
int keyInput::old_pad      = 0;
int keyInput::old_analog_x = 0;
int keyInput::old_analog_y = 0;


std::string setup::NameOfDiff(difficulty diffi)
{
	switch (diffi)
	{
	case difficulty::easy:
		return "easy";
	case difficulty::normal:
		return "normal";
	case difficulty::hard:
		return "hard";
	case difficulty::extreme:
		return "extreme";
	}
	return "None";
}


void setup::KeyInput()
{
	using namespace keyInput;
	old_W        = W;
	old_A        = A;
	old_S        = S;
	old_D        = D;
	old_E        = E;
	old_Q        = Q;
	old_space    = space;
	old_pad      = pad;
	old_analog_x = analog_x;
	old_analog_y = analog_y;
	W            = CheckHitKey(KEY_INPUT_W);
	A            = CheckHitKey(KEY_INPUT_A);
	S            = CheckHitKey(KEY_INPUT_S);
	D            = CheckHitKey(KEY_INPUT_D);
	E            = CheckHitKey(KEY_INPUT_E);
	Q            = CheckHitKey(KEY_INPUT_Q);
	space        = CheckHitKey(KEY_INPUT_SPACE);
	pad          = GetJoypadInputState(DX_INPUT_PAD1);
	GetJoypadAnalogInput(&analog_x, &analog_y, DX_INPUT_PAD1);
}


void setup::drawCursor(int x, int y, unsigned int Color, int FillFlag, int direction)
{
	switch (direction)
	{
	case 0:
		// 右向き
		DrawTriangle(x, y, x - 6 * sqrt(3.0), y - 6, x - 6 * sqrt(3.0), y + 6, Color, FillFlag);
		break;
	case 1:
		// 左向き
		DrawTriangle(x, y, x + 6 * sqrt(3.0), y - 6, x + 6 * sqrt(3.0), y + 6, Color, FillFlag);
		break;
	default:
		break;
	}
}

// vectorの最小値のイテレータを返す
std::vector<scorePair>::iterator setup::MinItrOfVector(std::vector<scorePair>& result)
{
	std::vector<scorePair>::iterator minItr = result.begin();
	for (auto itr = result.begin(); itr != result.end(); itr++)
	{
		if (minItr->first > itr->first)
		{
			minItr = itr;
		}
	}
	return minItr;
}
