#include "setup.h"
#include "DxLib.h"


unsigned int mySetup::battleX = 460;
unsigned int mySetup::subX = 640;
unsigned int mySetup::allX = mySetup::battleX + mySetup::subX;
unsigned int mySetup::Y = 640;
unsigned int mySetup::gameScore = 0;
std::vector<unsigned int> mySetup::resultScores{ 2, 3, 4, 5, 6 };