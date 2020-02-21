#include "../header/Keyboard.h"


MyKeyboard::MyKeyboard() : position(100.0, 100.0),
                           color_base(GetColor(40, 40, 40)),
	                       color_keys(GetColor(128, 128, 128)),
	                       size_x(940.0),
	                       size_y(400.0),
	                       size_key_x(80.0),
	                       size_key_y(50.0),
	                       distance_key(8.0)
{}

void MyKeyboard::update()
{
	//
}

void MyKeyboard::draw()
{
	// draw background
	DrawBox(position.x, position.y, position.x + size_x, position.y + size_y, color_base, true);

	// draw keys
	double x_start = position.x + distance_key * 4.5;
	double y_start = position.y + distance_key;
	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			DrawBox(x_start, y_start, x_start + size_key_x, y_start + size_key_y, color_keys, true);
			x_start += size_key_x + distance_key;
		}
		x_start = position.x + distance_key * 4.5;
		y_start += size_key_y + distance_key;
	}
}
