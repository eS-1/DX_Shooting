#include "Config.h"
#include "setup.h"
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

	// キーの入力状態を取得
	setup::KeyInput();
	
	if (keyInput::D != 0 && mySetup::diff < extreme && (keyInput::D & ~keyInput::oldD))
	{
		mySetup::diff = static_cast<difficulty>(mySetup::diff + 1);
	}
	else if (keyInput::A != 0 && mySetup::diff > easy && (keyInput::A & ~keyInput::oldA))
	{
		mySetup::diff = static_cast<difficulty>(mySetup::diff - 1);
	}
}


// 設定画面の描画
void ConfigDraw()
{
	unsigned int bX = mySetup::battleX / 2;
	unsigned int Y = mySetup::Y / 4;

	DrawString(bX, Y, "設定", GetColor(255, 255, 255));

	// 難易度調整描画
	DrawString(bX, Y + 40, "難易度：", GetColor(255, 255, 255));
	DrawFormatString(bX + 100, Y + 40, GetColor(255, 255, 255),
		"%s", setup::NameOf(mySetup::diff).c_str());
	if (mySetup::diff < extreme)
	{
		DrawTriangle(bX + 180, Y + 43, bX + 180, Y + 53,
			bX * sqrt(2.0) + 100, Y + 48, GetColor(255, 255, 255), 1);
	}
	if (mySetup::diff > easy)
	{
		DrawTriangle(bX + 80, Y + 48, bX * sqrt(2.0), Y + 43,
			bX * sqrt(2.0), Y + 53, GetColor(255, 255, 255), 1);
	}

	DrawString(0, 0, "'q'キーでメニューに戻る", GetColor(255, 255, 255));
}
