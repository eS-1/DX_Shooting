#include <algorithm>
#include "DxLib.h"
#include "../header/SaveName.h"
#include "../header/setup.h"
#include "../header/Objects.h"
#include "../header/SceneMgr.h"
#include "../header/Keyboard.h"


namespace
{
	std::vector<scorePair>::iterator minItr;
}

void SaveName_Init()
{
	minItr = setup::MinItrOfVector(mySetup::resultScores);
}

void SaveName_Update()
{
	using namespace mySetup;

	setup::KeyInput();
	obj::myKeyboard->update();

	if (obj::myKeyboard->get_flag_enter())
	{
		minItr->first = gameScore;
		minItr->second = obj::myKeyboard->get_typed();
		std::sort(resultScores.begin(), resultScores.end(), std::greater<std::vector<scorePair>::value_type>());

		gameScore = 0;
		SceneMgrChange(myScene::mySceneMenu);
	}
}

void SaveName_Draw()
{
	using namespace mySetup;
	DrawStringToHandle(X / 3, Y / 4, "–¼‘O‚Ì“o˜^", GetColor(255, 255, 255), obj::fontTitle);
	if (obj::myKeyboard)
	{
		obj::myKeyboard->draw();
	}
}
