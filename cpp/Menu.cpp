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

	if (((Input::W & ~Input::old_W) ||
		((Input::pad & ~Input::old_pad) & PAD_INPUT_UP)))
	{
		int current = static_cast<int>(selection);
		if (selection > MenuSelect::start)
		{
			selection = static_cast<MenuSelect>(current - 1);
		}
		else
		{
			selection = MenuSelect::keyboard;
		}
	}
	else if (((Input::S & ~Input::old_S) ||
		     ((Input::pad & ~Input::old_pad) & PAD_INPUT_DOWN)))
	{
		int current = static_cast<int>(selection);
		if (selection < MenuSelect::keyboard)
		{
			selection = static_cast<MenuSelect>(current + 1);
		}
		else
		{
			selection = MenuSelect::start;
		}
	}

	// �e�V�[���ɑJ��
	if ((Input::space & ~Input::old_space) || (Input::pad & ~Input::old_pad) & PAD_INPUT_3)
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
	int color_white = GetColor(255, 255, 255);

	DrawStringToHandle(X * 5 / 16, Y / 3, "Simple Shooter 2D", color_white, obj::fontTitle);
	DrawStringToHandle(X * 4 / 9 - 10, Y / 3 + 200, "�Q�[���J�n", color_white, obj::fontInGame);
	DrawStringToHandle(X * 4 / 9 - 10, Y / 3 + 240, "�ݒ�", color_white, obj::fontInGame);
	DrawStringToHandle(X * 4 / 9 - 10, Y / 3 + 280, "���U���g", color_white, obj::fontInGame);
	DrawStringToHandle(X * 4 / 9 - 10, Y / 3 + 320, "�Q�[���I��", color_white, obj::fontInGame);
	DrawStringToHandle(X * 4 / 9 - 10, Y / 3 + 360, "keyboard test", color_white, obj::fontInGame);
	setup::drawCursor(X * 4 / 9 - 15, Y / 3 + 215 + (stateSelect * 40), color_white, 1, 0);
}
