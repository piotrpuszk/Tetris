#include "IShapeGenerator.h"

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
	elements.push_back({ block.getId(), rotationTable, middle, 0, size, 2, 1 });
	elements.push_back({ block.getId(), rotationTable, middle, 1, size, 1, 1 });
	elements.push_back({ block.getId(), rotationTable, middle, 2, size, 0, 3 });
	elements.push_back({ block.getId(), rotationTable, middle, 3, size, 1, 3 });
	block.setElements(elements);
	return block;
}
