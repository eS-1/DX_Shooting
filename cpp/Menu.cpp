#include "../header/Menu.h"
#include "../header/setup.h"
#include "../header/Objects.h"
#include "../header/SceneMgr.h"
#include "DxLib.h"


bool Menu::exitFlag;


namespace
{
	myScene scene;
	menuSelect selection;
}

// メニュー画面の更新
void MenuUpdate()
{
	setup::KeyInput();

	if (((keyInput::W & ~keyInput::old_W) || ((keyInput::pad & ~keyInput::old_pad) & PAD_INPUT_UP)) && selection > menuSelect::start)
	{
		int current = static_cast<int>(selection);
		selection = static_cast<menuSelect>(current - 1);
	}
	else if (((keyInput::S & ~keyInput::old_S) || ((keyInput::pad & ~keyInput::old_pad) & PAD_INPUT_DOWN)) && selection < menuSelect::exit)
	{
		int current = static_cast<int>(selection);
		selection = static_cast<menuSelect>(current + 1);
	}

	// 各シーンに遷移
	switch (selection)
	{
	case menuSelect::start:
		if ((keyInput::space & ~keyInput::old_space) || (keyInput::pad & ~keyInput::old_pad) & PAD_INPUT_3)
		{
			SceneMgrChange(myScene::mySceneGame);
		}
		break;
	case menuSelect::config:
		if ((keyInput::space & ~keyInput::old_space) || (keyInput::pad & ~keyInput::old_pad) & PAD_INPUT_3)
		{
			SceneMgrChange(myScene::mySceneConfig);
		}
		break;
	case menuSelect::result:
		if ((keyInput::space & ~keyInput::old_space) || (keyInput::pad & ~keyInput::old_pad) & PAD_INPUT_3)
		{
			SceneMgrChange(myScene::mySceneResult);
		}
		break;
	case menuSelect::exit:
		if ((keyInput::space & ~keyInput::old_space) || (keyInput::pad & ~keyInput::old_pad) & PAD_INPUT_3)
		{
			Menu::exitFlag = true;
		}
		break;
	default:
		break;
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
	setup::drawCursor(X * 4 / 9 - 15, Y / 3 + 215 + (stateSelect * 40), GetColor(255, 255, 255), 1, 0);
}
