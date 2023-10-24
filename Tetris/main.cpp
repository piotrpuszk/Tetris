#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include "Tile.h"
#include "WorldProperties.h"
#include "RandomShapeGenerator.h"
#include "CollisionTable.h"
#include "CollisionHandler.h"
#include "UserInputHandler.h"
#include "BlockMover.h"
#include "Renderer.h"
#include "TileDestroyer.h"

const unsigned int mapWidth = 20;
const unsigned int mapHeight = 32;
const float tileSize = 30;
sf::Clock fixedTimeClock{};
sf::Time fixedTimeRate{ sf::milliseconds(150) };

bool handleUserFixedStep(UserInputHandler& userInputHandler, std::shared_ptr<sf::RenderWindow> window, BlockMover& blockMover,std::shared_ptr<Block> currentBlock)
{
	if (fixedTimeClock.getElapsedTime() >= fixedTimeRate)
	{
		fixedTimeClock.restart();
		blockMover.setUserActions(userInputHandler.getUserActions());
		blockMover.setBlock(currentBlock);
		return blockMover.move();
	}
}


int main()
{
	auto videoMode{ sf::VideoMode::getDesktopMode() };
	videoMode.width = tileSize * mapWidth;
	videoMode.height = tileSize * mapHeight;
	std::cout << videoMode.width << " " << videoMode.height << std::endl;
	auto worldProperties = std::make_shared<WorldProperties>(videoMode.width, videoMode.height, mapWidth, mapHeight);

	auto window = std::make_shared<sf::RenderWindow>(videoMode, "Tetrisso", sf::Style::Resize | sf::Style::Titlebar | sf::Style::Close);
	window->setVerticalSyncEnabled(true);
	window->setActive(false);

	auto renderThreadCancellationToken = std::make_shared<bool>();
	RandomShapeGenerator randomShapeGenerator{ {tileSize, tileSize}, worldProperties->GetMapWidth() / 2 };
	auto blocks = std::make_shared<std::vector<std::shared_ptr<Block>>>();
	auto currentBlock = std::make_shared<Block>(randomShapeGenerator.next());
	blocks->push_back(currentBlock);

	Renderer renderer{ window, blocks, worldProperties, renderThreadCancellationToken };
	std::thread renderThread{ &Renderer::render, renderer };

	
	sf::Vector2i mapSize(worldProperties->GetMapWidth(), worldProperties->GetMapHeight());
	auto collisionTable = std::make_shared<CollisionTable>(mapSize);
	CollisionHandler collisionHandler{ collisionTable, mapSize };
	UserInputHandler userInputHandler{};
	BlockMover blockMover{ collisionHandler };
	TileDestroyer tileDestroyer{ collisionTable, blocks };
	bool anyTileDestroyed{};
	bool anyMove{};

	while (window->isOpen())
	{
		for (auto& b : *blocks)
		{
			if (&*b == &*currentBlock) continue;
			blockMover.setBlock(b);
			blockMover.applyGravity();
		}


		userInputHandler.update();
		if (userInputHandler.handle(*window))
		{
			*renderThreadCancellationToken = true;
			renderThread.join();
			window->close();
		}

		anyMove = handleUserFixedStep(userInputHandler, window, blockMover, currentBlock);

		if (!anyMove)
		{
			anyTileDestroyed = tileDestroyer.destroyAll() > 0;
			currentBlock = std::make_shared<Block>(randomShapeGenerator.next());
			blockMover.setBlock(currentBlock);
			blocks->push_back(currentBlock);
		}


		
	}

	return 0;
}