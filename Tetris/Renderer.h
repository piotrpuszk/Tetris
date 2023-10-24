#pragma once
#include <SFML/Graphics.hpp>
#include <thread>
#include <vector>
#include "WorldProperties.h"
#include "Block.h"
#include "PositionToPixelConverter.h"

#include <iostream>

class Renderer
{
public:
	Renderer(std::shared_ptr<sf::RenderWindow> window,
		std::shared_ptr<std::vector<std::shared_ptr<Block>>> blocks,
		std::shared_ptr<WorldProperties> worldProperties,
		std::shared_ptr<const bool> renderThreadCancellationToken);

	void render();
private:
	std::shared_ptr<sf::RenderWindow> window;
	std::shared_ptr<std::vector<std::shared_ptr<Block>>> blocks;
	std::shared_ptr<WorldProperties> worldProperties;
	std::shared_ptr<const bool> renderThreadCancellationToken;
};

