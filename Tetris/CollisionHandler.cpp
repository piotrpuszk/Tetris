#include "CollisionHandler.h"

CollisionHandler::CollisionHandler(std::shared_ptr<CollisionTable> newCollisionTable, sf::Vector2i newMapSize)
	: collisionTable{ newCollisionTable },
	mapSize{ newMapSize }
{
}

bool CollisionHandler::isColliding(const Tile& element, const sf::Vector2i& move) const
{
	const auto position{ element.GetPosition()};
	sf::Vector2i newPosition{ position.x + move.x, position.y + move.y};
	return newPosition.x > mapSize.x - 1 
		|| newPosition.y > mapSize.y - 1 
		|| newPosition.x < 0 
		|| newPosition.y < 0 
		|| collisionTable->isBlocked(element.GetBlockId(), newPosition);
}

void CollisionHandler::addCollider(const Block& block)
{
	std::for_each(block.getElements().begin(), block.getElements().end(), [this](const Tile& e) {collisionTable->addCollider(e); });
}

void CollisionHandler::removeCollider(const Block& block)
{
	std::for_each(block.getElements().begin(), block.getElements().end(), [this](const Tile& e) {collisionTable->removeCollider(e); });
}
