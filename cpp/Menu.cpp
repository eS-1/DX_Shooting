#include "../header/Menu.h"
#include "../header/setup.h"
#include "../header/Objects.h"
#include "../header/SceneMgr.h"
#include "DxLib.h"


bool Menu::exitFlag;

namespace
{
	myScene scene;
	MenuSelect selection;
}


// ���j���[��ʂ̍X�V
void MenuUpdate()
{
	setup::KeyInput();

	if (((keyInput::W & ~keyInput::old_W) ||
		((keyInput::pad & ~keyInput::old_pad) & PAD_INPUT_UP)) &&
		selection > MenuSelect::start)
	{
		int current = static_cast<int>(selection);
		selection = static_cast<MenuSelect>(current - 1);
	}
	else if (((keyInput::S & ~keyInput::old_S) ||
		     ((keyInput::pad & ~keyInput::old_pad) & PAD_INPUT_DOWN)) &&
		     selection < MenuSelect::keyboard)
	{
		int current = static_cast<int>(selection);
		selection = static_cast<MenuSelect>(current + 1);
	}

	// �e�V�[���ɑJ��
	if ((keyInput::space & ~keyInput::old_space) || (keyInput::pad & ~keyInput::old_pad) & PAD_INPUT_3)
	{
		switch (selection)
		{
		case MenuSelect::start:
			SceneMgrChange(myScene::mySceneGame);
			break;
		case MenuSelect::config:
			SceneMgrChange(myScene::mySceneConfig);
			break;
		case MenuSelect::result:
			SceneMgrChange(myScene::mySceneResult);
			break;
		case MenuSelect::exit:
			Menu::exitFlag = true;
			break;
		case MenuSelect::keyboard:
			SceneMgrChange(myScene::mySceneKeyboard);
			break;
		default:
			break;
		}
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
	DrawStringToHandle(X * 4 / 9 - 10, Y / 3 + 360, "keyboard test", GetColor(255, 255, 255), obj::fontInGame);
	setup::drawCursor(X * 4 / 9 - 15, Y / 3 + 215 + (stateSelect * 40), GetColor(255, 255, 255), 1, 0);
}
