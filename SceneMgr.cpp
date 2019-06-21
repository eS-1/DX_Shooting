#include "SceneMgr.h"
#include "Config.h"
#include "Game.h"
#include "Menu.h"
#include "Result.h"


// ��ʑJ�ڗp�̕ϐ�
static myScene Scene = mySceneMenu;

// �Q�[����ʂ̏������t���O
static bool gameInitFlag = false;


// �V�[���Ǘ��̍X�V
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


// �V�[���Ǘ��̕`��
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


// �V�[���J�ڗp�̊֐�
void SceneMgrChange(myScene next)
{
	Scene = next;
}