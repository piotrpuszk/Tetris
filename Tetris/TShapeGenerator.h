#pragma once
#include "ShapeGenerator.h"
#include "WorldProperties.h"

class TShapeGenerator :
    public ShapeGenerator
{
public:
    Block generate(const int middle, const sf::Vector2f size) const override;
};

