#include "DxLib.h"
#include "../header/Keyboard.h"
#include "../header/setup.h"
#include "../header/Objects.h"


MyKeyboard::MyKeyboard() : position(200.0, 200.0),
                           flag_draw_key(keyboard_draw::lower),
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
	if ((keyInput::pad & ~keyInput::old_pad) & PAD_INPUT_LEFT)
	{
		if (cursor == 59)
		{
			cursor -= 2;
		}
		else if (cursor >= 43 && cursor <= 46)
		{
			cursor = 42;
		}
		else if (cursor % 10 == 0)
		{
			cursor += 9;
		}
		else
		{
			cursor--;
		}
	}
	else if ((keyInput::pad & ~keyInput::old_pad) & PAD_INPUT_RIGHT)
	{
		if (cursor == 58)
		{
			cursor -= 8;
		}
		else if (cursor >= 43 && cursor <= 46)
		{
			cursor = 47;
		}
		else if (cursor % 10 == 9)
		{
			cursor -= 9;
		}
		else
		{
			cursor++;
		}
	}
	else if ((keyInput::pad & ~keyInput::old_pad) & PAD_INPUT_UP)
	{
		if (cursor >= 0 && cursor < 10)
		{
			cursor += 50;
		}
		else
		{
			cursor -= 10;
		}
	}
	else if ((keyInput::pad & ~keyInput::old_pad) & PAD_INPUT_DOWN)
	{
		if (cursor > 49 && cursor < 60)
		{
			cursor -= 50;
		}
		else
		{
			cursor += 10;
		}
	}
	else if ((keyInput::pad & ~keyInput::old_pad) & PAD_INPUT_7)
	{
		switch (flag_draw_key)
		{
		case keyboard_draw::lower:
			flag_draw_key = keyboard_draw::upper;
			break;
		case keyboard_draw::upper:
			flag_draw_key = keyboard_draw::lower;
			break;
		default:
			break;
		}
	}
}

void MyKeyboard::draw()
{
	// draw background
	DrawBox(position.x, position.y, position.x + size_x, position.y + size_y, color_base, true);

	// draw keys
	double x_start = position.x + distance_key * 4.5;
	double x_start_space;
	double x_end_space = size_key_x * 4 + distance_key * 3;
	double x_end_done = size_key_x * 2 + distance_key;
	double y_start = position.y + distance_key;
	unsigned int draw_color;
	for (int i = 0; i < 6; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			if (cursor == k + 10 * i)
			{
				draw_color = color_selected;
			}
			else if (i < 4)
			{
				draw_color = color_keys;
			}
			else
			{
				draw_color = color_keys_others;
			}
			// ここから
			if (k + 10 * i == 43)
			{
				DrawBox(x_start, y_start, x_start + x_end_space, y_start + size_key_y, draw_color, true);
				x_start_space = x_start;
				x_start += (size_key_x + distance_key) * 4;
				continue;
			}
			else if (k + 10 * i > 43 && k + 10 * i < 47)
			{
				if (cursor > 43 && cursor < 47)
				{
					DrawBox(x_start_space, y_start, x_start_space + x_end_space, y_start + size_key_y, color_selected, true);
				}
				continue;
			}
			// ここまでSpaceキー周り
			else if (k + 10 * i == 58)
			{
				DrawBox(x_start, y_start, x_start + x_end_done, y_start + size_key_y, draw_color, true);
				// x_start += size_key_x + distance_key;
				continue;
			}
			else if (k + 10 * i == 59)
			{
				if (cursor == 59)
				{
					DrawBox(x_start, y_start, x_start + x_end_done, y_start + size_key_y, draw_color, true);
				}
				continue;
			}
			DrawBox(x_start, y_start, x_start + size_key_x, y_start + size_key_y, draw_color, true);
			x_start += size_key_x + distance_key;
		}
		x_start = position.x + distance_key * 4.5;
		y_start += size_key_y + distance_key;
	}

	// draw key string
	x_start = position.x + distance_key * 4.5;
	y_start = position.y + distance_key;

	std::string key_str;
	switch (flag_draw_key)
	{
	case keyboard_draw::lower:
		key_str = KEYS_LOWER;
		break;
	case keyboard_draw::upper:
		key_str = KEYS_UPPER;
		break;
	default:
		break;
	}
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			std::string key_char = key_str.substr(k + 10 * i, 1);
			DrawStringToHandle(x_start + 32, y_start + 8, key_char.c_str(), color_str, obj::fontInGame);
			x_start += size_key_x + distance_key;
		}
		x_start = position.x + distance_key * 4.5;
		y_start += size_key_y + distance_key;
	}
	for (int i = 0; i < 2; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			switch (k + 10 * i)
			{
			case 0:
				DrawStringToHandle(x_start, y_start, "L2", color_str, obj::fontKeySmall);
				break;
			case 12:
				DrawStringToHandle(x_start, y_start, "L1", color_str, obj::fontKeySmall);
				break;
			case 13:
				DrawStringToHandle(x_start, y_start, "R1", color_str, obj::fontKeySmall);
				break;
			case 18:
				DrawStringToHandle(x_start, y_start, "R2", color_str, obj::fontKeySmall);
				break;
			default:
				break;
			}
			x_start += size_key_x + distance_key;
		}
		x_start = position.x + distance_key * 4.5;
		y_start += size_key_y + distance_key;
	}
}
