#pragma once
#include <vector>
#include "Tile.h"

class Block
{
public:
	Block();
	Block(std::vector<Tile> newElements);
	void setElements(std::vector<Tile> newElements);
	unsigned int deleteElement(const sf::Vector2i position);
	void moveDown();
	void moveRight();
	void moveLeft();
	void rotate();
	void print() const;
	const std::vector<Tile>& getElements() const;
	const unsigned int getId() const noexcept;
private:
	std::vector<Tile> elements;
	unsigned int id;

	static std::atomic_uint32_t nextId;
};

