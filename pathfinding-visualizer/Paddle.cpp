#include "Paddle.h"
#include "InputManager.h"
#include "Game.h"

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

void Paddle::Render(std::shared_ptr<sf::RenderWindow> window)
{
	window->draw(shape);
}

void Paddle::HandleInput(float deltaTime)
{
	if (InputManager::Instance->IsKeypressed(upKey))
	{
		position.y -= moveSpeed * deltaTime;
		if (position.y < 5)
		{
			position.y = 5;
		}
	}
	if (InputManager::Instance->IsKeypressed(downKey))
	{
		position.y += moveSpeed * deltaTime;
		if (position.y > HEIGHT - shape.getSize().y - 5)
		{
			position.y = HEIGHT - shape.getSize().y - 5;
		}
	}
}

