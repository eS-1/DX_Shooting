#include "Result.h"
#include "setup.h"
#include "SceneMgr.h"
#include "DxLib.h"


// リザルト画面の更新
void ResultUpdate()
{
	if (CheckHitKey(KEY_INPUT_Q) != 0)
	{
		SceneMgrChange(mySceneMenu);
	}
}


// リザルト画面の描画
void ResultDraw()
{
	DrawString(0, 0, "リザルト画面", GetColor(255, 255, 255));
	DrawString(0, 20, "'q'キーでメニューに戻る", GetColor(255, 255, 255));
}