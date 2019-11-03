#include "../header/Menu.h"
#include "../header/setup.h"
#include "../header/Objects.h"
#include "../header/SceneMgr.h"
#include "DxLib.h"


bool Menu::exitFlag;


namespace
{
	myScene scene;
	menuSelect selection;
}

// ���j���[��ʂ̍X�V
void MenuUpdate()
{
	setup::KeyInput();

	if (keyInput::W != 0 && (keyInput::W & ~keyInput::oldW) && selection > menuSelect::start)
	{
		int current = static_cast<int>(selection);
		selection = static_cast<menuSelect>(current - 1);
	}
	else if (keyInput::S != 0 && (keyInput::S & ~keyInput::oldS) && selection < menuSelect::exit)
	{
		int current = static_cast<int>(selection);
		selection = static_cast<menuSelect>(current + 1);
	}

	// �Q�[����ʂɑJ��
	switch (selection)
	{
	case menuSelect::start:
		if (CheckHitKey(KEY_INPUT_E) != 0)
		{
			SceneMgrChange(myScene::mySceneGame);
		}
		break;
	case menuSelect::config:
		if (CheckHitKey(KEY_INPUT_E) != 0)
		{
			SceneMgrChange(myScene::mySceneConfig);
		}
		break;
	case menuSelect::result:
		if (CheckHitKey(KEY_INPUT_E) != 0)
		{
			SceneMgrChange(myScene::mySceneResult);
		}
		break;
	case menuSelect::exit:
		if (CheckHitKey(KEY_INPUT_E) != 0)
		{
			Menu::exitFlag = true;
		}
	default:
		break;
	}
}


// ���j���[��ʂ̕`��
void MenuDraw()
{
	using namespace mySetup;

	int stateSelect = static_cast<int>(selection);

	DrawStringToHandle(X * 5 / 16, Y / 3, "Simple Shooter 2D", GetColor(255, 255, 255), obj::fontTitle);
	DrawStringToHandle(X * 4 / 9 - 10, Y / 3 + 200, "�Q�[���J�n", GetColor(255, 255, 255), obj::fontInGame);
	DrawStringToHandle(X * 4 / 9 - 10, Y / 3 + 240, "�ݒ�", GetColor(255, 255, 255), obj::fontInGame);
	DrawStringToHandle(X * 4 / 9 - 10, Y / 3 + 280, "���U���g", GetColor(255, 255, 255), obj::fontInGame);
	DrawStringToHandle(X * 4 / 9 - 10, Y / 3 + 320, "�Q�[���I��", GetColor(255, 255, 255), obj::fontInGame);
	setup::drawCursor(X * 4 / 9 - 15, Y / 3 + 215 + (stateSelect * 40), GetColor(255, 255, 255), 1, 0);
}
