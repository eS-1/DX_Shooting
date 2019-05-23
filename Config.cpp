#include "Config.h"
#include "SceneMgr.h"
#include "DxLib.h"

void ConfigUpdate()
{
	if (CheckHitKey(KEY_INPUT_Q) != 0)
	{
		SceneMgrChange(mySceneMenu);
	}
}

void ConfigDraw()
{
	DrawString(0, 0, "設定", GetColor(255, 255, 255));
	DrawString(0, 20, "'q'キーでメニューに戻る", GetColor(255, 255, 255));
}