#include "PositionToPixelConverter.h"

PositionToPixelConverter::PositionToPixelConverter(unsigned int screenWidth, unsigned int screenHeight, unsigned int mapWidth, unsigned int mapHeight)
	: pixelsPerWidth{ static_cast<float>(screenWidth / mapWidth) }, pixelsPerHeight{ static_cast<float>(screenHeight / mapHeight) }
{
}

sf::Vector2f PositionToPixelConverter::getPixelsForPosition(const sf::Vector2i& position) const noexcept
{
	return sf::Vector2f{ position.x * pixelsPerWidth, position.y * pixelsPerHeight };
}