#include "Config.h"
#include "SceneMgr.h"
#include "setup.h"
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
	DrawString(mySetup::battleX / 2, mySetup::Y / 4, "�ݒ�", GetColor(255, 255, 255));

	DrawFormatString(mySetup::battleX / 2, mySetup::Y / 4 + 40, GetColor(255, 255, 255),
		"��Փx�F%s", NameOf(mySetup::diff).c_str());

	DrawString(0, 0, "'q'�L�[�Ń��j���[�ɖ߂�", GetColor(255, 255, 255));
}