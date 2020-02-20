#include "../header/Menu.h"
#include "../header/setup.h"
#include "../header/Objects.h"
#include "../header/SceneMgr.h"
#include "DxLib.h"


bool Menu::exitFlag;

namespace
{
	myScene scene;
	MenuSelect selection;
}


// メニュー画面の更新
void MenuUpdate()
{
	setup::KeyInput();

	if (((keyInput::W & ~keyInput::old_W) ||
		((keyInput::pad & ~keyInput::old_pad) & PAD_INPUT_UP)) &&
		selection > MenuSelect::start)
	{
		int current = static_cast<int>(selection);
		selection = static_cast<MenuSelect>(current - 1);
	}
	else if (((keyInput::S & ~keyInput::old_S) ||
		     ((keyInput::pad & ~keyInput::old_pad) & PAD_INPUT_DOWN)) &&
		     selection < MenuSelect::keyboard)
	{
		int current = static_cast<int>(selection);
		selection = static_cast<MenuSelect>(current + 1);
	}

	// 各シーンに遷移
	if ((keyInput::space & ~keyInput::old_space) || (keyInput::pad & ~keyInput::old_pad) & PAD_INPUT_3)
	{
		switch (selection)
		{
		case MenuSelect::start:
			SceneMgrChange(myScene::mySceneGame);
			break;
		case MenuSelect::config:
			SceneMgrChange(myScene::mySceneConfig);
			break;
		case MenuSelect::result:
			SceneMgrChange(myScene::mySceneResult);
			break;
		case MenuSelect::exit:
			Menu::exitFlag = true;
			break;
		case MenuSelect::keyboard:
			SceneMgrChange(myScene::mySceneKeyboard);
			break;
		default:
			break;
		}
	}
}


// メニュー画面の描画
void MenuDraw()
{
	using namespace mySetup;

	int stateSelect = static_cast<int>(selection);

	DrawStringToHandle(X * 5 / 16, Y / 3, "Simple Shooter 2D", GetColor(255, 255, 255), obj::fontTitle);
	DrawStringToHandle(X * 4 / 9 - 10, Y / 3 + 200, "ゲーム開始", GetColor(255, 255, 255), obj::fontInGame);
	DrawStringToHandle(X * 4 / 9 - 10, Y / 3 + 240, "設定", GetColor(255, 255, 255), obj::fontInGame);
	DrawStringToHandle(X * 4 / 9 - 10, Y / 3 + 280, "リザルト", GetColor(255, 255, 255), obj::fontInGame);
	DrawStringToHandle(X * 4 / 9 - 10, Y / 3 + 320, "ゲーム終了", GetColor(255, 255, 255), obj::fontInGame);
	DrawStringToHandle(X * 4 / 9 - 10, Y / 3 + 360, "keyboard test", GetColor(255, 255, 255), obj::fontInGame);
	setup::drawCursor(X * 4 / 9 - 15, Y / 3 + 215 + (stateSelect * 40), GetColor(255, 255, 255), 1, 0);
}
