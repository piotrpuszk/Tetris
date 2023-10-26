#include "LShapeGenerator.h"

LShapeGenerator::LShapeGenerator(TextureStore& textureStore)
	:
	ShapeGenerator{ textureStore }
{
}

Block LShapeGenerator::generate(const int middle, const sf::Vector2f size) const
{
	std::vector<sf::Vector2i> rotationTable
	{
		{1, -1},
		{1, 1},
		{-1, 1},
		{-1, -1}
	};
	Block block{};
	std::vector<Tile> elements{};

	Tile element = { block.getId(), rotationTable, middle + 0, 0, size, 2, 1 };
	element.setImageTexture(textureStore.getBrick02());
	elements.push_back(element);

	element = { block.getId(), rotationTable, middle + 0, 1, size, 1, 1 };
	element.setImageTexture(textureStore.getBrick02());
	elements.push_back(element);

	element = { block.getId(), rotationTable, middle + 0, 2, size, 0, 0 };
	element.setImageTexture(textureStore.getBrick02());
	elements.push_back(element);

	element = { block.getId(), rotationTable, middle + 1, 2, size, 1, 2 };
	element.setImageTexture(textureStore.getBrick02());
	elements.push_back(element);

	block.setElements(elements);
	return block;
}