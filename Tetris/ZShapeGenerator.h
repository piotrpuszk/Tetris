#pragma once
#include "ShapeGenerator.h"
class ZShapeGenerator :
    public ShapeGenerator
{
public:
    ZShapeGenerator(TextureStore& textureStore);
    Block generate(const int middle, const sf::Vector2f size) const override;
};
