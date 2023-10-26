#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include "Tile.h"
#include "WorldProperties.h"
#include "Renderer.h"
#include "GameLoop.h"
#include "ScoreController.h"
#include "TextureStore.h"

int main()
{
	WorldProperties worldProperties{ sf::Vector2u{12, 20}, 50.f, "Tetrisso" };
	sf::RenderWindow window
	{
		{worldProperties.GetScreenSize().x, worldProperties.GetScreenSize().y},
		worldProperties.GetGameName(),
		sf::Style::Resize | sf::Style::Titlebar | sf::Style::Close
	};
	window.setVerticalSyncEnabled(true);

	std::vector<Block> blocks{};
	ScoreController scoreController{ worldProperties };
	TextDrawer textDrawer{};
	TextureStore textureStore{};
	if (!textDrawer.setFont("Roboto-Regular.ttf"))
	{
		std::cerr << "Font " << "Roboto-Regular.ttf" << " could not be set up" << std::endl;
		return 1;
	}
	textDrawer.setStyle(24, sf::Color::Green);
	Renderer renderer{ window, blocks, worldProperties, scoreController, textDrawer };
	GameLoop gameLoop{ worldProperties, blocks, scoreController, textureStore };

	while (window.isOpen())
	{
		gameLoop.update(window);
		gameLoop.fixedUpdate();
		renderer.render();
	}

	return 0;
}