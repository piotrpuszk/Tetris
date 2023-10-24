#include "RandomShapeGenerator.h"

RandomShapeGenerator::RandomShapeGenerator(const sf::Vector2f newSize, const unsigned int newMiddle)
	: shapeGenerators{}, size{ newSize }, middle{ newMiddle }
{
	shapeGenerators.push_back(std::make_unique<TShapeGenerator>());
	shapeGenerators.push_back(std::make_unique<IShapeGenerator>());
	shapeGenerators.push_back(std::make_unique<LShapeGenerator>());
	shapeGenerators.push_back(std::make_unique<ZShapeGenerator>());
	shapeGenerators.push_back(std::make_unique<SquareShapeGenerator>());
	srand(time(nullptr));
}

Block RandomShapeGenerator::next()
{
	unsigned int index{rand() % shapeGenerators.size()};
	return shapeGenerators[index]->generate(middle, size);
}
