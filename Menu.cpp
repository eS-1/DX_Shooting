#include "Menu.h"
#include "SceneMgr.h"
#include "DxLib.h"


// メニュー画面の更新
void MenuUpdate()
{
	// ゲーム画面に遷移
	if (CheckHitKey(KEY_INPUT_S) != 0)
	{
		SceneMgrChange(mySceneGame);
	}
	// 設定画面に遷移
	if (CheckHitKey(KEY_INPUT_C) != 0)
	{
		SceneMgrChange(mySceneConfig);
	}
}

// メニュー画面の描画
void MenuDraw()
{
	DrawString(0, 0, "メニュー画面", GetColor(255, 255, 255));
	DrawString(0, 20, "'s'キーで開始", GetColor(255, 255, 255));
	DrawString(0, 40, "'c'キーで設定", GetColor(255, 255, 255));
}