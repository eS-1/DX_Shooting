#include "setup.h"
#include "DxLib.h"


unsigned int mySetup::battleX = 460;
unsigned int mySetup::subX = 640;
unsigned int mySetup::allX = mySetup::battleX + mySetup::subX;
unsigned int mySetup::Y = 640;
unsigned int mySetup::gameScore = 0;
std::vector<unsigned int> mySetup::resultScores{ 0, 0, 0, 0, 0 };
difficulty mySetup::diff = normal;


int keyInput::W = 0;
int keyInput::A = 0;
int keyInput::S = 0;
int keyInput::D = 0;
int keyInput::oldW = 0;
int keyInput::oldA = 0;
int keyInput::oldS = 0;
int keyInput::oldD = 0;


std::string setup::NameOf(difficulty diffi)
{
	switch (diffi)
	{
	case easy:
		return "easy";
	case normal:
		return "normal";
	case hard:
		return "hard";
	case extreme:
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
	keyInput::W = CheckHitKey(KEY_INPUT_W);
	keyInput::A = CheckHitKey(KEY_INPUT_A);
	keyInput::S = CheckHitKey(KEY_INPUT_S);
	keyInput::D = CheckHitKey(KEY_INPUT_D);
}
