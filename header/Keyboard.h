#pragma once
#include <string>
#include "MyVector2D.h"
#include "setup.h"


class MyKeyboard
{
public:
	MyKeyboard();
	~MyKeyboard() = default;

	std::string get_typed();
	void update();
	void draw();

private:
	const std::string KEYS_LOWER = "1234567890qwertyuiopasdfghjkl\'zxcvbnm,.?";
	const std::string KEYS_UPPER = "1234567890QWERTYUIOPASDFGHJKL\"ZXCVBNM-_/";

	myVector2 position;
	keyboard_draw flag_draw_key;
	std::string typed;
	double size_x;
	double size_y;
	double size_key_x;
	double size_key_y;
	double distance_key;
	unsigned int color_base;
	unsigned int color_keys;
	unsigned int color_keys_others;
	unsigned int color_selected;
	unsigned int color_str;
	unsigned int color_black;
	unsigned int cursor;
};
