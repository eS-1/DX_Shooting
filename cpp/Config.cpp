#include "../header/Config.h"
#include "../header/setup.h"
#include "../header/Objects.h"
#include "../header/SceneMgr.h"
#include "DxLib.h"


// 設定画面の更新
void ConfigUpdate()
{
	// メニュー画面に遷移
	if (CheckHitKey(KEY_INPUT_Q) != 0)
	{
		SceneMgrChange(myScene::mySceneMenu);
	}

	// キーの入力状態を取得
	setup::KeyInput();

	int currentDiff = static_cast<int>(mySetup::diff);
	int easy = static_cast<int>(difficulty::easy);
	int extreme = static_cast<int>(difficulty::extreme);
	
	if (keyInput::D != 0 && currentDiff < extreme && (keyInput::D & ~keyInput::oldD))
	{
		mySetup::diff = static_cast<difficulty>(currentDiff + 1);
	}
	else if (keyInput::A != 0 && currentDiff > easy && (keyInput::A & ~keyInput::oldA))
	{
		mySetup::diff = static_cast<difficulty>(currentDiff - 1);
	}
}


// 設定画面の描画
void ConfigDraw()
{
	unsigned int bX = mySetup::X / 3;
	unsigned int Y = mySetup::Y / 4;

	int currentDiff = static_cast<int>(mySetup::diff);
	int easy = static_cast<int>(difficulty::easy);
	int extreme = static_cast<int>(difficulty::extreme);

	DrawStringToHandle(bX, Y, "設定", GetColor(255, 255, 255), obj::fontTitle);

	// 難易度調整描画
	DrawStringToHandle(bX, Y + 100, "難易度: ", GetColor(255, 255, 255), obj::fontInGame);
	DrawFormatStringToHandle(bX + 150, Y + 100, GetColor(255, 255, 255), obj::fontInGame,
		"%s", setup::NameOf(mySetup::diff).c_str());
	if (currentDiff < extreme)
	{
		setup::drawCursor(bX + 270, Y + 117, GetColor(255, 255, 255), 1, 0);
	}
	if (currentDiff > easy)
	{
		setup::drawCursor(bX + 120, Y + 117, GetColor(255, 255, 255), 1, 1);
	}

	DrawStringToHandle(0, 5, "q: 戻る", GetColor(255, 255, 255), obj::fontInGame);
}
