#pragma once
#include "CollisionHandler.h"
#include "UserAction.h"
#include "Block.h"

class BlockMover
{
public:
	BlockMover(CollisionHandler& newCollisionHandler);
	void setUserActions(const std::vector<UserAction>& newUserActions);
	bool move(Block& block);
	bool applyGravity(Block& block);
private:
	bool applyUserActions(Block& block);
	bool applyUserAction(const UserAction& userAction, Block& block);
	bool moveDown(Block& block);
	bool moveRight(Block& block);
	bool moveLeft(Block& block);
	bool rotate(Block& block);
	bool canMove(Block& block, sf::Vector2i move);
	bool canRotate(Block& block);
	CollisionHandler collisionHandler;
	std::vector<UserAction> userActions;
};

