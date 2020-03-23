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

// �V�[���Ǘ��̍X�V
void SceneMgrUpdate()
{
	switch (Scene)
	{
	case myScene::mySceneMenu:
		MenuUpdate();
		flag_game_init = true;
		flag_keyboard_init = true;
		break;
	case myScene::mySceneGame:
		if (flag_game_init)
		{
			Game_Init();
			flag_game_init = false;
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
		if (flag_keyboard_init)
		{
			Keyboard_Init();
			flag_keyboard_init = false;
		}
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