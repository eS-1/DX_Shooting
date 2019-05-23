#include "SceneMgr.h"
#include "Config.h"
#include "Game.h"
#include "Menu.h"
#include "Player.h"
#include "Enemy.h"
#include "DxLib.h"

static myScene Scene = mySceneMenu;

static bool gameInitFlag = false;

void SceneMgrUpdate(Player* &player, std::deque<Bullet*> &bullets, std::deque<Enemy*> &enemys)
{
	switch (Scene)
	{
	case mySceneMenu:
		MenuUpdate();
		break;
	case mySceneGame:
		GameUpdate(player, bullets, enemys);
		break;
	case mySceneConfig:
		ConfigUpdate();
		break;
	}
}

void SceneMgrDraw(Player* &player, std::deque<Bullet*> &bullets, std::deque<Enemy*> &enemys)
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
			GameInitialize(player, enemys);
			gameInitFlag = false;
		}
		GameDraw(player, bullets, enemys);
		break;
	case mySceneConfig:
		ConfigDraw();
		gameInitFlag = true;
		break;
	}
}

void SceneMgrChange(myScene next)
{
	Scene = next;
}