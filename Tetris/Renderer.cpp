#include "Renderer.h"

Renderer::Renderer(std::shared_ptr<sf::RenderWindow> window,
	std::shared_ptr<std::vector<std::shared_ptr<Block>>> blocks,
	std::shared_ptr<WorldProperties> worldProperties,
	std::shared_ptr<const bool> renderThreadCancellationToken)
	: window{ window },
	blocks{ blocks },
	worldProperties{ worldProperties },
	renderThreadCancellationToken{ renderThreadCancellationToken }
{
}

void Renderer::render()
{
	PositionToPixelConverter positionToPixel{ worldProperties->GetScreenWidth(), worldProperties->GetScreenHeight(), worldProperties->GetMapWidth(), worldProperties->GetMapHeight() };
	window->setActive(true);
	while (!(*renderThreadCancellationToken) && window->isOpen())
	{
		window->clear(sf::Color::Black);

		for (const auto& block : *blocks)
			for (const auto& e : block->getElements())
			{
				auto image = e.GetImage();
				image.setFillColor(sf::Color::Yellow);
				auto position{ positionToPixel.getPixelsForPosition(e.GetPosition()) };
				image.setPosition(position);
				window->draw(image);
			}

		window->display();
	}
}
