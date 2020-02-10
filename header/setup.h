#pragma once
#include <vector>
#include <string>


// ��Փx
enum class difficulty
{
	easy,
	normal,
	hard,
	extreme
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
	extern std::vector<std::pair<unsigned int, std::string>> resultScores;
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
	extern int space;
	extern int pad;

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
	extern std::vector<std::pair<unsigned int, std::string>>::iterator
		MinItrOfVector(std::vector<std::pair<unsigned int, std::string>>& result);
}
