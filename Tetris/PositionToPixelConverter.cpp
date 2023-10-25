#include "PositionToPixelConverter.h"

PositionToPixelConverter::PositionToPixelConverter(const WorldProperties& worldProperties)
	: pixelsPerWidth{ static_cast<float>(worldProperties.GetScreenSize().x / worldProperties.GetMapSize().x)},
	pixelsPerHeight{ static_cast<float>(worldProperties.GetScreenSize().y / worldProperties.GetMapSize().y) }
{
}

sf::Vector2f PositionToPixelConverter::getPixelsForPosition(const sf::Vector2i& position) const noexcept
{
	return sf::Vector2f{ position.x * pixelsPerWidth, position.y * pixelsPerHeight };
}