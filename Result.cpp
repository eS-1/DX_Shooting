#include "Result.h"
#include "setup.h"
#include "Objects.h"
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
	DrawStringToHandle(mySetup::battleX / 2, mySetup::Y / 4, "�n�C�X�R�A", GetColor(255, 255, 255), obj::fontTitle);
	DrawString(0, 5, "q�L�[�Ń��j���[�ɖ߂�", GetColor(255, 255, 255));

	// �X�R�A�\��
	int i = 1;
	int dy = mySetup::Y / 3;
	for (auto sc : mySetup::resultScores)
	{
		DrawFormatString(mySetup::battleX / 2, dy, GetColor(255, 255, 255), "%d: %d", i, sc);
		i++;
		dy += 20;
	}
}