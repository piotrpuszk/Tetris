#pragma once
#include <SFML/Graphics.hpp>

class TextureStore
{
public:
	TextureStore();
	sf::Texture& getBrick01();
	sf::Texture& getBrick02();
	sf::Texture& getBrick03();
	sf::Texture& getBrick04();
	sf::Texture& getBrick05();
	sf::Texture& getPadding();
private:
	sf::Texture brick01;
	sf::Texture brick02;
	sf::Texture brick03;
	sf::Texture brick04;
	sf::Texture brick05;
	sf::Texture padding;
};

