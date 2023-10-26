#include "RandomShapeGenerator.h"

RandomShapeGenerator::RandomShapeGenerator(const sf::Vector2f newSize, const unsigned int newMiddle, TextureStore& textureStore)
	: shapeGenerators{}, size{ newSize }, middle{ newMiddle }
{
	shapeGenerators.push_back(std::make_unique<TShapeGenerator>(textureStore));
	shapeGenerators.push_back(std::make_unique<IShapeGenerator>(textureStore));
	shapeGenerators.push_back(std::make_unique<LShapeGenerator>(textureStore));
	shapeGenerators.push_back(std::make_unique<ZShapeGenerator>(textureStore));
	shapeGenerators.push_back(std::make_unique<SquareShapeGenerator>(textureStore));
	srand(time(nullptr));
}

Block RandomShapeGenerator::next()
{
	unsigned int index{rand() % shapeGenerators.size()};
	return shapeGenerators[index]->generate(middle, size);
}
