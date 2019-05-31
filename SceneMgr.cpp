#include "SceneMgr.h"
#include "Config.h"
#include "Game.h"
#include "Menu.h"
#include "Result.h"
#include "Player.h"
#include "Enemy.h"
#include "DxLib.h"


// ��ʑJ�ڗp�̕ϐ�
static myScene Scene = mySceneMenu;

// �Q�[����ʂ̏������t���O
static bool gameInitFlag = false;


// �V�[���Ǘ��̍X�V
void SceneMgrUpdate(Player*& player, std::vector<Bullet*>& bullets, std::vector<Enemy*>& enemys)
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
	case mySceneResult:
		ResultUpdate();
		break;
	}
}


// �V�[���Ǘ��̕`��
void SceneMgrDraw(Player*& player, std::vector<Bullet*>& bullets, std::vector<Enemy*>& enemys)
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
	case mySceneResult:
		ResultDraw();
		gameInitFlag = true;
		break;
	}
}


// �V�[���J�ڗp�̊֐�
void SceneMgrChange(myScene next)
{
	Scene = next;
}