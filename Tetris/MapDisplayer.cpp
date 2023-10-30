#include "MapDisplayer.h"

MapDisplayer::MapDisplayer(const WorldProperties& worldProperties, TextureStore& textureStore)
	:
	paddingBlocks{},
	leftPadding{}
{
	sf::Vector2u desktopScreenSize{ sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height };

	auto horizontalPadding{ desktopScreenSize.x - worldProperties.GetScreenSize().x };
	auto verticalPadding{ desktopScreenSize.y - worldProperties.GetScreenSize().y };

	sf::RectangleShape verticalPaddingBlock{ sf::Vector2f(sf::VideoMode::getDesktopMode().width, verticalPadding) };
	verticalPaddingBlock.setPosition(0, sf::VideoMode::getDesktopMode().height - verticalPadding);
	verticalPaddingBlock.setTexture(&textureStore.getPadding());
	verticalPaddingBlock.setTextureRect(sf::IntRect{0, 0, static_cast<int>(sf::VideoMode::getDesktopMode().width), static_cast<int>(verticalPadding) });

	sf::RectangleShape horizontalPaddingBlockLeft{ sf::Vector2f(horizontalPadding * 0.5, sf::VideoMode::getDesktopMode().height) };
	sf::RectangleShape horizontalPaddingBlockRight{ sf::Vector2f(horizontalPadding * 0.5, sf::VideoMode::getDesktopMode().height) };
	horizontalPaddingBlockRight.setPosition(worldProperties.GetScreenSize().x + horizontalPaddingBlockLeft.getSize().x, 0);

	horizontalPaddingBlockLeft.setTexture(&textureStore.getPadding());
	horizontalPaddingBlockRight.setTexture(&textureStore.getPadding());
	paddingBlocks.push_back(horizontalPaddingBlockLeft);
	paddingBlocks.push_back(horizontalPaddingBlockRight);
	paddingBlocks.push_back(verticalPaddingBlock);

	leftPadding = horizontalPaddingBlockLeft.getSize().x;
}

std::vector<sf::RectangleShape>& MapDisplayer::getPaddingBlocks() noexcept
{
	return paddingBlocks;
}

float MapDisplayer::getLeftPadding() const noexcept
{
	return leftPadding;
}
