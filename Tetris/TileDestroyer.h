#pragma once
#include <vector>
#include <algorithm>
#include "CollisionTable.h"
#include "Block.h"
#include <iostream>

class TileDestroyer
{
public:
	TileDestroyer(std::shared_ptr<CollisionTable> collisionTable, std::shared_ptr<std::vector<std::shared_ptr<Block>>> blocks);
	unsigned int destroyAll();
	unsigned int destroy();
private:
	std::shared_ptr<CollisionTable> collisionTable;
	std::shared_ptr<std::vector<std::shared_ptr<Block>>> blocks;
};

