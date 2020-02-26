#include "DxLib.h"
#include "../header/TestKeyboard.h"
#include "../header/Objects.h"
#include "../header/setup.h"
#include "../header/SceneMgr.h"


void KeyboardUpdate()
{
	setup::KeyInput();
	if (keyInput::Q != 0 || (keyInput::pad & PAD_INPUT_2))
	{
		SceneMgrChange(myScene::mySceneMenu);
	}
	obj::myKeyboard.update();
}

void KeyboardDraw()
{
	obj::myKeyboard.draw();
}
