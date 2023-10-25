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
	unsigned int destroyAll();
	unsigned int destroy();
private:
	CollisionTable& collisionTable;
	std::vector<Block>& blocks;
};

