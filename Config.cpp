#include "Config.h"
#include "SceneMgr.h"
#include "DxLib.h"


// �ݒ��ʂ̍X�V
void ConfigUpdate()
{
	// ���j���[��ʂɑJ��
	if (CheckHitKey(KEY_INPUT_Q) != 0)
	{
		SceneMgrChange(mySceneMenu);
	}
}

// �ݒ��ʂ̕`��
void ConfigDraw()
{
	DrawString(0, 0, "�ݒ�", GetColor(255, 255, 255));
	DrawString(0, 20, "'q'�L�[�Ń��j���[�ɖ߂�", GetColor(255, 255, 255));
}