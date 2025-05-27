#include "Ball.h"

Ball::Ball(sf::Vector2f startPosition)
	: position{ startPosition }
{
}

void Ball::Start()
{
	shape.setSize(sf::Vector2f(10, 10));
	shape.setOutlineThickness(2);
	shape.setFillColor(sf::Color::White);
}

void Ball::Update(float deltaTime)
{
	shape.setPosition(position);
}

void Ball::Render(std::shared_ptr<sf::RenderWindow> window)
{
	window->draw(shape);
}
