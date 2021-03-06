#include "../header/Result.h"
#include "../header/setup.h"
#include "../header/Objects.h"
#include "../header/SceneMgr.h"
#include "DxLib.h"


// リザルト画面の更新
void Result_Update()
{
	setup::KeyInput();

	if (Input::Q != 0 || (Input::pad & PAD_INPUT_2))
	{
		SceneMgrChange(myScene::mySceneMenu);
	}
}


// リザルト画面の描画
void Result_Draw()
{
	DrawStringToHandle(mySetup::X / 3, mySetup::Y / 4, "ハイスコア", GetColor(255, 255, 255), obj::fontTitle);
	DrawStringToHandle(0, 5, "q: 戻る", GetColor(255, 255, 255), obj::fontInGame);

	// スコア表示
	int i = 1;
	int dy = mySetup::Y * 2 / 5;
	for (scorePair sc : mySetup::resultScores)
	{
		DrawFormatStringToHandle(mySetup::X / 3, dy, GetColor(255, 255, 255), obj::fontInGame,
			                     "%d: %d, %s", i, sc.first, sc.second.c_str());
		i++;
		dy += 40;
	}
}
