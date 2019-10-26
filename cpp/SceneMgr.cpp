#include "../header/SceneMgr.h"
#include "../header/Config.h"
#include "../header/Objects.h"
#include "../header/Game.h"
#include "../header/Menu.h"
#include "../header/Result.h"


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
	}
}


// シーン管理の描画
void SceneMgrDraw()
{
	switch (Scene)
	{
	case myScene::mySceneMenu:
		MenuDraw();
		gameInitFlag = true;
		break;
	case myScene::mySceneGame:
		GameDraw();
		break;
	case myScene::mySceneConfig:
		ConfigDraw();
		gameInitFlag = true;
		break;
	case myScene::mySceneResult:
		ResultDraw();
		gameInitFlag = true;
		break;
	}
}


// シーン遷移用の関数
void SceneMgrChange(myScene next)
{
	Scene = next;
}