#include "TextureStore.h"

TextureStore::TextureStore()
	:
	brick01{}
{
	brick01.loadFromFile("Brick01.jpg");
	brick02.loadFromFile("Brick02.jpg");
	brick03.loadFromFile("Brick03.png");
	brick04.loadFromFile("Brick04.jpg");
	brick05.loadFromFile("Brick05.jpg");
}

sf::Texture& TextureStore::getBrick01()
{
	return brick01;
}

sf::Texture& TextureStore::getBrick02()
{
	return brick02;
}

sf::Texture& TextureStore::getBrick03()
{
	return brick03;
}

sf::Texture& TextureStore::getBrick04()
{
	return brick04;
}

sf::Texture& TextureStore::getBrick05()
{
	return brick05;
}