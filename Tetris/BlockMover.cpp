#include "BlockMover.h"

BlockMover::BlockMover(CollisionHandler& newCollisionHandler)
	: 
	collisionHandler{ newCollisionHandler }
{
}

void BlockMover::setUserActions(const std::vector<UserAction>& newUserActions)
{
	userActions.clear();
	for (auto& action : newUserActions) userActions.push_back(action);
}

void BlockMover::moveAfterDestruction(std::vector<Block>& blocks, std::vector<int> rows)
{
	if (rows.size() == 0) return;

	collisionHandler.clear();

	for (const auto& row : rows)
	{
		for (auto& b : blocks)
		{
			for (auto& e : b.getElementsForModification())
			{
				if (e.GetPosition().y < row) e.moveDown();
			}
		}
	}

	for (auto& b : blocks) collisionHandler.addCollider(b);
}

bool BlockMover::move(Block& block)
{

	auto gravityMove = applyGravity(block);
	auto userMove = applyUserActions(block);
	return gravityMove || userMove;
}

bool BlockMover::applyGravity(Block& block)
{
	return moveDown(block);
}

bool BlockMover::applyUserActions(Block& block)
{
	bool anyMove{};
	for (auto userAction : userActions)
	{
		anyMove = applyUserAction(userAction, block) || anyMove;
	}
	return anyMove;
}

bool BlockMover::applyUserAction(const UserAction& userAction, Block& block)
{
	switch (userAction)
	{	
		case UserAction::Up:
			return rotate(block);
			break;
		case UserAction::Down:
			return moveDown(block);
		case UserAction::Right:
			return moveRight(block);
		case UserAction::Left:
			return moveLeft(block);
	}
	return false;
}

bool BlockMover::moveDown(Block& block)
{
	if (canMove(block, WorldDirection::down))
	{
		collisionHandler.removeCollider(block);
		block.moveDown();
		collisionHandler.addCollider(block);
		return true;
	}
	return false;
}

bool BlockMover::moveRight(Block& block)
{
	if (canMove(block, WorldDirection::right))
	{
		collisionHandler.removeCollider(block);
		block.moveRight();
		collisionHandler.addCollider(block);
		return true;
	}
	return false;
}

bool BlockMover::moveLeft(Block& block)
{
	if (canMove(block, WorldDirection::left))
	{
		collisionHandler.removeCollider(block);
		block.moveLeft();
		collisionHandler.addCollider(block);
		return true;
	}
	return false;
}

bool BlockMover::rotate(Block& block)
{
	if (canRotate(block))
	{
		collisionHandler.removeCollider(block);
		block.rotate();
		collisionHandler.addCollider(block);
		return true;
	}
	return false;
}

bool BlockMover::canMove(Block& block, sf::Vector2i move)
{
	for (auto& e : block.getElements())
	{
		if (collisionHandler.isColliding(e, move))
		{
			return false;
		}
	}
	return true;
}

bool BlockMover::canRotate(Block& block)
{
	for (auto& e : block.getElements())
	{
		auto move{e.getRotate()};
		if (collisionHandler.isColliding(e, move))
		{
			return false;
		}
	}
	return true;
}
