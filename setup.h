#pragma once
#include <vector>

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
};