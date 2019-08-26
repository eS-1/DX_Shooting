#include "SceneMgr.h"
#include "Config.h"
#include "Objects.h"
#include "Game.h"
#include "Menu.h"
#include "Result.h"


namespace
{
	// ��ʑJ�ڗp�̕ϐ�
	myScene Scene = mySceneMenu;
	// �Q�[����ʂ̏������t���O
	bool gameInitFlag = false;
}

// �V�[���Ǘ��̍X�V
void SceneMgrUpdate()
{
	switch (Scene)
	{
	case mySceneMenu:
		MenuUpdate();
		break;
	case mySceneGame:
		if (gameInitFlag)
		{
			Game_Init();
			gameInitFlag = false;
		}
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