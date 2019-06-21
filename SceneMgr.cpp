#include "SceneMgr.h"
#include "Config.h"
#include "Game.h"
#include "Menu.h"
#include "Result.h"


// 画面遷移用の変数
static myScene Scene = mySceneMenu;

// ゲーム画面の初期化フラグ
static bool gameInitFlag = false;


// シーン管理の更新
void SceneMgrUpdate()
{
	switch (Scene)
	{
	case mySceneMenu:
		MenuUpdate();
		break;
	case mySceneGame:
		GameUpdate();
		break;
	case mySceneConfig:
		ConfigUpdate();
		break;
	case mySceneResult:
		ResultUpdate();
		break;
	}
}


// シーン管理の描画
void SceneMgrDraw()
{
	switch (Scene)
	{
	case mySceneMenu:
		MenuDraw();
		gameInitFlag = true;
		break;
	case mySceneGame:
		if (gameInitFlag)
		{
			Game_Init();
			gameInitFlag = false;
		}
		GameDraw();
		break;
	case mySceneConfig:
		ConfigDraw();
		gameInitFlag = true;
		break;
	case mySceneResult:
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