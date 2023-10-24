#pragma once

class WorldProperties
{
public:
	WorldProperties(unsigned int screenWidth,
	unsigned int screenHeight,
	unsigned int mapWidth,
	unsigned int mapHeight);
	unsigned int GetScreenWidth() const;
	unsigned int GetScreenHeight() const;
	unsigned int GetMapWidth() const;
	unsigned int GetMapHeight() const;


private:
	unsigned int screenWidth;
	unsigned int screenHeight;
	unsigned int mapWidth;
	unsigned int mapHeight;
};