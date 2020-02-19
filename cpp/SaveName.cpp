#include <algorithm>
#include "../header/SaveName.h"
#include "../header/setup.h"
#include "../header/Objects.h"
#include "../header/SceneMgr.h"
#include "DxLib.h"


void SaveNameUpdate()
{
	using namespace mySetup;
	char name[21];
	std::vector<scorePair>::iterator minItr = setup::MinItrOfVector(resultScores);
	DrawStringToHandle(X / 3, Y / 4, "–¼‘O‚Ì“o˜^", GetColor(255, 255, 255), obj::fontTitle);
	KeyInputString(X / 3, Y * 2 / 5, 20, name, false);
	minItr->first = gameScore;
	minItr->second = std::string(name);
	std::sort(resultScores.begin(), resultScores.end(), std::greater<std::vector<scorePair>::value_type>());

	gameScore = 0;
	SceneMgrChange(myScene::mySceneMenu);
}

void SaveNameUpdate()
{
	//
}
