#pragma once
#include <vector>
#include <algorithm>
#include "CollisionTable.h"
#include "Block.h"
#include <iostream>

class TileDestroyer
{
public:
	TileDestroyer(CollisionTable& collisionTable, std::vector<Block>& blocks);
	std::vector<int> destroyAll();
	int destroy();
private:
	CollisionTable& collisionTable;
	std::vector<Block>& blocks;
};

