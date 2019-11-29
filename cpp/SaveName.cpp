#include <algorithm>
#include "../header/SaveName.h"
#include "../header/setup.h"
#include "../header/Objects.h"
#include "../header/SceneMgr.h"
#include "DxLib.h"


void SaveNameUpdate()
{
	char name[21];
	auto minItr = setup::MinItrOfVector(mySetup::resultScores);
	DrawStringToHandle(mySetup::X / 3, mySetup::Y / 4, "–¼‘O‚Ì“o˜^", GetColor(255, 255, 255), obj::fontTitle);
	KeyInputString(mySetup::X / 3, mySetup::Y * 2 / 5, 20, name, false);
	minItr->first = mySetup::gameScore;
	minItr->second = std::string(name);
	std::sort(mySetup::resultScores.begin(), mySetup::resultScores.end(),
		std::greater<std::vector<std::pair<unsigned int, std::string>>::value_type>());

	mySetup::gameScore = 0;
	SceneMgrChange(myScene::mySceneMenu);
}

void SaveNameDraw()
{
	//
}
