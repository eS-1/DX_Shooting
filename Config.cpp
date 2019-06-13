#include "Config.h"
#include "setup.h"
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

	// �L�[�̓��͏�Ԃ��擾
	setup::KeyInput();
	
	if (keyInput::D != 0 && mySetup::diff < extreme && (keyInput::D & ~keyInput::oldD))
	{
		mySetup::diff = static_cast<difficulty>(mySetup::diff + 1);
	}
	else if (keyInput::A != 0 && mySetup::diff > easy && (keyInput::A & ~keyInput::oldA))
	{
		mySetup::diff = static_cast<difficulty>(mySetup::diff - 1);
	}
}


// �ݒ��ʂ̕`��
void ConfigDraw()
{
	unsigned int bX = mySetup::battleX / 2;
	unsigned int Y = mySetup::Y / 4;

	DrawString(bX, Y, "�ݒ�", GetColor(255, 255, 255));

	// ��Փx�����`��
	DrawString(bX, Y + 40, "��Փx�F", GetColor(255, 255, 255));
	DrawFormatString(bX + 100, Y + 40, GetColor(255, 255, 255),
		"%s", setup::NameOf(mySetup::diff).c_str());
	if (mySetup::diff < extreme)
	{
		DrawTriangle(bX + 180, Y + 43, bX + 180, Y + 53,
			bX * sqrt(2.0) + 100, Y + 48, GetColor(255, 255, 255), 1);
	}
	if (mySetup::diff > easy)
	{
		DrawTriangle(bX + 80, Y + 48, bX * sqrt(2.0), Y + 43,
			bX * sqrt(2.0), Y + 53, GetColor(255, 255, 255), 1);
	}

	DrawString(0, 0, "'q'�L�[�Ń��j���[�ɖ߂�", GetColor(255, 255, 255));
}
