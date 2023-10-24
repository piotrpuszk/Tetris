#pragma once
#include "CollisionHandler.h"
#include "UserAction.h"
#include "Block.h"

class BlockMover
{
public:
	BlockMover(CollisionHandler& newCollisionHandler);
	void setUserActions(const std::vector<UserAction>& newUserActions);
	void setBlock(std::shared_ptr<Block> block);
	bool move();
	bool applyGravity();
private:
	bool applyUserActions();
	bool applyUserAction(const UserAction& userAction);
	bool moveDown();
	bool moveRight();
	bool moveLeft();
	bool rotate();
	bool canMove(sf::Vector2i move);
	bool canRotate();
	CollisionHandler collisionHandler;
	std::vector<UserAction> userActions;
	std::shared_ptr<Block> block;
};

