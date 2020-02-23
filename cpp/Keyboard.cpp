#include "../header/Keyboard.h"
#include "../header/setup.h"
#include "../header/Objects.h"


MyKeyboard::MyKeyboard() : position(100.0, 100.0),
                           color_base(GetColor(30, 30, 30)),
	                       color_keys(GetColor(60, 60, 60)),
	                       color_keys_others(GetColor(80, 80, 80)),
	                       color_selected(GetColor(150, 150, 150)),
	                       color_str(GetColor(255, 255, 255)),
	                       size_x(940.0),
	                       size_y(370.0),
	                       size_key_x(80.0),
	                       size_key_y(50.0),
	                       distance_key(8.0),
	                       cursor(0)
{}

void MyKeyboard::update()
{
	if (keyInput::pad & PAD_INPUT_LEFT)
	{
		cursor--;
	}
	else if (keyInput::pad & PAD_INPUT_RIGHT)
	{
		cursor++;
	}
	else if (keyInput::pad & PAD_INPUT_UP)
	{
		cursor -= 10;
	}
	else if (keyInput::pad & PAD_INPUT_DOWN)
	{
		cursor += 10;
	}
}

void MyKeyboard::draw()
{
	// draw background
	DrawBox(position.x, position.y, position.x + size_x, position.y + size_y, color_base, true);

	// draw keys
	double x_start = position.x + distance_key * 4.5;
	double y_start = position.y + distance_key;
	unsigned int draw_color;
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			if (cursor == k + 10 * i)
			{
				draw_color = color_selected;
			}
			else
			{
				draw_color = color_keys;
			}
			DrawBox(x_start, y_start, x_start + size_key_x, y_start + size_key_y, draw_color, true);
			x_start += size_key_x + distance_key;
		}
		x_start = position.x + distance_key * 4.5;
		y_start += size_key_y + distance_key;
	}
	for (int i = 0; i < 2; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			if (cursor == k + 10 * i)
			{
				draw_color = color_selected;
			}
			else
			{
				draw_color = color_keys_others;
			}
			DrawBox(x_start, y_start, x_start + size_key_x, y_start + size_key_y, color_keys_others, true);
			x_start += size_key_x + distance_key;
		}
		x_start = position.x + distance_key * 4.5;
		y_start += size_key_y + distance_key;
	}

	// draw key string
	x_start = position.x + distance_key * 4.5;
	y_start = position.y + distance_key;
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			std::string key_str = KEYS_LOWER.substr(k + 10 * i, 1);
			DrawStringToHandle(x_start + 32, y_start + 8, key_str.c_str(), color_str, obj::fontInGame);
			x_start += size_key_x + distance_key;
		}
		x_start = position.x + distance_key * 4.5;
		y_start += size_key_y + distance_key;
	}
}
