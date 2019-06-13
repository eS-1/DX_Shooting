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


struct mySetup
{
	// 戦闘画面サイズのx成分
	static unsigned int battleX;
	// 情報表示画面サイズのx成分
	static unsigned int subX;
	// 全体画面サイズのx成分
	static unsigned int allX;
	// 画面サイズのy成分
	static unsigned int Y;
	// ゲーム画面のスコア
	static unsigned int gameScore;
	// リザルト画面で表示するスコア
	static std::vector<unsigned int> resultScores;
	// ゲームの難易度
	static difficulty diff;
};


struct keyInput
{
	static int W;
	static int A;
	static int S;
	static int D;

	static int oldW;
	static int oldA;
	static int oldS;
	static int oldD;
};


namespace setup
{
	std::string NameOf(difficulty diff);
	void KeyInput();
}
