#include "Paddle.h"
#include "InputManager.h"
#include <iostream>

Paddle::Paddle(sf::Vector2f startPosition, sf::Keyboard::Key upKey, sf::Keyboard::Key downKey)
	: position{ startPosition }, upKey{ upKey }, downKey{ downKey }
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
	if (InputManager::Instance->IsKeypressed(upKey))
	{
		std::cout << "Moving up" << std::endl;
	}	
	if (InputManager::Instance->IsKeypressed(downKey))
	{
		std::cout << "Moving down" << std::endl;
	}
	shape.setPosition(position);
}

void Paddle::Render(sf::RenderWindow* window)
{
	window->draw(shape);
}

