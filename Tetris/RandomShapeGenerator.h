#pragma once
#include <vector>
#include <cstdlib>
#include <ctime>
#include "ShapeGenerator.h"
#include "TShapeGenerator.h"
#include "IShapeGenerator.h"
#include "LShapeGenerator.h"
#include "ZShapeGenerator.h"
#include "SquareShapeGenerator.h"
#include "TextureStore.h"

class RandomShapeGenerator
{
public:
	RandomShapeGenerator(const sf::Vector2f size, const unsigned int newMiddle, TextureStore& textureStore);
	Block next();
private:
	std::vector<std::unique_ptr<ShapeGenerator>> shapeGenerators;
	sf::Vector2f size;
	unsigned int middle;
};

