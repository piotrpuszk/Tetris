#pragma once
#include <SFML/Graphics.hpp>
#include <thread>
#include <vector>
#include "WorldProperties.h"
#include "Block.h"
#include "PositionToPixelConverter.h"
#include "ScoreController.h"
#include "TextDrawer.h"

#include <iostream>

class Renderer
{
public:
	Renderer(sf::RenderWindow& window,
		std::vector<Block>& blocks,
		WorldProperties& worldProperties,
		ScoreController& scoreController,
		TextDrawer textDrawer);

	void render();
private:
	sf::RenderWindow& window;
	std::vector<Block>& blocks;
	WorldProperties& worldProperties;
	PositionToPixelConverter positionToPixelConverter;
	ScoreController& scoreController;
	TextDrawer textDrawer;
};

