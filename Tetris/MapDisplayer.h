#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "WorldProperties.h"
#include "TextureStore.h"

class MapDisplayer
{
public:
	MapDisplayer(const WorldProperties& worldProperties, TextureStore& textureStore);
	std::vector<sf::RectangleShape>& getPaddingBlocks() noexcept;
	float getLeftPadding() const noexcept;
private:
	std::vector<sf::RectangleShape> paddingBlocks;
	float leftPadding;
};

