#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <thread>
#include "Tile.h"
#include "WorldProperties.h"
#include "Renderer.h"
#include "GameLoop.h"
#include "ScoreController.h"
#include "TextureStore.h"
#include "MapDisplayer.h"

const std::string musicFile{ "Country Title Loop.wav" };
const std::string fontFile{ "Roboto-Regular.ttf" };
const std::string gameName{ "Tetrisso" };
const sf::Vector2u mapSize{ 12, 20 };
const float tileSize{ 50.f };
const unsigned fontSize{ 24 };
sf::Color textColor{ sf::Color::Green };

int main()
{
	WorldProperties worldProperties{ mapSize, tileSize, gameName };
	sf::RenderWindow window
	{
		sf::VideoMode::getDesktopMode(),
		worldProperties.GetGameName(),
		sf::Style::Fullscreen
	};
	window.setVerticalSyncEnabled(true);

	std::vector<Block> blocks{};
	ScoreController scoreController{ worldProperties };
	TextDrawer textDrawer{};
	TextureStore textureStore{};
	MapDisplayer mapDisplayer{ worldProperties, textureStore };
	if (!textDrawer.setFont(fontFile))
	{
		std::cerr << "Font " << fontFile << " could not be set up" << std::endl;
		return 1;
	}
	textDrawer.setStyle(fontSize, textColor);
	Renderer renderer{ window, blocks, worldProperties, scoreController, textDrawer, mapDisplayer };
	GameLoop gameLoop{ worldProperties, blocks, scoreController, textureStore };
	sf::Music music{};
	if (!music.openFromFile(musicFile))
	{
		std::cerr << "Couldn't not open a music file " << musicFile << std::endl;
	}
	else
	{
		music.setLoop(true);
		music.play();
	}

	while (window.isOpen())
	{
		gameLoop.update(window);
		gameLoop.fixedUpdate();
		renderer.render();
	}

	return 0;
}