#include "Paddle.h"

Paddle::Paddle(sf::Vector2f startPosition)
	: position{ startPosition }
{

}

void Paddle::Start()
{
	shape.setSize(sf::Vector2f(30, 100));
	shape.setOutlineThickness(2);
	shape.setFillColor(sf::Color::Black);
	shape.setOutlineColor(sf::Color::White);
}

void Paddle::Update(float deltaTime)
{
	shape.setPosition(position);
}

void Paddle::Render(sf::RenderWindow* window)
{
	window->draw(shape);
}
