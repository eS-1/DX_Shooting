#pragma once
#include <array>

struct mySetup
{
	// �퓬��ʃT�C�Y��x����
	static unsigned int battleX;
	// �S�̉�ʃT�C�Y��x����
	static unsigned int subX;
	// ��ʃT�C�Y��y����
	static unsigned int Y;
	// �Q�[����ʂ̃X�R�A
	static unsigned int gameScore;
	// ���U���g��ʂŕ\������X�R�A
	static std::array<unsigned int, 5> resultScores;
};