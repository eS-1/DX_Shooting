#include "../header/Result.h"
#include "../header/setup.h"
#include "../header/Objects.h"
#include "../header/SceneMgr.h"
#include "DxLib.h"


// ���U���g��ʂ̍X�V
void ResultUpdate()
{
	setup::KeyInput();

	if (keyInput::Q != 0 || (keyInput::pad & PAD_INPUT_2))
	{
		SceneMgrChange(myScene::mySceneMenu);
	}
}


// ���U���g��ʂ̕`��
void ResultDraw()
{
	DrawStringToHandle(mySetup::X / 3, mySetup::Y / 4, "�n�C�X�R�A", GetColor(255, 255, 255), obj::fontTitle);
	DrawStringToHandle(0, 5, "q: �߂�", GetColor(255, 255, 255), obj::fontInGame);

	// �X�R�A�\��
	int i = 1;
	int dy = mySetup::Y * 2 / 5;
	for (auto sc : mySetup::resultScores)
	{
		DrawFormatStringToHandle(mySetup::X / 3, dy, GetColor(255, 255, 255), obj::fontInGame,
			                     "%d: %d, %s", i, sc.first, sc.second.c_str());
		i++;
		dy += 40;
	}
}