#include "TileDestroyer.h"

TileDestroyer::TileDestroyer(CollisionTable& collisionTable, std::vector<Block>& blocks)
	: collisionTable{ collisionTable },
	blocks{ blocks }
{
}

std::vector<int> TileDestroyer::destroyAll()
{
	std::vector<int> destroyedRows{};
	int destroyedRow{-1};
	while (true)
	{
		destroyedRow = destroy();
		if (destroyedRow < 0) break;
		destroyedRows.push_back(destroyedRow);
	}
	return destroyedRows;
}

int TileDestroyer::destroy()
{
	int rowToDestroy{ -1 };
	const auto size{ collisionTable.getSize() };
	sf::Vector2i position{};
	bool toDestroy{};
	for (int row = 0; row < size.y; row++)
	{
		toDestroy = true;
		position.y = row;
		for (int column = 0; column < size.x; column++)
		{
			position.x = column;
			if (!collisionTable.isBlocked(position))
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
		return rowToDestroy;
	}

	for (int column = 0; column < size.x; column++)
	{
		sf::Vector2i position{ column, rowToDestroy };

		for (auto& b : blocks)
		{
			b.deleteElement(position);
		}

		collisionTable.removeCollider(position);
	}

	return rowToDestroy;
}
