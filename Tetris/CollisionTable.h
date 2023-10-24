#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Tile.h"

class CollisionTable
{
public:
	CollisionTable(const sf::Vector2i& mapSize);
	bool isBlocked(unsigned int id, const sf::Vector2i& position) const;
	bool isBlocked(const sf::Vector2i& position) const;
	void addCollider(const Tile& element);
	void removeCollider(const Tile& element);
	void removeCollider(const sf::Vector2i& position);
	const sf::Vector2i getSize() const noexcept;
private:
	std::vector<std::vector<unsigned int>> collisionTable;
	sf::Vector2i size;
};

