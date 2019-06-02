#include "Menu.h"
#include "setup.h"
#include "SceneMgr.h"
#include "DxLib.h"


// ���j���[��ʂ̍X�V
void MenuUpdate()
{
	// �Q�[����ʂɑJ��
	if (CheckHitKey(KEY_INPUT_S) != 0)
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
	DrawString(mySetup::allX * 3 / 7, mySetup::Y / 3 + 40, "���j���[���", GetColor(255, 255, 255));
	DrawString(mySetup::allX * 3 / 7, mySetup::Y / 3 + 60, "'s'�L�[�ŊJ�n", GetColor(255, 255, 255));
	DrawString(mySetup::allX * 3 / 7, mySetup::Y / 3 + 80, "'c'�L�[�Őݒ���", GetColor(255, 255, 255));
	DrawString(mySetup::allX * 3 / 7, mySetup::Y / 3 + 100, "'r'�L�[�Ń��U���g���", GetColor(255, 255, 255));
}