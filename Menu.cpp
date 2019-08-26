#include "Menu.h"
#include "setup.h"
#include "Objects.h"
#include "SceneMgr.h"
#include "DxLib.h"


// メニュー画面の更新
void MenuUpdate()
{
	// ゲーム画面に遷移
	if (CheckHitKey(KEY_INPUT_E) != 0)
	{
		SceneMgrChange(mySceneGame);
	}
	// 設定画面に遷移
	else if (CheckHitKey(KEY_INPUT_C) != 0)
	{
		SceneMgrChange(mySceneConfig);
	}
	// リザルト画面に遷移
	else if (CheckHitKey(KEY_INPUT_R) != 0)
	{
		SceneMgrChange(mySceneResult);
	}
}


// メニュー画面の描画
void MenuDraw()
{
	DrawStringToHandle(mySetup::allX * 2 / 7, mySetup::Y / 3, "2Dシューティング(仮)", GetColor(255, 255, 255), obj::fontTitle);
	DrawString(mySetup::allX * 4 / 9, mySetup::Y / 3 + 100, "eキーで開始", GetColor(255, 255, 255));
	DrawString(mySetup::allX * 4 / 9, mySetup::Y / 3 + 130, "cキーで設定画面", GetColor(255, 255, 255));
	DrawString(mySetup::allX * 4 / 9, mySetup::Y / 3 + 160, "rキーでリザルト画面", GetColor(255, 255, 255));
}
