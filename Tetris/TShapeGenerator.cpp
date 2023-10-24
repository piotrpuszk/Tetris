#include "TShapeGenerator.h"

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
	elements.push_back({ block.getId(), rotationTable, middle - 1, 1, size, 1, 0 });
	elements.push_back({ block.getId(), rotationTable, middle + 0, 1, size, 0, 0 });
	elements.push_back({ block.getId(), rotationTable, middle + 1, 1, size, 1, 2 });
	elements.push_back({ block.getId(), rotationTable, middle, 0, size, 1, 1 });
	block.setElements(elements);
	return block;
}
