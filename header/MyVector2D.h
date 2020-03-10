#pragma once


struct  myVector2
{
	double x;
	double y;

	constexpr myVector2(double mx, double my);

	constexpr myVector2 operator +() const;
	constexpr myVector2 operator -() const;
	constexpr myVector2 operator +(const myVector2& other) const;
	constexpr myVector2 operator -(const myVector2& other) const;
	constexpr myVector2 operator *(double s) const;
	constexpr myVector2 operator /(double s) const;
	myVector2& operator +=(const myVector2& other);
	myVector2& operator -=(const myVector2& other);
	myVector2& operator *=(double s);
	myVector2& operator /=(double s);

	double length() const;
	double lengthSquare() const;
	double dot(const myVector2& other) const;
	double distanceFrom(const myVector2& other) const;
	void normalize();
	void normalize(const double val);
	constexpr bool isZero() const;
};

myVector2 operator *(double s, const myVector2& v);