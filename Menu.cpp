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
	if (CheckHitKey(KEY_INPUT_C) != 0)
	{
		SceneMgrChange(mySceneConfig);
	}
	// ���U���g��ʂɑJ��
	if (CheckHitKey(KEY_INPUT_R) != 0)
	{
		SceneMgrChange(mySceneResult);
	}
}


// ���j���[��ʂ̕`��
void MenuDraw()
{
	DrawString((mySetup::battleX + mySetup::subX) * 3 / 7, mySetup::Y / 3, "���j���[���", GetColor(255, 255, 255));
	DrawString((mySetup::battleX + mySetup::subX) * 3 / 7, mySetup::Y / 3 + 20, "'s'�L�[�ŊJ�n", GetColor(255, 255, 255));
	DrawString((mySetup::battleX + mySetup::subX) * 3 / 7, mySetup::Y / 3 + 40, "'c'�L�[�Őݒ���", GetColor(255, 255, 255));
	DrawString((mySetup::battleX + mySetup::subX) * 3 / 7, mySetup::Y / 3 + 60, "'r'�L�[�Ń��U���g���", GetColor(255, 255, 255));
}