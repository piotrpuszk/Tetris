#include "WorldProperties.h"

WorldProperties::WorldProperties(sf::Vector2u mapSize, float tileSize, std::string gameName)
	:
	gameName{ gameName },
	mapSize{ mapSize },
	tileSize{ tileSize },
	screenSize{ static_cast<unsigned int>(tileSize * mapSize.x), static_cast<unsigned int>(tileSize * mapSize.y) }
{
}

sf::Vector2u WorldProperties::GetScreenSize() const noexcept
{
	return screenSize;
}

sf::Vector2u WorldProperties::GetMapSize() const noexcept
{
	return mapSize;
}

float WorldProperties::GetTileSize() const noexcept
{
	return tileSize;
}

std::string WorldProperties::GetGameName() const noexcept
{
	return gameName;
}
