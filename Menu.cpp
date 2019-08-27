#include "Menu.h"
#include "setup.h"
#include "Objects.h"
#include "SceneMgr.h"
#include "DxLib.h"


namespace
{
	myScene scene;
	menuSelect selection;
}

// ���j���[��ʂ̍X�V
void MenuUpdate()
{
	setup::KeyInput();

	if (keyInput::W != 0 && (keyInput::W & ~keyInput::oldW) && selection > start)
	{
		selection = static_cast<menuSelect>(selection - 1);
	}
	else if (keyInput::S != 0 && (keyInput::S & ~keyInput::oldS) && selection < result)
	{
		selection = static_cast<menuSelect>(selection + 1);
	}

	// �Q�[����ʂɑJ��
	switch (selection)
	{
	case start:
		if (CheckHitKey(KEY_INPUT_E) != 0)
		{
			SceneMgrChange(mySceneGame);
		}
		break;
	case config:
		if (CheckHitKey(KEY_INPUT_E) != 0)
		{
			SceneMgrChange(mySceneConfig);
		}
		break;
	case result:
		if (CheckHitKey(KEY_INPUT_E) != 0)
		{
			SceneMgrChange(mySceneResult);
		}
		break;
	default:
		break;
	}
}


// ���j���[��ʂ̕`��
void MenuDraw()
{
	using namespace mySetup;

	DrawStringToHandle(allX / 3, Y / 3, "2D�V���[�e�B���O(��)", GetColor(255, 255, 255), obj::fontTitle);
	DrawString(allX * 4 / 9, Y / 3 + 130, "�Q�[���J�n", GetColor(255, 255, 255));
	DrawString(allX * 4 / 9, Y / 3 + 160, "�ݒ�", GetColor(255, 255, 255));
	DrawString(allX * 4 / 9, Y / 3 + 190, "���U���g", GetColor(255, 255, 255));
	setup::drawCursor(allX * 4 / 9 - 5, Y / 3 + 140 + (selection * 30), GetColor(255, 255, 255), 1, 0);
}
