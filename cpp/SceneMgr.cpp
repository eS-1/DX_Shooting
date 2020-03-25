#include "../header/SceneMgr.h"
#include "../header/Config.h"
#include "../header/Objects.h"
#include "../header/Game.h"
#include "../header/Menu.h"
#include "../header/Result.h"
#include "../header/SaveName.h"
#include "../header/TestKeyboard.h"


namespace
{
	myScene Scene = myScene::mySceneMenu;
	bool flag_game_init = false;
	bool flag_keyboard_init = false;
}

// シーン管理の更新
void SceneMgr_Update()
{
	switch (Scene)
	{
	case myScene::mySceneMenu:
		Menu_Update();
		flag_game_init = true;
		flag_keyboard_init = true;
		break;
	case myScene::mySceneGame:
		if (flag_game_init)
		{
			Game_Init();
			flag_game_init = false;
		}
		Game_Update();
		break;
	case myScene::mySceneConfig:
		Config_Update();
		break;
	case myScene::mySceneResult:
		Result_Update();
		break;
	case myScene::mySceneSaveName:
		if (flag_keyboard_init)
		{
			Keyboard_Init();
			SaveName_Init();
			flag_keyboard_init = false;
		}
		SaveName_Update();
		break;
	/*case myScene::mySceneTestKeyboard:
		if (flag_keyboard_init)
		{
			Keyboard_Init();
			flag_keyboard_init = false;
		}
		Keyboard_Update();
		break;*/
	default:
		break;
	}
}


// シーン管理の描画
void SceneMgr_Draw()
{
	switch (Scene)
	{
	case myScene::mySceneMenu:
		Menu_Draw();
		break;
	case myScene::mySceneGame:
		Game_Draw();
		break;
	case myScene::mySceneConfig:
		Config_Draw();
		break;
	case myScene::mySceneResult:
		Result_Draw();
		break;
	case myScene::mySceneSaveName:
		SaveName_Draw();
		break;
	/*case myScene::mySceneTestKeyboard:
		Keyboard_Draw();
		break;*/
	default:
		break;
	}
}


// シーン遷移用の関数
void SceneMgrChange(myScene next)
{
	Scene = next;
}