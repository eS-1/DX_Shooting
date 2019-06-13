#pragma once
#include <vector>
#include <string>


// ��Փx
enum difficulty
{
	easy,
	normal,
	hard,
	extreme
};


struct mySetup
{
	// �퓬��ʃT�C�Y��x����
	static unsigned int battleX;
	// ���\����ʃT�C�Y��x����
	static unsigned int subX;
	// �S�̉�ʃT�C�Y��x����
	static unsigned int allX;
	// ��ʃT�C�Y��y����
	static unsigned int Y;
	// �Q�[����ʂ̃X�R�A
	static unsigned int gameScore;
	// ���U���g��ʂŕ\������X�R�A
	static std::vector<unsigned int> resultScores;
	// �Q�[���̓�Փx
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
