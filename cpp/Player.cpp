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
	if (imgHandle == -1)
	{
		DrawBox(position.x - 40, position.y - 40, position.x + 40, position.y + 40, GetColor(255, 255, 255), true);
		return;
	}
	DrawExtendGraph(position.x - 40, position.y - 40, position.x + 40, position.y + 40, imgHandle, true);
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


void Player::fire(std::vector<std::unique_ptr<MyObject>>& bullets)
{
	oldKey = key;
	key = CheckHitKey(KEY_INPUT_SPACE);

	if ((key & ~oldKey) & KEY_INPUT_SPACE)
	{
		for (int i = 0; i < bullets.size(); i++)
		{
			if (bullets[i]->getRemoveFlag())
			{
				bullets[i]->setRemoveFlag(false);
				bullets[i]->setDirection(myVector2(0.0, -8.0));
				bullets[i]->setPosition(position);
				break;
			}
		}
	}
}
