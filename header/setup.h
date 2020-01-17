#pragma once
#include <vector>
#include <string>


// 難易度
enum class difficulty
{
	easy,
	normal,
	hard,
	extreme
};


namespace mySetup
{
	// 画面サイズのx成分
	extern unsigned int X;
	// 画面サイズのy成分
	extern unsigned int Y;
	// ゲーム画面のスコア
	extern unsigned int gameScore;
	// リザルト画面で表示するスコア
	extern std::vector<std::pair<unsigned int, std::string>> resultScores;
	// ゲームの難易度
	extern difficulty diff;
};


namespace keyInput
{
	extern int W;
	extern int A;
	extern int S;
	extern int D;
	extern int E;
	extern int Q;

	extern int oldW;
	extern int oldA;
	extern int oldS;
	extern int oldD;
	extern int oldE;
	extern int oldQ;
};


namespace setup
{
	extern std::string NameOfDiff(difficulty diff);
	extern void KeyInput();
	extern void drawCursor(int x, int y, unsigned int Color, int FillFlag, int direction);
	extern std::vector<std::pair<unsigned int, std::string>>::iterator
		MinItrOfVector(std::vector<std::pair<unsigned int, std::string>>& result);
}
