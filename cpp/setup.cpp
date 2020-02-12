#include "../header/setup.h"
#include "DxLib.h"


unsigned int mySetup::X = 1600;
unsigned int mySetup::Y = 900;
unsigned int mySetup::gameScore = 0;

std::vector<scorePair> mySetup::resultScores { 
	{0, std::string("No name")},
    {0, std::string("No name")},
    {0, std::string("No name")},
    {0, std::string("No name")},
    {0, std::string("No name")}
};

difficulty mySetup::diff = difficulty::normal;

int keyInput::W = 0;
int keyInput::A = 0;
int keyInput::S = 0;
int keyInput::D = 0;
int keyInput::E = 0;
int keyInput::Q = 0;
int keyInput::pad = 0;
int keyInput::space = 0;
int keyInput::old_W = 0;
int keyInput::old_A = 0;
int keyInput::old_S = 0;
int keyInput::old_D = 0;
int keyInput::old_E = 0;
int keyInput::old_Q = 0;
int keyInput::old_space = 0;
int keyInput::old_pad = 0;


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
	keyInput::old_W = keyInput::W;
	keyInput::old_A = keyInput::A;
	keyInput::old_S = keyInput::S;
	keyInput::old_D = keyInput::D;
	keyInput::old_E = keyInput::E;
	keyInput::old_Q = keyInput::Q;
	keyInput::old_space = keyInput::space;
	keyInput::old_pad = keyInput::pad;
	keyInput::W = CheckHitKey(KEY_INPUT_W);
	keyInput::A = CheckHitKey(KEY_INPUT_A);
	keyInput::S = CheckHitKey(KEY_INPUT_S);
	keyInput::D = CheckHitKey(KEY_INPUT_D);
	keyInput::E = CheckHitKey(KEY_INPUT_E);
	keyInput::Q = CheckHitKey(KEY_INPUT_Q);
	keyInput::space = CheckHitKey(KEY_INPUT_SPACE);
	keyInput::pad = GetJoypadInputState(DX_INPUT_PAD1);
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
