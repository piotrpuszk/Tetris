#pragma once
#include <vector>
#include "Block.h"

class ShapeGenerator
{
public:
	virtual Block generate(const int middle, const sf::Vector2f size) const = 0;
	virtual ~ShapeGenerator() = default;
};

