#pragma once
class Collider
{
public:
	Collider(unsigned int newX, unsigned int newY);
	bool operator<(const Collider& right) const;
	bool operator>(const Collider& right) const;
	bool operator==(const Collider& right) const;
	bool operator!=(const Collider& right) const;
private:
	unsigned int x;
	unsigned int y;
};

