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


// �V�[���Ǘ��̕`��
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


// �V�[���J�ڗp�̊֐�
void SceneMgrChange(myScene next)
{
	Scene = next;
}