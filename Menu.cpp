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
	DrawString(0, 0, "���j���[���", GetColor(255, 255, 255));
	DrawString(0, 20, "'s'�L�[�ŊJ�n", GetColor(255, 255, 255));
	DrawString(0, 40, "'c'�L�[�Őݒ�", GetColor(255, 255, 255));
}