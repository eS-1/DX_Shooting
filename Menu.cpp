#include "setup.h"
#include "Menu.h"
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
}


// ���j���[��ʂ̕`��
void MenuDraw()
{
	DrawString((mySetup::battleX + mySetup::subX) * 3 / 7, mySetup::Y / 3, "���j���[���", GetColor(255, 255, 255));
	DrawString((mySetup::battleX + mySetup::subX) * 3 / 7, mySetup::Y / 3 + 20, "'s'�L�[�ŊJ�n", GetColor(255, 255, 255));
	DrawString((mySetup::battleX + mySetup::subX) * 3 / 7, mySetup::Y / 3 + 40, "'c'�L�[�Őݒ�", GetColor(255, 255, 255));
}