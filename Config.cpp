#include "Config.h"
#include "SceneMgr.h"
#include "DxLib.h"


// 設定画面の更新
void ConfigUpdate()
{
	// メニュー画面に遷移
	if (CheckHitKey(KEY_INPUT_Q) != 0)
	{
		SceneMgrChange(mySceneMenu);
	}
}

// 設定画面の描画
void ConfigDraw()
{
	DrawString(0, 0, "設定", GetColor(255, 255, 255));
	DrawString(0, 20, "'q'キーでメニューに戻る", GetColor(255, 255, 255));
}