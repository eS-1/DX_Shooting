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
	// 画面遷移用の変数
	myScene Scene = myScene::mySceneMenu;
	// ゲーム画面の初期化フラグ
	bool gameInitFlag = false;
}

// シーン管理の更新
void SceneMgrUpdate()
{
	switch (Scene)
	{
	case myScene::mySceneMenu:
		MenuUpdate();
		gameInitFlag = true;
		break;
	case myScene::mySceneGame:
		if (gameInitFlag)
		{
			Game_Init();
			gameInitFlag = false;
		}
		GameUpdate();
		break;
	case myScene::mySceneConfig:
		ConfigUpdate();
		break;
	case myScene::mySceneResult:
		ResultUpdate();
		break;
	case myScene::mySceneSaveName:
		SaveNameUpdate();
		break;
	case myScene::mySceneKeyboard:
		KeyboardUpdate();
		break;
	}
}


// シーン管理の描画
void SceneMgrDraw()
{
	switch (Scene)
	{
	case myScene::mySceneMenu:
		MenuDraw();
		break;
	case myScene::mySceneGame:
		GameDraw();
		break;
	case myScene::mySceneConfig:
		ConfigDraw();
		break;
	case myScene::mySceneResult:
		ResultDraw();
		break;
	case myScene::mySceneSaveName:
		SaveNameDraw();
		break;
	case myScene::mySceneKeyboard:
		KeyboardDraw();
		break;
	}
}


// シーン遷移用の関数
void SceneMgrChange(myScene next)
{
	Scene = next;
}