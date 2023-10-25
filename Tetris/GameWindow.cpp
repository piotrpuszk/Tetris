#include "GameWindow.h"

GameWindow::GameWindow(WorldProperties worldProperties)
	:
	window
	{
		worldProperties.GetScreenSize(),
		worldProperties.GetGameName(),
		sf::Style::Resize | sf::Style::Titlebar | sf::Style::Close
	}
{
	window.setVerticalSyncEnabled(true);
}

sf::RenderWindow& GameWindow::getWindow()
{
	return window;
}
