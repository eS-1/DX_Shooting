#pragma once
#include "setup.h"


enum class MenuSelect
{
	start,
	config,
	result,
	exit,
	test_keyboard,
};

namespace Menu
{
	extern bool exitFlag;
}

void Menu_Update();

void Menu_Draw();
