#include "Renderer.h"

Renderer::Renderer(sf::RenderWindow& window,
	std::vector<Block>& blocks,
	WorldProperties& worldProperties,
	ScoreController& scoreController,
	TextDrawer textDrawer,
	MapDisplayer& mapDisplayer)
	:
	window{ window },
	blocks{ blocks },
	worldProperties{ worldProperties },
	positionToPixelConverter{ worldProperties },
	scoreController{ scoreController },
	textDrawer{ textDrawer },
	backgroundTexture{},
	background{},
	mapDisplayer{ mapDisplayer }
{
	backgroundTexture.loadFromFile("grass01.png");
	const float width{ static_cast<float>(sf::VideoMode::getDesktopMode().width) };
	const float height{ static_cast<float>(sf::VideoMode::getDesktopMode().height) };
	const auto blockSize{ 50.f };
	sf::Vector2f startPosition{ };
	backgroundTexture.setRepeated(true);
	sf::Vector2f position{};
	for (; position.x < width; position.x += blockSize)
	{
		position.y = 0.f;
		for (; position.y < height; position.y += blockSize)
		{
			sf::RectangleShape block{ sf::Vector2f{blockSize, blockSize} };
			block.setPosition(startPosition + position);
			block.setTexture(&backgroundTexture);
			background.push_back(block);
		}
	}
}

void Renderer::render()
{
	window.clear(sf::Color::Black);

	for (const auto& e : background)
	{
		window.draw(e);
	}

	for (const auto& paddingBlock : mapDisplayer.getPaddingBlocks())
	{
		window.draw(paddingBlock);
	}

	for (const auto& block : blocks)
	{
		for (const auto& e : block.getElements())
		{
			auto image = e.GetImage();
			auto position{ positionToPixelConverter.getPixelsForPosition(e.GetPosition()) };
			position.x += mapDisplayer.getLeftPadding();
			image.setPosition(position);
			window.draw(image);
		}
	}

	window.draw(textDrawer.write("Score: " + std::to_string(scoreController.getScore())));

	window.display();
}
