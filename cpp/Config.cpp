#include "../header/Config.h"
#include "../header/setup.h"
#include "../header/Objects.h"
#include "../header/SceneMgr.h"
#include "DxLib.h"


// 設定画面の更新
void Config_Update()
{
	setup::KeyInput();

	if (Input::Q != 0 || (Input::pad & PAD_INPUT_2))
	{
		SceneMgrChange(myScene::mySceneMenu);
	}

	int currentDiff = static_cast<int>(mySetup::diff);
	int easy = static_cast<int>(difficulty::easy);
	int extreme = static_cast<int>(difficulty::extreme);
	
	if (((Input::D & ~Input::old_D) ||
		((Input::pad & ~Input::old_pad) & PAD_INPUT_RIGHT)) &&
		currentDiff < extreme)
	{
		mySetup::diff = static_cast<difficulty>(currentDiff + 1);
	}
	else if (((Input::A & ~Input::old_A) ||
		     ((Input::pad & ~Input::old_pad) & PAD_INPUT_LEFT)) &&
		     currentDiff > easy)
	{
		mySetup::diff = static_cast<difficulty>(currentDiff - 1);
	}
}


// 設定画面の描画
void Config_Draw()
{
	unsigned int bX = mySetup::X / 3;
	unsigned int Y = mySetup::Y / 4;

	int currentDiff = static_cast<int>(mySetup::diff);
	int easy = static_cast<int>(difficulty::easy);
	int extreme = static_cast<int>(difficulty::extreme);

	DrawStringToHandle(bX, Y, "設定", GetColor(255, 255, 255), obj::fontTitle);

	DrawStringToHandle(bX, Y + 100, "難易度: ", GetColor(255, 255, 255), obj::fontInGame);
	DrawFormatStringToHandle(bX + 150, Y + 100, GetColor(255, 255, 255), obj::fontInGame,
		"%s", setup::NameOfDiff(mySetup::diff).c_str());
	if (currentDiff < extreme)
	{
		setup::drawCursor(bX + 270, Y + 117, GetColor(255, 255, 255), 1, 0);
	}
	if (currentDiff > easy)
	{
		setup::drawCursor(bX + 120, Y + 117, GetColor(255, 255, 255), 1, 1);
	}

	DrawStringToHandle(0, 5, "q: 戻る", GetColor(255, 255, 255), obj::fontInGame);
}
