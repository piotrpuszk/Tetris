#include "Block.h"

std::atomic_uint32_t Block::nextId{};

Block::Block()
	: Block{ {} }
{
}

Block::Block(std::vector<Tile> newElements)
	: id{ ++nextId }, elements{ newElements }
{
}

void Block::setElements(std::vector<Tile> newElements)
{
	elements.clear();
	for (auto e : newElements)
	{
		elements.push_back(e);
	}
}

unsigned int Block::deleteElement(const sf::Vector2i position)
{
	auto countBefore{ elements.size()};
	elements.erase(std::remove_if(elements.begin(), elements.end(), [&position](const Tile& e) {return e.GetPosition() == position; }), elements.end());
	return countBefore - elements.size();
}

void Block::moveDown()
{
	for (auto& element : elements)
	{
		element.moveDown();
	}
}

void Block::moveRight()
{
	for (auto& element : elements)
	{
		element.moveRight();
	}
}

void Block::moveLeft()
{
	for (auto& element : elements)
	{
		element.moveLeft();
	}
}

void Block::rotate()
{
	for (auto& element : elements)
	{
		element.rotate();
	}
}

void Block::print() const
{
	std::cout << "~~~~~~~~~~~~~~~~~~~~" << std::endl;
	for (const auto& e : elements)
	{
		std::cout << "(" << e.GetPosition().x << ", " << e.GetPosition().y << ") ";
	}
	std::cout << std::endl << "~~~~~~~~~~~~~~~~~~~~" << std::endl;
}

const std::vector<Tile>& Block::getElements() const
{
	return elements;
}

std::vector<Tile>& Block::getElementsForModification()
{
	return elements;
}

const unsigned int Block::getId() const noexcept
{
	return id;
}
