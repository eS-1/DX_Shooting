#include "../header/setup.h"


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

DINPUT_JOYSTATE Input::pad_input;

int Input::W           = 0;
int Input::A           = 0;
int Input::S           = 0;
int Input::D           = 0;
int Input::E           = 0;
int Input::Q           = 0;
int Input::pad         = 0;
int Input::space       = 0;
int Input::analog_LX   = 0;
int Input::analog_LY   = 0;
int Input::analog_RX   = 0;
int Input::analog_RY   = 0;
int Input::old_W       = 0;
int Input::old_A       = 0;
int Input::old_S       = 0;
int Input::old_D       = 0;
int Input::old_E       = 0;
int Input::old_Q       = 0;
int Input::old_space   = 0;
int Input::old_pad     = 0;


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
	using namespace Input;
	old_W        = W;
	old_A        = A;
	old_S        = S;
	old_D        = D;
	old_E        = E;
	old_Q        = Q;
	old_space    = space;
	old_pad      = pad;
	W            = CheckHitKey(KEY_INPUT_W);
	A            = CheckHitKey(KEY_INPUT_A);
	S            = CheckHitKey(KEY_INPUT_S);
	D            = CheckHitKey(KEY_INPUT_D);
	E            = CheckHitKey(KEY_INPUT_E);
	Q            = CheckHitKey(KEY_INPUT_Q);
	space        = CheckHitKey(KEY_INPUT_SPACE);
	pad          = GetJoypadInputState(DX_INPUT_PAD1);
	GetJoypadDirectInputState(DX_INPUT_PAD1, &pad_input);
	analog_LX = pad_input.X;
	analog_LY = pad_input.Y;
	analog_RX = pad_input.Z;
	analog_RY = pad_input.Rz;
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
