#include "Paddle.h"
#include "InputManager.h"
#include <iostream>

Paddle::Paddle(sf::Vector2f startPosition, sf::Keyboard::Key upKey, sf::Keyboard::Key downKey)
	: position{ startPosition }, upKey{ upKey }, downKey{ downKey }, moveSpeed{ 250.f }
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
	HandleInput(deltaTime);
	shape.setPosition(position);
}

void Paddle::Render(sf::RenderWindow* window)
{
	window->draw(shape);
}

void Paddle::HandleInput(float deltaTime)
{
	if (InputManager::Instance->IsKeypressed(upKey))
	{
		position.y -= moveSpeed * deltaTime;
	}
	if (InputManager::Instance->IsKeypressed(downKey))
	{
		position.y += moveSpeed * deltaTime;
	}
}

