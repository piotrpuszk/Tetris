#include "Collider.h"

Collider::Collider(unsigned int newX, unsigned int newY)
	: x{ newX }, y{newY}
{
}

bool Collider::operator<(const Collider& right) const
{
	return x < right.x and y < right.y;
}

bool Collider::operator>(const Collider& right) const
{
	return x > right.x and y > right.y;
}

bool Collider::operator==(const Collider& right) const
{
	return x == right.x and y == right.y;
}

bool Collider::operator!=(const Collider& right) const
{
	return !(*this == right);
}
