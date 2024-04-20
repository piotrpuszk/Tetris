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
	verticalPaddingBlock.setTextureRect(sf::IntRect{ 0, 0, static_cast<int>(sf::VideoMode::getDesktopMode().width), static_cast<int>(verticalPadding) });


	const float horizontalWidth{ static_cast<float>(horizontalPadding) * 0.5f };
	const float horizontalHeight{ static_cast<float>(sf::VideoMode::getDesktopMode().height) };
	const auto blockSize{ 50.f };
	sf::Vector2f startPosition{ horizontalWidth - blockSize, 0.f };
	sf::Vector2f position{};
	for (; position.x < horizontalWidth; position.x += blockSize)
	{
		position.y = 0.f;
		for (; position.y < horizontalHeight; position.y += blockSize)
		{
			sf::RectangleShape block{ sf::Vector2f{blockSize, blockSize} };
			block.setPosition(sf::Vector2f{ startPosition.x - position.x, startPosition.y + position.y });
			block.setTexture(&textureStore.getPadding());
			paddingBlocks.push_back(block);
		}
	}

	startPosition = { static_cast<float>(worldProperties.GetScreenSize().x + horizontalWidth), 0.f };
	position = {};
	for (; position.x < horizontalWidth; position.x += blockSize)
	{
		position.y = 0.f;
		for (; position.y < horizontalHeight; position.y += blockSize)
		{
			sf::RectangleShape block{ sf::Vector2f{blockSize, blockSize} };
			block.setPosition(startPosition + position);
			block.setTexture(&textureStore.getPadding());
			paddingBlocks.push_back(block);
		}
	}

	const float verticalWidth{ static_cast<float>(sf::VideoMode::getDesktopMode().width) };
	const float verticalHeight{ static_cast<float>(verticalPadding) };
	startPosition = { 0.f, static_cast<float>(sf::VideoMode::getDesktopMode().height) - verticalHeight };
	position = {};
	for (; position.x < verticalWidth; position.x += blockSize)
	{
		position.y = 0.f;
		for (; position.y < verticalHeight; position.y += blockSize)
		{
			sf::RectangleShape padding{ sf::Vector2f{blockSize, blockSize} };
			padding.setPosition(startPosition + position);
			padding.setTexture(&textureStore.getPadding());
			paddingBlocks.push_back(padding);
		}
	}

	leftPadding = horizontalWidth;
}

std::vector<sf::RectangleShape>& MapDisplayer::getPaddingBlocks() noexcept
{
	return paddingBlocks;
}

float MapDisplayer::getLeftPadding() const noexcept
{
	return leftPadding;
}
