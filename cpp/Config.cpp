#include "../header/Config.h"
#include "../header/setup.h"
#include "../header/Objects.h"
#include "../header/SceneMgr.h"
#include "DxLib.h"


// �ݒ��ʂ̍X�V
void ConfigUpdate()
{
	// ���j���[��ʂɑJ��
	if (CheckHitKey(KEY_INPUT_Q) != 0)
	{
		SceneMgrChange(myScene::mySceneMenu);
	}

	// �L�[�̓��͏�Ԃ��擾
	setup::KeyInput();

	int currentDiff = static_cast<int>(mySetup::diff);
	int easy = static_cast<int>(difficulty::easy);
	int extreme = static_cast<int>(difficulty::extreme);
	
	if (keyInput::D != 0 && currentDiff < extreme && (keyInput::D & ~keyInput::oldD))
	{
		mySetup::diff = static_cast<difficulty>(currentDiff + 1);
	}
	else if (keyInput::A != 0 && currentDiff > easy && (keyInput::A & ~keyInput::oldA))
	{
		mySetup::diff = static_cast<difficulty>(currentDiff - 1);
	}
}


// �ݒ��ʂ̕`��
void ConfigDraw()
{
	unsigned int bX = mySetup::battleX / 2;
	unsigned int Y = mySetup::Y / 4;

	int currentDiff = static_cast<int>(mySetup::diff);
	int easy = static_cast<int>(difficulty::easy);
	int extreme = static_cast<int>(difficulty::extreme);

	DrawStringToHandle(bX, Y, "�ݒ�", GetColor(255, 255, 255), obj::fontTitle);

	// ��Փx�����`��
	DrawString(bX, Y + 60, "��Փx: ", GetColor(255, 255, 255));
	DrawFormatString(bX + 100, Y + 60, GetColor(255, 255, 255),
		"%s", setup::NameOf(mySetup::diff).c_str());
	if (currentDiff < extreme)
	{
		setup::drawCursor(bX + 180, Y + 68, GetColor(255, 255, 255), 1, 0);
	}
	if (currentDiff > easy)
	{
		setup::drawCursor(bX + 80, Y + 68, GetColor(255, 255, 255), 1, 1);
	}

	DrawString(0, 5, "q�L�[�Ń��j���[�ɖ߂�", GetColor(255, 255, 255));
}
