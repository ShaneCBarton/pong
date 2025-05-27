#include "Background.h"
#include <iostream>

Background::Background()
{
}

void Background::Start()
{
	for (int i = 0; i < numberOfDashes; i++)
	{
		sf::RectangleShape shape{ sf::Vector2f(20, 50) };
		shape.setFillColor(sf::Color::White);
		shape.setPosition(1280 / 2, i * 75 + 100);
		rects[i] = shape;
	}
}

void Background::Render(std::shared_ptr<sf::RenderWindow> window)
{
	for (const sf::RectangleShape& rect : rects)
	{
		window->draw(rect);
		std::cout << "drawing" << std::endl;
	}
}
