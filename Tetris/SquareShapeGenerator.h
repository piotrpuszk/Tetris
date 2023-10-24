#pragma once
#include "ShapeGenerator.h"
class SquareShapeGenerator :
    public ShapeGenerator
{
public:
    Block generate(const int middle, const sf::Vector2f size) const override;
};


