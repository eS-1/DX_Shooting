#include "DxLib.h"
#include <time.h>
#include "../header/Keyboard.h"
#include "../header/setup.h"
#include "../header/Objects.h"


void Keyboard_Init()
{
	obj::myKeyboard.reset(new MyKeyboard());
}

MyKeyboard::MyKeyboard() : start_time(0),
                           remaining_time(0),
	                       pos(400.0, 400.0),
                           flag_draw_key(keyboard_draw::lower),
	                       typed(""),
	                       flag_enter(false),
	                       flag_caps_count(false),
	                       flag_caps_lock(false),
                           color_base(GetColor(30, 30, 30)),
	                       color_keys(GetColor(60, 60, 60)),
	                       color_keys_others(GetColor(80, 80, 80)),
	                       color_selected(GetColor(150, 150, 150)),
	                       color_str(GetColor(255, 255, 255)),
	                       color_black(GetColor(0, 0, 0)),
	                       size_x(940.0),
	                       size_y(370.0),
	                       size_key_x(80.0),
	                       size_key_y(50.0),
	                       distance_key(8.0),
	                       ptr(0),
	                       cursor(0)
{}

std::string MyKeyboard::get_typed()
{
	return typed;
}

bool MyKeyboard::get_flag_enter()
{
	return flag_enter;
}

void MyKeyboard::switch_shift()
{
	start_time = GetTickCount();
	flag_caps_count = !flag_caps_count;
	switch (flag_draw_key)
	{
	case keyboard_draw::lower:
		flag_draw_key = keyboard_draw::upper;
		break;
	case keyboard_draw::upper:
		if (flag_caps_count)
		{
			flag_caps_lock = false;
			flag_caps_count = false;
			flag_draw_key = keyboard_draw::lower;
		}
		else
		{
			flag_caps_lock = true;
		}
		break;
	default:
		break;
	}
}

void MyKeyboard::update()
{
	char key = GetInputChar(1);
	flag_enter = false;
	if (flag_caps_count)
	{
		remaining_time = GetTickCount() - start_time;
		if ((double)remaining_time / 1000 > 0.5)
		{
			flag_caps_count = false;
		}
	}
	pos.x += Input::analog_RX / 100;
	pos.y += Input::analog_RY / 100;
	if ((Input::pad & ~Input::old_pad) & PAD_INPUT_LEFT)
	{
		if (ptr == 49 || ptr == 59)
		{
			ptr -= 2;
		}
		else if (ptr >= 43 && ptr <= 46)
		{
			ptr = 42;
		}
		else if (ptr % 10 == 0)
		{
			ptr += 9;
		}
		else
		{
			ptr--;
		}
	}
	else if ((Input::pad & ~Input::old_pad) & PAD_INPUT_RIGHT)
	{
		if (ptr == 48 || ptr == 58)
		{
			ptr -= 8;
		}
		else if (ptr >= 43 && ptr <= 46)
		{
			ptr = 47;
		}
		else if (ptr % 10 == 9)
		{
			ptr -= 9;
		}
		else
		{
			ptr++;
		}
	}
	else if ((Input::pad & ~Input::old_pad) & PAD_INPUT_UP)
	{
		if (ptr >= 0 && ptr < 10)
		{
			ptr += 50;
		}
		else
		{
			ptr -= 10;
		}
	}
	else if ((Input::pad & ~Input::old_pad) & PAD_INPUT_DOWN)
	{
		if (ptr > 49 && ptr < 60)
		{
			ptr -= 50;
		}
		else
		{
			ptr += 10;
		}
	}
	// ○ボタン
	else if ((Input::pad & ~Input::old_pad) & PAD_INPUT_3)
	{
		if (ptr >= 0 && ptr < 40)
		{
			switch (flag_draw_key)
			{
			case keyboard_draw::lower:
				typed.insert(typed.begin() + cursor, KEYS_LOWER.at(ptr));
				break;
			case keyboard_draw::upper:
				typed.insert(typed.begin() + cursor, KEYS_UPPER.at(ptr));
				if (!flag_caps_lock)
				{
					flag_draw_key = keyboard_draw::lower;
				}
				break;
			default:
				break;
			}
			cursor++;
		}
		else if (ptr == 40)
		{
			switch_shift();
		}
		else if (ptr > 42 && ptr < 47)
		{
			typed += " ";
			cursor++;
		}
		else if (ptr == 52 && cursor > 0)
		{
			cursor--;
		}
		else if (ptr == 53 && cursor < typed.size())
		{
			cursor++;
		}
		else if (ptr == 58 || ptr == 59)
		{
			flag_enter = true;
		}
	}
	// □ボタン
	else if ((Input::pad & ~Input::old_pad) & PAD_INPUT_1)
	{
		if (!typed.empty() && cursor > 0)
		{
			typed.erase(typed.begin() + cursor - 1);
			cursor--;
		}
	}
	// L1
	else if ((Input::pad & ~Input::old_pad) & PAD_INPUT_5)
	{
	    if (cursor > 0)
	    {
		    cursor--;
		}
    }
	// R1
	else if ((Input::pad & ~Input::old_pad) & PAD_INPUT_6)
	{
	    if (cursor < typed.size())
	    {
			cursor++;
		}
    }
	// L2
	else if ((Input::pad & ~Input::old_pad) & PAD_INPUT_7)
	{
		switch_shift();
	}
	// R2
	else if ((Input::pad & ~Input::old_pad) & PAD_INPUT_8)
    {
	    flag_enter = true;
	}
	else if (key != 0)
	{
	    if (key == CTRL_CODE_BS && !typed.empty())
		{
			typed.erase(typed.begin() + cursor - 1);
			cursor--;
		}
		else if (key >= CTRL_CODE_CMP)
		{
			typed.insert(typed.begin() + cursor, key);
			cursor++;
		}
    }
}

void MyKeyboard::draw()
{
	// draw background
	DrawBox(pos.x, pos.y, pos.x + size_x, pos.y + size_y, color_base, true);

	// draw keys
	double x_start = pos.x + distance_key * 4.5;
	double x_start_space;
	double x_end_space = size_key_x * 4 + distance_key * 3;
	double x_end_done = size_key_x * 2 + distance_key;
	double y_start = pos.y + distance_key;
	unsigned int draw_color;
	for (int i = 0; i < 6; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			if (ptr == k + 10 * i)
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
			// Spaceここから
			if (k + 10 * i == 43)
			{
				DrawBox(x_start, y_start, x_start + x_end_space, y_start + size_key_y, draw_color, true);
				x_start_space = x_start;
				x_start += (size_key_x + distance_key) * 4;
				continue;
			}
			else if (k + 10 * i > 43 && k + 10 * i < 47)
			{
				if (ptr > 43 && ptr < 47)
				{
					DrawBox(x_start_space, y_start, x_start_space + x_end_space, y_start + size_key_y, color_selected, true);
				}
				continue;
			}
			// Spaceここまで
			// Deleteここから
			else if (k + 10 * i == 48)
			{
				DrawBox(x_start, y_start, x_start + x_end_done, y_start + size_key_y, draw_color, true);
				continue;
			}
			else if (k + 10 * i == 49)
			{
				if (ptr == 49)
				{
					DrawBox(x_start, y_start, x_start + x_end_done, y_start + size_key_y, draw_color, true);
				}
				continue;
			}
			// Deleteここまで
			// Enterここから
			else if (k + 10 * i == 58)
			{
				DrawBox(x_start, y_start, x_start + x_end_done, y_start + size_key_y, draw_color, true);
				continue;
			}
			else if (k + 10 * i == 59)
			{
				if (ptr == 59)
				{
					DrawBox(x_start, y_start, x_start + x_end_done, y_start + size_key_y, draw_color, true);
				}
				continue;
			}
			// Enterここまで
			DrawBox(x_start, y_start, x_start + size_key_x, y_start + size_key_y, draw_color, true);
			if (k + 10 * i == 40 && flag_caps_lock)
			{
				DrawBox(x_start, y_start, x_start + size_key_x, y_start + size_key_y, color_str, false);
			}
			x_start += size_key_x + distance_key;
		}
		x_start = pos.x + distance_key * 4.5;
		y_start += size_key_y + distance_key;
	}

	// draw key string
	x_start = pos.x + distance_key * 4.5;
	y_start = pos.y + distance_key;

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
		x_start = pos.x + distance_key * 4.5;
		y_start += size_key_y + distance_key;
	}
	for (int i = 0; i < 2; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			double x_tri = x_start + 33.0;
			double y_tri = y_start + 27.0;
			switch (k + 10 * i)
			{
			case 0:
				DrawBox(x_start, y_start, x_start + 30, y_start + 25, color_black, true);
				DrawStringToHandle(x_start + 5, y_start + 3, "L2", color_str, obj::fontKeySmall);
				break;
			case 3:
				DrawBox(x_start, y_start, x_start + 30, y_start + 25, color_black, true);
				DrawStringToHandle(x_start + x_end_space / 2 - 40, y_start + 10, "Space", color_str, obj::fontInGame);
				break;
			case 8:
				DrawBox(x_start, y_start, x_start + 30, y_start + 25, color_black, true);
				break;
			case 12:
				DrawBox(x_start, y_start, x_start + 30, y_start + 25, color_black, true);
				DrawStringToHandle(x_start + 5, y_start + 3, "L1", color_str, obj::fontKeySmall);
				DrawTriangle(x_tri, y_tri, x_tri + 14 * sqrt(3.0), y_tri - 14, x_tri + 14 * sqrt(3.0), y_tri + 14, color_str, 1);
				break;
			case 13:
				x_tri += 30.0;
				DrawBox(x_start, y_start, x_start + 30, y_start + 25, color_black, true);
				DrawStringToHandle(x_start + 5, y_start + 3, "R1", color_str, obj::fontKeySmall);
				DrawTriangle(x_tri, y_tri, x_tri - 14 * sqrt(3.0), y_tri - 14, x_tri - 14 * sqrt(3.0), y_tri + 14, color_str, 1);
				break;
			case 18:
				DrawBox(x_start, y_start, x_start + 30, y_start + 25, color_black, true);
				DrawStringToHandle(x_start + 5, y_start + 3, "R2", color_str, obj::fontKeySmall);
				DrawStringToHandle(x_start + 55, y_start + 10, "Done", color_str, obj::fontInGame);
				break;
			default:
				break;
			}
			x_start += size_key_x + distance_key;
		}
		x_start = pos.x + distance_key * 4.5;
		y_start += size_key_y + distance_key;
	}

	// draw typed string
	DrawStringToHandle(pos.x + 50, pos.y - 40, typed.c_str(), color_str, obj::fontInGame);

	// draw cursor
	DrawLine(pos.x + 50 + cursor * 15, pos.y - 40, pos.x + 50 + cursor * 15, pos.y - 10, color_str);

	// DrawFormatString(150, 180, color_str, "%lf", (double)remaining_time / 1000);
}
