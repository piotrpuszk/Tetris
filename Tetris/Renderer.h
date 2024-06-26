#pragma once
#include <SFML/Graphics.hpp>
#include <thread>
#include <vector>
#include "WorldProperties.h"
#include "Block.h"
#include "PositionToPixelConverter.h"
#include "ScoreController.h"
#include "TextDrawer.h"
#include "MapDisplayer.h"

#include <iostream>

class Renderer
{
public:
	Renderer(sf::RenderWindow& window,
		std::vector<Block>& blocks,
		WorldProperties& worldProperties,
		ScoreController& scoreController,
		TextDrawer textDrawer, 
		MapDisplayer& mapDisplayer);

	void render();
private:
	sf::RenderWindow& window;
	std::vector<Block>& blocks;
	WorldProperties& worldProperties;
	PositionToPixelConverter positionToPixelConverter;
	ScoreController& scoreController;
	TextDrawer textDrawer;
	sf::Texture backgroundTexture;
	std::vector<sf::RectangleShape> background;
	MapDisplayer& mapDisplayer;
};

