#include "Config.h"
#include "SceneMgr.h"
#include "setup.h"
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
	DrawString(mySetup::battleX / 2, mySetup::Y / 4, "設定", GetColor(255, 255, 255));

	DrawFormatString(mySetup::battleX / 2, mySetup::Y / 4 + 40, GetColor(255, 255, 255),
		"難易度：%s", NameOf(mySetup::diff).c_str());

	DrawString(0, 0, "'q'キーでメニューに戻る", GetColor(255, 255, 255));
}