#include "Tile.h"

std::atomic_uint32_t Tile::nextId{};

Tile::Tile(unsigned int newId, std::vector<sf::Vector2i> rotationTable, int x, int y, sf::Vector2f newSize, unsigned int newDistanceFromPivot, unsigned int newRotationIndex)
	: id{ ++nextId },
	blockId{ newId },
	rotationTable{ rotationTable },
	position{ x, y },
	image{ sf::RectangleShape{{newSize.x, newSize.y}} },
	size{ newSize },
	distanceFromPivot{ newDistanceFromPivot },
	rotationIndex{ newRotationIndex },
	originalPosition{ x, y }
{
}

bool Tile::moveDown(const int& speed)
{
	position += getMoveDown(speed);
	//std::cout << position.y << std::endl;
	return true;
}

bool Tile::moveLeft(const int& speed)
{
	position += getMoveLeft(speed);
	return true;
}

bool Tile::moveRight(const int& speed)
{
	position += getMoveRight(speed);
	return true;
}

bool Tile::rotate()
{
	position += getRotate();
	rotationIndex = (rotationIndex + 1) % rotationTable.size();
	return true;
}

sf::Vector2i Tile::getMoveDown(const int& speed) const
{
	return WorldDirection::down * speed;
}

sf::Vector2i Tile::getMoveLeft(const int& speed) const
{
	return WorldDirection::left * speed;
}

sf::Vector2i Tile::getMoveRight(const int& speed) const
{
	return WorldDirection::right * speed;
}

sf::Vector2i Tile::getRotate() const
{
	auto translation{ rotationTable[rotationIndex] };
	translation.x *= distanceFromPivot;
	translation.y *= distanceFromPivot;
	return translation;
}

sf::RectangleShape Tile::GetImage() const noexcept
{
	return image;
}

const sf::Vector2i Tile::GetPosition() const noexcept
{
	return position;
}

const unsigned int Tile::GetId() const noexcept
{
	return id;
}

const unsigned int Tile::GetBlockId() const noexcept
{
	return blockId;
}

const unsigned int Tile::getRotationIndex() const noexcept
{
	return rotationIndex;
}

const sf::Vector2i& Tile::getOriginalPosition() const noexcept
{
	return originalPosition;
}
