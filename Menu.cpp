#include "Menu.h"
#include "setup.h"
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
	// リザルト画面に遷移
	if (CheckHitKey(KEY_INPUT_R) != 0)
	{
		SceneMgrChange(mySceneResult);
	}
}


// メニュー画面の描画
void MenuDraw()
{
	DrawString((mySetup::battleX + mySetup::subX) * 3 / 7, mySetup::Y / 3, "メニュー画面", GetColor(255, 255, 255));
	DrawString((mySetup::battleX + mySetup::subX) * 3 / 7, mySetup::Y / 3 + 20, "'s'キーで開始", GetColor(255, 255, 255));
	DrawString((mySetup::battleX + mySetup::subX) * 3 / 7, mySetup::Y / 3 + 40, "'c'キーで設定画面", GetColor(255, 255, 255));
	DrawString((mySetup::battleX + mySetup::subX) * 3 / 7, mySetup::Y / 3 + 60, "'r'キーでリザルト画面", GetColor(255, 255, 255));
}