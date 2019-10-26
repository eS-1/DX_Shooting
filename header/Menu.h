#pragma once
#include "setup.h"


enum class menuSelect
{
	start,
	config,
	result,
	exit
};

namespace Menu
{
	extern bool exitFlag;
}

void MenuUpdate();

void MenuDraw();
