#pragma once
#include <SFML/Graphics.hpp>
#include "WorldProperties.h"

class GameWindow
{
public:
	GameWindow(WorldProperties worldProperties);
	sf::RenderWindow& getWindow();
private:
	sf::RenderWindow window;
};

