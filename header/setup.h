#pragma once
#include <vector>
#include <string>
#include "DxLib.h"


using scorePair = std::pair<unsigned int, std::string>;

// 難易度
enum class difficulty
{
	easy,
	normal,
	hard,
	extreme
};

// キーボード描画
enum class keyboard_draw
{
	lower,
	upper
};


namespace mySetup
{
	extern unsigned int X;
	extern unsigned int Y;
	extern unsigned int gameScore;
	extern std::vector<scorePair> resultScores;
	extern difficulty diff;
};


namespace Input
{
	extern DINPUT_JOYSTATE pad_input;
	extern int W;
	extern int A;
	extern int S;
	extern int D;
	extern int E;
	extern int Q;
	extern int pad;
	extern int space;
	extern int analog_LX;
	extern int analog_LY;
	extern int analog_RX;
	extern int analog_RY;

	extern int old_W;
	extern int old_A;
	extern int old_S;
	extern int old_D;
	extern int old_E;
	extern int old_Q;
	extern int old_space;
	extern int old_pad;
};


namespace setup
{
	extern std::string NameOfDiff(difficulty diff);
	extern void KeyInput();
	extern void drawCursor(int x, int y, unsigned int Color, int FillFlag, int direction);
	extern std::vector<scorePair>::iterator MinItrOfVector(std::vector<scorePair>& result);
}
