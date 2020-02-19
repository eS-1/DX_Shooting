#include "../header/Keyboard.h"


MyKeyboard::MyKeyboard() : position(0.0, 0.0),
                           color(GetColor(128, 128, 128)),
	                       size_x(700.0),
	                       size_y(500.0)
{}

void MyKeyboard::update()
{
	//
}

void MyKeyboard::draw()
{
	DrawBox(position.x, position.y, position.x + size_x, position.y + size_y, color, true);
}
