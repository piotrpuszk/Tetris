#include "TextureStore.h"

TextureStore::TextureStore()
	:
	brick01{}
{
	brick01.loadFromFile("polyHavenBrick01.jpg");
	brick02.loadFromFile("polyHavenBrick03.jpg");
	brick03.loadFromFile("polyHavenBrickPavement.jpg");
	brick04.loadFromFile("polyHavenRoseWood.jpg");
	brick05.loadFromFile("polyHavenDarkBrick.jpg");
	padding.loadFromFile("polyHavenBrickPavement02.jpg");
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
