#pragma once
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "UserAction.h"

class UserInputHandler
{
public:
	void update();
	bool handle(sf::RenderWindow& window);
	std::vector<UserAction> getUserActions();
private:
	bool upPressed;
	bool downPressed;
	bool rightPressed;
	bool leftPressed;
};

