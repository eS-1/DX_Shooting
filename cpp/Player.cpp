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
	int color_white = GetColor(255, 255, 255);
	int x = static_cast<int>(position.x);
	int y = static_cast<int>(position.y);
	if (img_handle == -1)
	{
		DrawBox(x - 40, y - 40, x + 40, y + 40, color_white, true);
		return;
	}
	DrawExtendGraph(x - 40, y - 40, x + 40, y + 40, img_handle, true);
}


void Player::move()
{
	int dir_analog_x = Input::analog_LX / 50;
	int dir_analog_y = Input::analog_LY / 50;
	double diff_x = position.x + dir_analog_x;
	double diff_y = position.y + dir_analog_y;
	if (diff_x > 25 && diff_x < mySetup::X - 25)
	{
		direction.x = dir_analog_x;
	}
	if (diff_y > 25 && diff_y < mySetup::Y - 25)
	{
		direction.y = dir_analog_y;
	}

	if (Input::A && position.x > 25)
	{
		direction.x = -5.0;
	}

	if (Input::D && position.x < mySetup::X - 25)
	{
		direction.x = 5.0;
	}

	if (Input::W && position.y > 25)
	{
		direction.y = -5.0;
	}

	if (Input::S && position.y < mySetup::Y - 25)
	{
		direction.y = 5.0;
	}
	if (direction.length() > 5.0)
	{
		direction.normalize(5.0);
	}
	position += direction;
	int color_white = GetColor(255, 255, 255);
	int x = static_cast<int>(position.x);
	int y = static_cast<int>(position.y);
	DrawFormatStringToHandle(0, 60, color_white, obj::fontKeySmall, "x: %d", x);
	DrawFormatStringToHandle(0, 90, color_white, obj::fontKeySmall, "y: %d", y);
	DrawFormatStringToHandle(0, 120, color_white, obj::fontKeySmall, "dir_x: %d", static_cast<int>(direction.x));
	DrawFormatStringToHandle(0, 150, color_white, obj::fontKeySmall, "dir_y: %d", static_cast<int>(direction.y));
	direction.x = 0.0;
	direction.y = 0.0;
}


void Player::fire()
{
	if ((Input::space & ~Input::old_space) || ((Input::pad & ~Input::old_pad) & PAD_INPUT_3))
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
