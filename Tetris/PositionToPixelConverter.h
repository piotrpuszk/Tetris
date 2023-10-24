#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"

class PositionToPixelConverter
{
public:
	PositionToPixelConverter(unsigned int screenWidth, unsigned int screenHeight, unsigned int mapWidth, unsigned int mapHeight);
	sf::Vector2f getPixelsForPosition(const sf::Vector2i &position) const noexcept;
private:
	float pixelsPerWidth;
	float pixelsPerHeight;
};

