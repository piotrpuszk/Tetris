#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

namespace WorldRotation
{
	std::vector<sf::Vector2i> rotationTable
	{ 
		{1, 1}, 
		{1, -1}, 
		{-1, -1}, 
		{-1, 1} 
	};
}