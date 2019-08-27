#pragma once
#include <vector>
#include <string>


// 難易度
enum difficulty
{
	easy,
	normal,
	hard,
	extreme
};


namespace mySetup
{
	// 戦闘画面サイズのx成分
	extern unsigned int battleX;
	// 情報表示画面サイズのx成分
	extern unsigned int subX;
	// 全体画面サイズのx成分
	extern unsigned int allX;
	// 画面サイズのy成分
	extern unsigned int Y;
	// ゲーム画面のスコア
	extern unsigned int gameScore;
	// リザルト画面で表示するスコア
	extern std::vector<unsigned int> resultScores;
	// ゲームの難易度
	extern difficulty diff;
};


namespace keyInput
{
	extern int W;
	extern int A;
	extern int S;
	extern int D;

	extern int oldW;
	extern int oldA;
	extern int oldS;
	extern int oldD;
};


namespace setup
{
	extern std::string NameOf(difficulty diff);
	extern void KeyInput();
	extern void drawCursor(int x, int y, unsigned int Color, int FillFlag, int direction);
}
