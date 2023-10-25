#include "GameLoop.h"

GameLoop::GameLoop(const WorldProperties& worldProperties, std::vector<Block>& blocks)
	:
	fixedTimeClock{},
	blocks{ blocks },
	fixedTimeRate{ sf::milliseconds(150) },
	collisionTable{ { worldProperties } },
	collisionHandler{ collisionTable, worldProperties },
	blockMover{ collisionHandler },
	userInputHandler{},
	tileDestroyer{ collisionTable, blocks },
	randomShapeGenerator{ {worldProperties.GetTileSize(), worldProperties.GetTileSize()}, worldProperties.GetMapSize().x / 2 },
	currentBlockIndex{}
{
	blocks.push_back(randomShapeGenerator.next());
}


void GameLoop::fixedUpdate()
{
	if (fixedTimeClock.getElapsedTime() < fixedTimeRate) return;

	fixedTimeClock.restart();
	blockMover.setUserActions(userInputHandler.getUserActions());
	auto anyMove{ blockMover.move(blocks[currentBlockIndex]) };

	if (!anyMove)
	{
		tileDestroyer.destroyAll();
		blocks.push_back(randomShapeGenerator.next());
		currentBlockIndex = blocks.size() - 1;
	}
}

void GameLoop::update(sf::RenderWindow& window)
{
	for (auto& b : blocks)
	{
		if (b.getId() == blocks[currentBlockIndex].getId()) continue;
		blockMover.applyGravity(b);
	}

	userInputHandler.update();
	if (userInputHandler.handle(window))
	{
		window.close();
	}
}