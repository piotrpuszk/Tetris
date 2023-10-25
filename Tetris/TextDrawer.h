#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class TextDrawer
{
public:
	bool setFont(std::string fontPath);
	void setStyle(unsigned fontSize, sf::Color color, sf::Text::Style styleFlags = sf::Text::Style::Regular);
	sf::Text write(std::string textToWrite, sf::Vector2f position = {});
	sf::Text write(unsigned textToWrite, sf::Vector2f position = {});
private:
	sf::Text text;
	sf::Font font;
};

