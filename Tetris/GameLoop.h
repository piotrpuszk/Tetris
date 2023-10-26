#pragma once
#include <vector>
#include "BlockMover.h"
#include "TileDestroyer.h"
#include "RandomShapeGenerator.h"
#include "UserInputHandler.h"
#include "ScoreController.h"
#include "TextureStore.h"

class GameLoop
{
public:
	GameLoop(const WorldProperties& worldProperties, std::vector<Block>& blocks, ScoreController& scoreController, TextureStore& textureStore);
	void update(sf::RenderWindow& window);
	void fixedUpdate();
private:
	sf::Clock fixedTimeClock;
	sf::Time fixedTimeRate;
	CollisionTable collisionTable;
	CollisionHandler collisionHandler;
	BlockMover blockMover;
	UserInputHandler userInputHandler;
	std::vector<Block>& blocks;
	size_t currentBlockIndex;
	TileDestroyer tileDestroyer;
	RandomShapeGenerator randomShapeGenerator;
	std::vector<int> destroyedRows;
	ScoreController& scoreController;
};

