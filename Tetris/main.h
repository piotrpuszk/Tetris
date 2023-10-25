#pragma once

void FixedUpdate(sf::Clock& fixedTimeClock, BlockMover& blockMover, UserInputHandler& userInputHandler, bool& anyMove, std::vector<Block>& blocks, size_t& currentBlockIndex, TileDestroyer& tileDestroyer, Block& newBlock, RandomShapeGenerator& randomShapeGenerator);

void Update(std::vector<Block>& blocks, const size_t& currentBlockIndex, BlockMover& blockMover, UserInputHandler& userInputHandler, sf::RenderWindow& window);
