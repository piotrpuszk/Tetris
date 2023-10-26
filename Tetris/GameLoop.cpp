#include "GameLoop.h"

GameLoop::GameLoop(const WorldProperties& worldProperties, std::vector<Block>& blocks, ScoreController& scoreController, TextureStore& textureStore)
	:
	fixedTimeClock{},
	blocks{ blocks },
	fixedTimeRate{ sf::milliseconds(150) },
	collisionTable{ { worldProperties } },
	collisionHandler{ collisionTable, worldProperties },
	blockMover{ collisionHandler },
	userInputHandler{},
	tileDestroyer{ collisionTable, blocks },
	randomShapeGenerator{ {worldProperties.GetTileSize(), worldProperties.GetTileSize()}, worldProperties.GetMapSize().x / 2, textureStore },
	currentBlockIndex{},
	destroyedRows{},
	scoreController{ scoreController }
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
		auto destroyedResult{ tileDestroyer.destroyAll() };
		for (auto& e : destroyedResult) destroyedRows.push_back(e);
		scoreController.addScoreWithDestroyedRowsCount(destroyedResult.size());
		blocks.push_back(randomShapeGenerator.next());
		currentBlockIndex = blocks.size() - 1;
	}
}

void GameLoop::update(sf::RenderWindow& window)
{
	blockMover.moveAfterDestruction(blocks, destroyedRows);
	destroyedRows.clear();

	userInputHandler.update();
	if (userInputHandler.handle(window))
	{
		window.close();
	}
}