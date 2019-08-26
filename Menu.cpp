#include "Menu.h"
#include "setup.h"
#include "Objects.h"
#include "SceneMgr.h"
#include "DxLib.h"


// ���j���[��ʂ̍X�V
void MenuUpdate()
{
	// �Q�[����ʂɑJ��
	if (CheckHitKey(KEY_INPUT_E) != 0)
	{
		SceneMgrChange(mySceneGame);
	}
	// �ݒ��ʂɑJ��
	else if (CheckHitKey(KEY_INPUT_C) != 0)
	{
		SceneMgrChange(mySceneConfig);
	}
	// ���U���g��ʂɑJ��
	else if (CheckHitKey(KEY_INPUT_R) != 0)
	{
		SceneMgrChange(mySceneResult);
	}
}


// ���j���[��ʂ̕`��
void MenuDraw()
{
	DrawStringToHandle(mySetup::allX * 2 / 7, mySetup::Y / 3, "2D�V���[�e�B���O(��)", GetColor(255, 255, 255), obj::fontTitle);
	DrawString(mySetup::allX * 4 / 9, mySetup::Y / 3 + 100, "e�L�[�ŊJ�n", GetColor(255, 255, 255));
	DrawString(mySetup::allX * 4 / 9, mySetup::Y / 3 + 130, "c�L�[�Őݒ���", GetColor(255, 255, 255));
	DrawString(mySetup::allX * 4 / 9, mySetup::Y / 3 + 160, "r�L�[�Ń��U���g���", GetColor(255, 255, 255));
}
