#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "WorldProperties.h"

class PositionToPixelConverter
{
public:
	PositionToPixelConverter(const WorldProperties& worldProperties);
	sf::Vector2f getPixelsForPosition(const sf::Vector2i &position) const noexcept;
private:
	float pixelsPerWidth;
	float pixelsPerHeight;
};

