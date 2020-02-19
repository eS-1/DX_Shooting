#pragma once
#include <string>
#include "DxLib.h"
#include "MyVector2D.h"


class MyKeyboard
{
public:
	MyKeyboard();
	~MyKeyboard() = default;

	void update();
	void draw();

private:
	const std::string KEYS_LOWER = "1234567890qwertyuiopasdfghjkl'zxcvbnm,.";
	const std::string KEYS_UPPER = "1234567890QWERTYUIOPASDFGHJKL'ZXCVBNM,.";

	myVector2 position;
	double size_x;
	double size_y;
	unsigned int color;
};
