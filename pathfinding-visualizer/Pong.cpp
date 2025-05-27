#include "Pong.h"
#include "Paddle.h"
#include "Game.h"
#include <iostream>

Pong::Pong()
{
	playerOne.reset(new Paddle(sf::Vector2f(10, HEIGHT / 2 - 50), sf::Keyboard::W, sf::Keyboard::S));
	playerTwo.reset(new Paddle(sf::Vector2f(1280 - 40, HEIGHT / 2 - 50), sf::Keyboard::Up, sf::Keyboard::Down));

	playerOneScore.reset(new Score(sf::Vector2f(WIDTH / 4, 50)));
	playerTwoScore.reset(new Score(sf::Vector2f((WIDTH / 4) + (WIDTH / 2), 50)));

	ball.reset(new Ball(sf::Vector2f(WIDTH / 2, HEIGHT / 2)));
	bg.reset(new Background());
}

Pong::~Pong()
{
}

void Pong::Start()
{
	renderObjects.push_back(std::move(bg));
	gameObjects.push_back(std::move(playerOne));
	gameObjects.push_back(std::move(playerTwo));
	gameObjects.push_back(std::move(playerOneScore));
	gameObjects.push_back(std::move(playerTwoScore));
	gameObjects.push_back(std::move(ball));

	for (auto& object : renderObjects)
	{
		object->Start();
	}

	for (auto& object : gameObjects)
	{
		object->Start();
	}

}

void Pong::Update(float deltaTime)
{
	for (auto& object : gameObjects)
	{
		if (object) { object->Update(deltaTime); }
	}
}

void Pong::Render(std::shared_ptr<sf::RenderWindow> window)
{
	for (auto& object : renderObjects)
	{
		if (object) { object->Render(window); }
	}

	for (auto& object : gameObjects)
	{
		if (object) { object->Render(window); }
	}
}

