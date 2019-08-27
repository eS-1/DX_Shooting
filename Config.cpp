#include "Config.h"
#include "setup.h"
#include "Objects.h"
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

	DrawStringToHandle(bX, Y, "�ݒ�", GetColor(255, 255, 255), obj::fontTitle);

	// ��Փx�����`��
	DrawString(bX, Y + 60, "��Փx: ", GetColor(255, 255, 255));
	DrawFormatString(bX + 100, Y + 60, GetColor(255, 255, 255),
		"%s", setup::NameOf(mySetup::diff).c_str());
	if (mySetup::diff < extreme)
	{
		setup::drawCursor(bX + 180, Y + 68, GetColor(255, 255, 255), 1, 0);
	}
	if (mySetup::diff > easy)
	{
		setup::drawCursor(bX + 80, Y + 68, GetColor(255, 255, 255), 1, 1);
	}

	DrawString(0, 5, "q�L�[�Ń��j���[�ɖ߂�", GetColor(255, 255, 255));
}
