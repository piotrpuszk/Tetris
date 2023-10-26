#include "ZShapeGenerator.h"

ZShapeGenerator::ZShapeGenerator(TextureStore& textureStore)
	:
	ShapeGenerator{ textureStore }
{
}

Block ZShapeGenerator::generate(const int middle, const sf::Vector2f size) const
{
	std::vector<sf::Vector2i> rotationTable
	{
		{1, -1},
		{1, 1},
		{-1, 1},
		{-1, -1}
	};
	std::vector<sf::Vector2i> rotationTable2
	{
		{1, 0},
		{0, 1},
		{-1, 0},
		{0, -1}
	};
	Block block{};
	std::vector<Tile> elements{};

	Tile element = { block.getId(), rotationTable2, middle - 1, 0, size, 2, 0 };
	element.setImageTexture(textureStore.getBrick04());
	elements.push_back(element);

	element = { block.getId(), rotationTable, middle - 1, 1, size, 1, 0 };
	element.setImageTexture(textureStore.getBrick04());
	elements.push_back(element);

	element = { block.getId(), rotationTable, middle + 0, 1, size, 0, 0 };
	element.setImageTexture(textureStore.getBrick04());
	elements.push_back(element);

	element = { block.getId(), rotationTable, middle + 0, 2, size, 1, 3 };
	element.setImageTexture(textureStore.getBrick04());
	elements.push_back(element);
	block.setElements(elements);
	return block;
}