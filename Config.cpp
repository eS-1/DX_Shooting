#include "Config.h"
#include "SceneMgr.h"
#include "DxLib.h"

void ConfigUpdate()
{
	if (CheckHitKey(KEY_INPUT_Q) != 0)
	{
		SceneMgrChange(mySceneMenu);
	}
}

void ConfigDraw()
{
	DrawString(0, 0, "�ݒ�", GetColor(255, 255, 255));
	DrawString(0, 20, "'q'�L�[�Ń��j���[�ɖ߂�", GetColor(255, 255, 255));
}