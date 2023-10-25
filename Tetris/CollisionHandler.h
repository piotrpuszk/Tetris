#pragma once
#include "CollisionTable.h"
#include "Block.h"

class CollisionHandler
{
public:
	CollisionHandler(CollisionTable& collisionTable, const WorldProperties& worldProperties);
	bool isColliding(const Tile& element, const sf::Vector2i& move) const;
	void addCollider(const Block& block);
	void removeCollider(const Block& block);
	void clear();
private:
	CollisionTable& collisionTable;
	sf::Vector2i mapSize;
};

