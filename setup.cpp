#include "setup.h"
#include "DxLib.h"


unsigned int mySetup::battleX = 460;
unsigned int mySetup::subX = 640;
unsigned int mySetup::allX = mySetup::battleX + mySetup::subX;
unsigned int mySetup::Y = 640;
unsigned int mySetup::gameScore = 0;
std::vector<unsigned int> mySetup::resultScores{ 0, 0, 0, 0, 0 };
difficulty mySetup::diff = normal;

std::string NameOf(difficulty diffi)
{
	switch (diffi)
	{
	case easy:
		return "easy";
	case normal:
		return "normal";
	case hard:
		return "hard";
	}
	return "None";
}