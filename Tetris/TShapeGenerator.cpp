#include "TShapeGenerator.h"

TShapeGenerator::TShapeGenerator(TextureStore& textureStore)
	:
	ShapeGenerator{ textureStore }
{
}

Block TShapeGenerator::generate(const int middle, const sf::Vector2f size) const
{
	const std::vector<sf::Vector2i> rotationTable
	{
		{1, -1},
		{1, 1},
		{-1, 1},
		{-1, -1}
	};
	Block block{};
	std::vector<Tile> elements{};

	Tile element = { block.getId(), rotationTable, middle - 1, 1, size, 1, 0 };
	element.setImageTexture(textureStore.getBrick03());
	elements.push_back(element);

	element = { block.getId(), rotationTable, middle + 0, 1, size, 0, 0 };
	element.setImageTexture(textureStore.getBrick03());
	elements.push_back(element);

	element = { block.getId(), rotationTable, middle + 1, 1, size, 1, 2 };
	element.setImageTexture(textureStore.getBrick03());
	elements.push_back(element);

	element = { block.getId(), rotationTable, middle, 0, size, 1, 1 };
	element.setImageTexture(textureStore.getBrick03());
	elements.push_back(element);

	block.setElements(elements);
	return block;
}
