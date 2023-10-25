#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include "Tile.h"
#include "WorldProperties.h"
#include "Renderer.h"
#include "GameLoop.h"

int main()
{
	WorldProperties worldProperties{ sf::Vector2u{12, 20}, 30.f, "Tetrisso" };
	sf::RenderWindow window
	{
		{worldProperties.GetScreenSize().x, worldProperties.GetScreenSize().y},
		worldProperties.GetGameName(),
		sf::Style::Resize | sf::Style::Titlebar | sf::Style::Close
	};
	window.setVerticalSyncEnabled(true);

	std::vector<Block> blocks{};
	Renderer renderer{ window, blocks, worldProperties };
	GameLoop gameLoop{ worldProperties, blocks };

	while (window.isOpen())
	{
		gameLoop.update(window);
		gameLoop.fixedUpdate();
		renderer.render();
	}

	return 0;
}