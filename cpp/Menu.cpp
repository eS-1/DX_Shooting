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

	DrawStringToHandle(allX / 3, Y / 3, "2D�V���[�e�B���O(��)", GetColor(255, 255, 255), obj::fontTitle);
	DrawString(allX * 4 / 9, Y / 3 + 130, "�Q�[���J�n", GetColor(255, 255, 255));
	DrawString(allX * 4 / 9, Y / 3 + 160, "�ݒ�", GetColor(255, 255, 255));
	DrawString(allX * 4 / 9, Y / 3 + 190, "���U���g", GetColor(255, 255, 255));
	DrawString(allX * 4 / 9, Y / 3 + 220, "�Q�[���I��", GetColor(255, 255, 255));
	setup::drawCursor(allX * 4 / 9 - 5, Y / 3 + 140 + (stateSelect * 30), GetColor(255, 255, 255), 1, 0);
}
