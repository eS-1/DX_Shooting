#pragma once
#include <memory>
#include "Bullet.h"
#include "Enemy.h"
#include "Player.h"
#include "Keyboard.h"


namespace obj
{
	extern std::unique_ptr<MyObject> player;
	extern std::vector<std::unique_ptr<MyObject>> bullets;
	extern std::vector<std::unique_ptr<MyObject>> enemys;
	extern std::vector<std::unique_ptr<MyObject>> enBullets;
	extern std::unique_ptr<MyKeyboard> myKeyboard;
	extern int fontTitle;
	extern int fontInGame;
	extern int fontKeySmall;
}
