#pragma once
#include "setup.h"


enum class MenuSelect
{
	start,
	config,
	result,
	exit,
	keyboard,
};

namespace Menu
{
	extern bool exitFlag;
}

void MenuUpdate();

void MenuDraw();
