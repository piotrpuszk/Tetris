#include "TextDrawer.h"

bool TextDrawer::setFont(std::string fontPath)
{
	font = {};
	auto isSuccess{ font.loadFromFile(fontPath) };

	if (!isSuccess)
	{
		return isSuccess;
	}

	text.setFont(font);

	return isSuccess;
}

void TextDrawer::setStyle(unsigned fontSize, sf::Color color, sf::Text::Style styleFlags)
{
	text.setCharacterSize(fontSize);
	text.setFillColor(color);
	text.setStyle(styleFlags);
}

sf::Text TextDrawer::write(std::string textToWrite, sf::Vector2f position)
{
	text.setPosition(position);
	text.setString(textToWrite);
	return text;
}

sf::Text TextDrawer::write(unsigned textToWrite, sf::Vector2f position)
{
	return write(std::to_string(textToWrite), position);
}
