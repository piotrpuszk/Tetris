#include "TextureStore.h"

TextureStore::TextureStore()
	:
	brick01{}
{
	brick01.loadFromFile("Brick02.png");
	brick02.loadFromFile("Brick03.png");
	brick03.loadFromFile("Brick04.png");
	brick04.loadFromFile("Brick05.png");
	brick05.loadFromFile("Brick06.png");
	padding.loadFromFile("Brick01.png");
	padding.setRepeated(true);
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

sf::Texture& TextureStore::getPadding()
{
	return padding;
}
