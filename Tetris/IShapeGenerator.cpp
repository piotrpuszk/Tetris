#include "IShapeGenerator.h"

IShapeGenerator::IShapeGenerator(TextureStore& textureStore)
	:
	ShapeGenerator{ textureStore }
{
}

Block IShapeGenerator::generate(const int middle, const sf::Vector2f size) const
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

	Tile element = { block.getId(), rotationTable, middle, 0, size, 2, 1 };
	element.setImageTexture(textureStore.getBrick01());
	elements.push_back(element);

	element = { block.getId(), rotationTable, middle, 1, size, 1, 1 };
	element.setImageTexture(textureStore.getBrick01());
	elements.push_back(element);

	element = { block.getId(), rotationTable, middle, 2, size, 0, 3 };
	element.setImageTexture(textureStore.getBrick01());
	elements.push_back(element);

	element = { block.getId(), rotationTable, middle, 3, size, 1, 3 };
	element.setImageTexture(textureStore.getBrick01());
	elements.push_back(element);

	block.setElements(elements);
	return block;
}
