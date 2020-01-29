#include "../header/setup.h"
#include "../header/Player.h"
#include "DxLib.h"


Player::Player(const myVector2& position)
	: MyObject(position), key(0), oldKey(0), imgHandle(LoadGraph("images/player.png")) {}


Player::~Player()
{
	DeleteGraph(imgHandle);
}


bool Player::isPlayer()
{
	return true;
}


void Player::draw()
{
	int x = static_cast<int>(position.x);
	int y = static_cast<int>(position.y);
	if (imgHandle == -1)
	{
		DrawBox(x - 40, y - 40, x + 40, y + 40, GetColor(255, 255, 255), true);
		return;
	}
	DrawExtendGraph(x - 40, y - 40, x + 40, y + 40, imgHandle, true);
}


void Player::move()
{
	if (CheckHitKey(KEY_INPUT_A) && position.x > 25)
	{
		direction.x -= 5.0;
	}

	if (CheckHitKey(KEY_INPUT_D) && position.x < mySetup::X - 25)
	{
		direction.x += 5.0;
	}

	if (CheckHitKey(KEY_INPUT_W) && position.y > 25)
	{
		direction.y -= 5.0;
	}

	if (CheckHitKey(KEY_INPUT_S) && position.y < mySetup::Y - 25)
	{
		direction.y += 5.0;
	}
	if (direction.length() > 5.0)
	{
		direction.normalize(5.0);
	}
	position += direction;
	direction = myVector2(0, 0);
}


void Player::fire()
{
	oldKey = key;
	key = CheckHitKey(KEY_INPUT_SPACE);

	if ((key & ~oldKey) & KEY_INPUT_SPACE)
	{
		for (const auto& bul : obj::bullets)
		{
			if (bul->getRemoveFlag())
			{
				bul->setRemoveFlag(false);
				bul->setDirection(myVector2(0.0, -8.0));
				bul->setPosition(position);
				break;
			}
		}
	}
}
