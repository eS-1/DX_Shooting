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

	// スコア表示
	int i = 1;
	int dy = mySetup::Y / 3;
	for (auto sc : mySetup::resultScores)
	{
		DrawFormatString(mySetup::battleX / 2, dy, GetColor(255, 255, 255), "%d: %d", i, sc);
		i++;
		dy += 20;
	}
}