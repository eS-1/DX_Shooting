#include "Menu.h"
#include "SceneMgr.h"
#include "DxLib.h"


void MenuUpdate()
{
	if (CheckHitKey(KEY_INPUT_S) != 0)
	{
		SceneMgrChange(mySceneGame);
	}
	if (CheckHitKey(KEY_INPUT_C) != 0)
	{
		SceneMgrChange(mySceneConfig);
	}
}

void MenuDraw()
{
	DrawString(0, 0, "メニュー画面", GetColor(255, 255, 255));
	DrawString(0, 20, "'s'キーで開始", GetColor(255, 255, 255));
	DrawString(0, 40, "'c'キーで設定", GetColor(255, 255, 255));
}