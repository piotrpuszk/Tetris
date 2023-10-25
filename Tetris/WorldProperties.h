#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class WorldProperties
{
public:
	WorldProperties(sf::Vector2u mapSize, float tileSize, std::string gameName);
	sf::Vector2u GetScreenSize() const noexcept;
	sf::Vector2u GetMapSize() const noexcept;
	float GetTileSize() const noexcept;
	std::string GetGameName() const noexcept;
private:
	sf::Vector2u screenSize;
	sf::Vector2u mapSize;
	float tileSize;
	std::string gameName;
};