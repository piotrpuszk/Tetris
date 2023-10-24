#pragma once
#include "ShapeGenerator.h"

class LShapeGenerator :
    public ShapeGenerator
{
public:
    Block generate(const int middle, const sf::Vector2f size) const override;
};

