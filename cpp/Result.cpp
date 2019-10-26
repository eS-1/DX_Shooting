#include "../header/Result.h"
#include "../header/setup.h"
#include "../header/Objects.h"
#include "../header/SceneMgr.h"
#include "DxLib.h"


// リザルト画面の更新
void ResultUpdate()
{
	if (CheckHitKey(KEY_INPUT_Q) != 0)
	{
		SceneMgrChange(myScene::mySceneMenu);
	}
}


// リザルト画面の描画
void ResultDraw()
{
	DrawStringToHandle(mySetup::battleX / 2, mySetup::Y / 4, "ハイスコア", GetColor(255, 255, 255), obj::fontTitle);
	DrawString(0, 5, "qキーでメニューに戻る", GetColor(255, 255, 255));

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