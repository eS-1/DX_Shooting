#include "../header/SaveName.h"
#include "../header/setup.h"
#include "../header/Objects.h"
#include "../header/SceneMgr.h"
#include "DxLib.h"


// vectorの最小値のイテレータを返す
std::vector<std::pair<unsigned int, std::string>>::iterator MaxItrOfVector(std::vector<std::pair<unsigned int, std::string>>& result)
{
	auto maxItr = result.begin();
	for (auto itr = result.begin(); itr != result.end(); itr++)
	{
		if (maxItr->first < itr->first) { maxItr = itr; }
	}
	return maxItr;
}


void SaveNameUpdate()
{
	char name[21];
	auto maxItr = MaxItrOfVector(mySetup::resultScores);
	DrawStringToHandle(mySetup::X / 3, mySetup::Y / 4, "名前の登録", GetColor(255, 255, 255), obj::fontTitle);
	KeyInputString(mySetup::X / 3, mySetup::Y * 2 / 5, 20, name, false);
	maxItr->second = std::string(name);

	SceneMgrChange(myScene::mySceneMenu);
}

void SaveNameDraw()
{
	//
}
