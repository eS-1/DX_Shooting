#include "DxLib.h"
#include "Bullet.h"

Bullet::Bullet() = default;

Bullet::Bullet(double bx, double by)
	: pos(myVector2(bx, by)), moveDirection(myVector2(0.0, -5.0)) {}

Bullet::Bullet(const myVector2 &p)
	: pos(p), moveDirection(myVector2(0.0, -5.0)) {}

Bullet::~Bullet()
{
	// デストラクタ
}

myVector2 Bullet::getPos() const
{
	return pos;
}

void Bullet::move()
{
	pos += moveDirection;
}

void Bullet::draw()
{
	DrawBox(pos.x - 5.0, pos.y - 5.0, pos.x + 5.0, pos.y + 5.0, GetColor(255, 0, 0), 1);
}
