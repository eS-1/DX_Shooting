#include "Result.h"
#include "setup.h"
#include "SceneMgr.h"
#include "DxLib.h"


// ���U���g��ʂ̍X�V
void ResultUpdate()
{
	if (CheckHitKey(KEY_INPUT_Q) != 0)
	{
		SceneMgrChange(mySceneMenu);
	}
}


// ���U���g��ʂ̕`��
void ResultDraw()
{
	DrawString(0, 0, "���U���g���", GetColor(255, 255, 255));
	DrawString(0, 20, "'q'�L�[�Ń��j���[�ɖ߂�", GetColor(255, 255, 255));
}