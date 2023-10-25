#include "Renderer.h"

Renderer::Renderer(sf::RenderWindow& window, std::vector<Block>& blocks, WorldProperties& worldProperties)
	: 
	window{ window },
	blocks{ blocks },
	worldProperties{ worldProperties },
	positionToPixelConverter{ worldProperties }
{
}

void Renderer::render()
{
	window.clear(sf::Color::Black);

	for (const auto& block : blocks)
	{
		for (const auto& e : block.getElements())
		{
			auto image = e.GetImage();
			image.setFillColor(sf::Color::Yellow);
			auto position{ positionToPixelConverter.getPixelsForPosition(e.GetPosition()) };
			image.setPosition(position);
			window.draw(image);
		}
	}

	window.display();
}
