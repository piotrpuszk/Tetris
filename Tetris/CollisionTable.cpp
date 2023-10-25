#include "CollisionTable.h"

CollisionTable::CollisionTable(const WorldProperties& worldPropeties)
	: collisionTable{},
	size{worldPropeties.GetMapSize()}
{
	for (size_t height = 0; height < worldPropeties.GetMapSize().y; height++)
	{
		collisionTable.push_back(std::vector<unsigned int>(worldPropeties.GetMapSize().x, 0));
	}
}

bool CollisionTable::isBlocked(unsigned int id, const sf::Vector2i& position) const
{
	auto value{ collisionTable[position.y][position.x] };
	return value > 0 && value != id;
}

bool CollisionTable::isBlocked(const sf::Vector2i& position) const
{
	return collisionTable[position.y][position.x] > 0;
}

void CollisionTable::addCollider(const Tile& element)
{
	const auto position{ element.GetPosition() };
	collisionTable[position.y][position.x] = element.GetBlockId();
}

void CollisionTable::removeCollider(const Tile& element)
{
	const auto position{ element.GetPosition() };
	collisionTable[position.y][position.x] = 0;
}

void CollisionTable::removeCollider(const sf::Vector2i& position)
{
	collisionTable[position.y][position.x] = 0;
}

const sf::Vector2i CollisionTable::getSize() const noexcept
{
	return size;
}
