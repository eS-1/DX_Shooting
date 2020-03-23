#include "DxLib.h"
#include "../header/TestKeyboard.h"
#include "../header/Objects.h"
#include "../header/setup.h"
#include "../header/SceneMgr.h"


void Keyboard_Init()
{
	obj::myKeyboard.reset(new MyKeyboard());
}

void KeyboardUpdate()
{
	setup::KeyInput();
	if ((Input::pad & ~Input::old_pad) & PAD_INPUT_2)
	{
		SceneMgrChange(myScene::mySceneMenu);
	}
	obj::myKeyboard->update();
}

void KeyboardDraw()
{
	using namespace Input;
	if (obj::myKeyboard != nullptr)
	{
		obj::myKeyboard->draw();
	}

	// パッドの入力テスト
	int Color = GetColor(255, 255, 255);
	DrawFormatString(0, 0, Color, "X:%d Y:%d Z:%d",
		pad_input.X, pad_input.Y, pad_input.Z);
	DrawFormatString(0, 16, Color, "Rx:%d Ry:%d Rz:%d",
		pad_input.Rx, pad_input.Ry, pad_input.Rz);
	DrawFormatString(0, 32, Color, "Slider 0:%d 1:%d",
		pad_input.Slider[0], pad_input.Slider[1]);
	DrawFormatString(0, 48, Color, "POV 0:%d 1:%d 2:%d 3:%d",
		pad_input.POV[0], pad_input.POV[1],
		pad_input.POV[2], pad_input.POV[3]);
	DrawString(0, 64, "Button", Color);
	for (int i = 0; i < 32; i++)
	{
		DrawFormatString(64 + i % 8 * 64, 64 + i / 8 * 16, Color,
			"%2d:%d", i, pad_input.Buttons[i]);
	}
}
