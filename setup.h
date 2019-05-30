#pragma once
#include <array>

struct mySetup
{
	// 戦闘画面サイズのx成分
	static unsigned int battleX;
	// 全体画面サイズのx成分
	static unsigned int subX;
	// 画面サイズのy成分
	static unsigned int Y;
	// ゲーム画面のスコア
	static unsigned int gameScore;
	// リザルト画面で表示するスコア
	static std::array<unsigned int, 5> resultScores;
};