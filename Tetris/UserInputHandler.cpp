#include "UserInputHandler.h"

void UserInputHandler::update()
{
	downPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || downPressed;
	rightPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || rightPressed;
	leftPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || leftPressed;
}

bool UserInputHandler::handle(sf::RenderWindow& window)
{
	sf::Event windowEvent{};
	while (window.pollEvent(windowEvent))
	{
		if (windowEvent.type == sf::Event::Closed)
		{
			return true;
		}
		else if (windowEvent.type == sf::Event::KeyReleased)
		{
			upPressed = windowEvent.key.scancode == sf::Keyboard::Scan::Up;
		}
	}
	return false;
}

std::vector<UserAction> UserInputHandler::getUserActions()
{
	std::vector<UserAction> actions{};
	if (rightPressed) actions.push_back(UserAction::Right);
	if (leftPressed) actions.push_back(UserAction::Left);
	if (upPressed) actions.push_back(UserAction::Up);
	if (downPressed) actions.push_back(UserAction::Down);

	upPressed = false;
	downPressed = false;
	rightPressed = false;
	leftPressed = false;
	return actions;
}
