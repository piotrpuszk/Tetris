#pragma once
#include <vector>
#include "Block.h"
#include "TextureStore.h"

class ShapeGenerator
{
public:
	ShapeGenerator(TextureStore& textureStore);
	virtual Block generate(const int middle, const sf::Vector2f size) const = 0;
	virtual ~ShapeGenerator() = default;
protected:
	TextureStore& textureStore;
};

