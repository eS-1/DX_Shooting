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
	unsigned int bX = mySetup::X / 3;
	unsigned int Y = mySetup::Y / 4;

	int currentDiff = static_cast<int>(mySetup::diff);
	int easy = static_cast<int>(difficulty::easy);
	int extreme = static_cast<int>(difficulty::extreme);

	DrawStringToHandle(bX, Y, "�ݒ�", GetColor(255, 255, 255), obj::fontTitle);

	// ��Փx�����`��
	DrawStringToHandle(bX, Y + 100, "��Փx: ", GetColor(255, 255, 255), obj::fontInGame);
	DrawFormatStringToHandle(bX + 150, Y + 100, GetColor(255, 255, 255), obj::fontInGame,
		"%s", setup::NameOf(mySetup::diff).c_str());
	if (currentDiff < extreme)
	{
		setup::drawCursor(bX + 270, Y + 117, GetColor(255, 255, 255), 1, 0);
	}
	if (currentDiff > easy)
	{
		setup::drawCursor(bX + 120, Y + 117, GetColor(255, 255, 255), 1, 1);
	}

	DrawStringToHandle(0, 5, "q: �߂�", GetColor(255, 255, 255), obj::fontInGame);
}
