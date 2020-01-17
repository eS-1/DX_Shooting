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
