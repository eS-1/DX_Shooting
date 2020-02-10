#include "../header/setup.h"
#include "../header/Player.h"
#include "DxLib.h"


Player::Player(const myVector2& position)
	: MyObject(position), img_handle(LoadGraph("images/player.png")) {}


Player::~Player()
{
	DeleteGraph(img_handle);
}


bool Player::isPlayer()
{
	return true;
}


void Player::draw()
{
	int x = static_cast<int>(position.x);
	int y = static_cast<int>(position.y);
	if (img_handle == -1)
	{
		DrawBox(x - 40, y - 40, x + 40, y + 40, GetColor(255, 255, 255), true);
		return;
	}
	DrawExtendGraph(x - 40, y - 40, x + 40, y + 40, img_handle, true);
}


void Player::move()
{
	if ((keyInput::A || (keyInput::pad & PAD_INPUT_LEFT)) && position.x > 25)
	{
		direction.x -= 5.0;
	}

	if ((keyInput::D || (keyInput::pad & PAD_INPUT_RIGHT)) && position.x < mySetup::X - 25)
	{
		direction.x += 5.0;
	}

	if ((keyInput::W || (keyInput::pad & PAD_INPUT_UP)) && position.y > 25)
	{
		direction.y -= 5.0;
	}

	if ((keyInput::S || (keyInput::pad & PAD_INPUT_DOWN)) && position.y < mySetup::Y - 25)
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
	if ((keyInput::space & ~keyInput::old_space) || ((keyInput::pad & ~keyInput::old_pad) & PAD_INPUT_3))
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
