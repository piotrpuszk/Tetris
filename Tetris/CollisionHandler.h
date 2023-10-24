#pragma once
#include "CollisionTable.h"
#include "Block.h"

class CollisionHandler
{
public:
	CollisionHandler(std::shared_ptr<CollisionTable> newCollisionTable, sf::Vector2i newMapSize);
	bool isColliding(const Tile& element, const sf::Vector2i& move) const;
	void addCollider(const Block& block);
	void removeCollider(const Block& block);
private:
	std::shared_ptr<CollisionTable> collisionTable;
	sf::Vector2i mapSize;
};

