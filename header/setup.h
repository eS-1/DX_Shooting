#pragma once
#include <vector>
#include <string>


using scorePair = std::pair<unsigned int, std::string>;

// ��Փx
enum class difficulty
{
	easy,
	normal,
	hard,
	extreme
};

// �L�[�{�[�h�`��
enum class keyboard_draw
{
	lower,
	upper
};


namespace mySetup
{
	// ��ʃT�C�Y��x����
	extern unsigned int X;
	// ��ʃT�C�Y��y����
	extern unsigned int Y;
	// �Q�[����ʂ̃X�R�A
	extern unsigned int gameScore;
	// ���U���g��ʂŕ\������X�R�A
	extern std::vector<scorePair> resultScores;
	// �Q�[���̓�Փx
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
	extern int pad;
	extern int space;
	extern int analog_x;
	extern int analog_y;

	extern int old_W;
	extern int old_A;
	extern int old_S;
	extern int old_D;
	extern int old_E;
	extern int old_Q;
	extern int old_space;
	extern int old_pad;
	extern int old_analog_x;
	extern int old_analog_y;
};


namespace setup
{
	extern std::string NameOfDiff(difficulty diff);
	extern void KeyInput();
	extern void drawCursor(int x, int y, unsigned int Color, int FillFlag, int direction);
	extern std::vector<scorePair>::iterator MinItrOfVector(std::vector<scorePair>& result);
}
