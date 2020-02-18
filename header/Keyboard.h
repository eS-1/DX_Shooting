#pragma once
#include <array>
#include <string>


class MyKeyboard
{
public:
	MyKeyboard();
	~MyKeyboard() = default;

private:
	std::array<std::string, 60> keys;
};
