#include "Config.h"
#include "setup.h"
#include "Objects.h"
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

	DrawStringToHandle(bX, Y, "設定", GetColor(255, 255, 255), obj::fontTitle);

	// 難易度調整描画
	DrawString(bX, Y + 60, "難易度: ", GetColor(255, 255, 255));
	DrawFormatString(bX + 100, Y + 60, GetColor(255, 255, 255),
		"%s", setup::NameOf(mySetup::diff).c_str());
	if (mySetup::diff < extreme)
	{
		setup::drawCursor(bX + 180, Y + 68, GetColor(255, 255, 255), 1, 0);
	}
	if (mySetup::diff > easy)
	{
		setup::drawCursor(bX + 80, Y + 68, GetColor(255, 255, 255), 1, 1);
	}

	DrawString(0, 5, "qキーでメニューに戻る", GetColor(255, 255, 255));
}
