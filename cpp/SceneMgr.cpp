#include "../header/SceneMgr.h"
#include "../header/Config.h"
#include "../header/Objects.h"
#include "../header/Game.h"
#include "../header/Menu.h"
#include "../header/Result.h"


namespace
{
	// ��ʑJ�ڗp�̕ϐ�
	myScene Scene = myScene::mySceneMenu;
	// �Q�[����ʂ̏������t���O
	bool gameInitFlag = false;
}

// �V�[���Ǘ��̍X�V
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


// �V�[���Ǘ��̕`��
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


// �V�[���J�ڗp�̊֐�
void SceneMgrChange(myScene next)
{
	Scene = next;
}