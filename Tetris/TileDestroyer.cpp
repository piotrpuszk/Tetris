#include "TileDestroyer.h"

TileDestroyer::TileDestroyer(std::shared_ptr<CollisionTable> collisionTable, std::shared_ptr<std::vector<std::shared_ptr<Block>>> blocks)
	: collisionTable{ collisionTable },
	blocks{ blocks }
{
}

unsigned int TileDestroyer::destroyAll()
{
	unsigned int destroyedRowsCount{};
	for(; destroy() > 0;) ++destroyedRowsCount;
	return destroyedRowsCount;
}

unsigned int TileDestroyer::destroy()
{
	int rowToDestroy{ -1 };
	const auto size{ collisionTable->getSize() };
	sf::Vector2i position{};
	bool toDestroy{};
	for (size_t row = 0; row < size.y; row++)
	{
		toDestroy = true;
		position.y = row;
		for (size_t column = 0; column < size.x; column++)
		{
			position.x = column;
			if (!collisionTable->isBlocked(position))
			{
				toDestroy = false;
				break;
			}
		}
		if (toDestroy)
		{
			rowToDestroy = row;
			break;
		}
	}

	if (rowToDestroy < 0)
	{
		return 0;
	}

	for (int column = 0; column < size.x; column++)
	{
		sf::Vector2i position{ column, rowToDestroy };

		for (auto& b : *blocks)
		{
			b->deleteElement(position);
		}

		collisionTable->removeCollider(position);
	}

	return 1;
}
