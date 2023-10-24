#include "WorldProperties.h"

WorldProperties::WorldProperties(unsigned int screenWidth, unsigned int screenHeight, unsigned int mapWidth, unsigned int mapHeight)
	: screenWidth{ screenWidth }, screenHeight{ screenHeight }, mapWidth{ mapWidth }, mapHeight{ mapHeight }
{
}

unsigned int WorldProperties::GetScreenWidth() const
{
	return screenWidth;
}

unsigned int WorldProperties::GetScreenHeight() const
{
	return screenHeight;
}

unsigned int WorldProperties::GetMapWidth() const
{
	return mapWidth;
}

unsigned int WorldProperties::GetMapHeight() const
{
	return mapHeight;
}
