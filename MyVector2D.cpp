#include <cmath>
#include "MyVector2D.h"

myVector2::myVector2() = default;

constexpr myVector2::myVector2(double mx, double my)
	: x(mx), y(my) {}

constexpr myVector2 myVector2::operator +() const
{
	return *this;
}

constexpr myVector2 myVector2::operator -() const
{
	return { -x, -y };
}
constexpr myVector2 myVector2::operator +(const myVector2& other) const
{
	return { x + other.x, y + other.y };
}

constexpr myVector2 myVector2::operator -(const myVector2& other) const
{
	return { x - other.x, y - other.y };
}

constexpr myVector2 myVector2::operator *(double s) const
{
	return { x * s, y * s };
}

constexpr myVector2 myVector2::operator /(double s) const
{
	return { x / s, y / s };
}

myVector2& myVector2::operator +=(const myVector2& other)
{
	x += other.x;
	y += other.y;
	return *this;
}

myVector2& myVector2::operator -=(const myVector2& other)
{
	x -= other.x;
	y -= other.y;
	return *this;
}

myVector2& myVector2::operator *=(double s)
{
	x *= s;
	y *= s;
	return *this;
}

myVector2& myVector2::operator /=(double s)
{
	x /= s;
	y /= s;
	return *this;
}

double myVector2::length() const
{
	return std::sqrt(lengthSquare());
}

constexpr double myVector2::lengthSquare() const
{
	return dot(*this);
}

constexpr double myVector2::dot(const myVector2& other) const
{
	return x * other.x + y * other.y;
}

double myVector2::distanceFrom(const myVector2& other) const
{
	return (other - *this).length();
}

myVector2 myVector2::normalized() const
{
	return *this / length();
}

constexpr bool myVector2::isZero() const
{
	return x == 0.0 && y == 0.0;
}

myVector2 operator *(double s, const myVector2& v)
{
	return { s * v.x, s * v.y };
}