#include "../header/setup.h"
#include "DxLib.h"


unsigned int mySetup::X = 1600;
unsigned int mySetup::Y = 900;
unsigned int mySetup::gameScore = 0;
std::vector<std::pair<unsigned int, std::string>> mySetup::resultScores { 
	{0, std::string("aaa")},
    {0, std::string("bbb")},
    {0, std::string("ccc")},
    {0, std::string("ddd")},
    {0, std::string("eee")}
};
difficulty mySetup::diff = difficulty::normal;


int keyInput::W = 0;
int keyInput::A = 0;
int keyInput::S = 0;
int keyInput::D = 0;
int keyInput::E = 0;
int keyInput::Q = 0;
int keyInput::oldW = 0;
int keyInput::oldA = 0;
int keyInput::oldS = 0;
int keyInput::oldD = 0;
int keyInput::oldE = 0;
int keyInput::oldQ = 0;


std::string setup::NameOf(difficulty diffi)
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
	keyInput::oldW = keyInput::W;
	keyInput::oldA = keyInput::A;
	keyInput::oldS = keyInput::S;
	keyInput::oldD = keyInput::D;
	keyInput::oldE = keyInput::E;
	keyInput::oldQ = keyInput::Q;
	keyInput::W = CheckHitKey(KEY_INPUT_W);
	keyInput::A = CheckHitKey(KEY_INPUT_A);
	keyInput::S = CheckHitKey(KEY_INPUT_S);
	keyInput::D = CheckHitKey(KEY_INPUT_D);
	keyInput::E = CheckHitKey(KEY_INPUT_E);
	keyInput::Q = CheckHitKey(KEY_INPUT_Q);
}


void setup::drawCursor(int x, int y, unsigned int Color, int FillFlag, int direction)
{
	switch (direction)
	{
	case 0:
		// âEå¸Ç´
		DrawTriangle(x, y, x - 6 * sqrt(3.0), y - 6, x - 6 * sqrt(3.0), y + 6, Color, FillFlag);
		break;
	case 1:
		// ç∂å¸Ç´
		DrawTriangle(x, y, x + 6 * sqrt(3.0), y - 6, x + 6 * sqrt(3.0), y + 6, Color, FillFlag);
		break;
	default:
		break;
	}
}