#pragma once
#include <atomic>
#include <SFML/Graphics.hpp>
#include "WorldDirection.h"

class Tile
{
public:
	Tile(unsigned int newId, std::vector<sf::Vector2i> rotationTable, int x, int y, sf::Vector2f newSize, unsigned int newDistanceFromPivot, unsigned int newRotationIndex);
	bool moveDown(const int& speed = 1);
	bool moveLeft(const int& speed = 1);
	bool moveRight(const int& speed = 1);
	bool rotate();
	sf::Vector2i getMoveDown(const int& speed = 1) const;
	sf::Vector2i getMoveLeft(const int& speed = 1) const;
	sf::Vector2i getMoveRight(const int& speed = 1) const;
	sf::Vector2i getRotate() const;
	const sf::RectangleShape GetImage() const noexcept;
	const sf::Vector2i GetPosition() const noexcept;
	const unsigned int GetId() const noexcept;
	const unsigned int GetBlockId() const noexcept;
	const unsigned int getRotationIndex() const noexcept;
private:
	unsigned int id;
	unsigned int blockId;
	sf::Vector2i position;
	sf::RectangleShape image;
	sf::Vector2f size;
	unsigned int distanceFromPivot;
	unsigned int rotationIndex;
	std::vector<sf::Vector2i> rotationTable;
	static std::atomic_uint32_t nextId;
};
