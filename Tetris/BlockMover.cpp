#include "BlockMover.h"

BlockMover::BlockMover(CollisionHandler& newCollisionHandler)
	: collisionHandler{ newCollisionHandler }
{
}

void BlockMover::setUserActions(const std::vector<UserAction>& newUserActions)
{
	userActions.clear();
	for (auto& action : newUserActions) userActions.push_back(action);
}

void BlockMover::setBlock(std::shared_ptr<Block> block)
{
	this->block = block;
}

bool BlockMover::move()
{

	auto gravityMove = applyGravity();
	auto userMove = applyUserActions();
	return gravityMove || userMove;
}

bool BlockMover::applyGravity()
{
	return moveDown();
}

bool BlockMover::applyUserActions()
{
	bool anyMove{};
	for (auto userAction : userActions)
	{
		anyMove = applyUserAction(userAction) || anyMove;
	}
	return anyMove;
}

bool BlockMover::applyUserAction(const UserAction& userAction)
{
	switch (userAction)
	{	
		case UserAction::Up:
			return rotate();
			break;
		case UserAction::Down:
			return moveDown();
		case UserAction::Right:
			return moveRight();
		case UserAction::Left:
			return moveLeft();
	}
}

bool BlockMover::moveDown()
{
	if (canMove(WorldDirection::down))
	{
		collisionHandler.removeCollider(*block);
		block->moveDown();
		collisionHandler.addCollider(*block);
		return true;
	}
	return false;
}

bool BlockMover::moveRight()
{
	if (canMove(WorldDirection::right))
	{
		collisionHandler.removeCollider(*block);
		block->moveRight();
		collisionHandler.addCollider(*block);
		return true;
	}
	return false;
}

bool BlockMover::moveLeft()
{
	if (canMove(WorldDirection::left))
	{
		collisionHandler.removeCollider(*block);
		block->moveLeft();
		collisionHandler.addCollider(*block);
		return true;
	}
	return false;
}

bool BlockMover::rotate()
{
	if (canRotate())
	{
		collisionHandler.removeCollider(*block);
		block->rotate();
		collisionHandler.addCollider(*block);
		return true;
	}
	return false;
}

bool BlockMover::canMove(sf::Vector2i move)
{
	for (auto& e : block->getElements())
	{
		if (collisionHandler.isColliding(e, move))
		{
			return false;
		}
	}
	return true;
}

bool BlockMover::canRotate()
{
	for (auto& e : block->getElements())
	{
		auto move{e.getRotate()};
		if (collisionHandler.isColliding(e, move))
		{
			return false;
		}
	}
	return true;
}
