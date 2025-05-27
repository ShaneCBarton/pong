#include "Pong.h"
#include "Paddle.h"
#include "Game.h"
#include <iostream>

Pong::Pong()
{
	playerOne = new Paddle(sf::Vector2f(10, HEIGHT / 2 - 50), sf::Keyboard::W, sf::Keyboard::S);
	playerTwo = new Paddle(sf::Vector2f(1280 - 40, HEIGHT / 2 - 50), sf::Keyboard::Up, sf::Keyboard::Down);

	playerOneScore = new Score(sf::Vector2f(WIDTH / 4, 50));
	playerTwoScore = new Score(sf::Vector2f((WIDTH / 4) + (WIDTH / 2), 50));

	ball = new Ball(sf::Vector2f(WIDTH / 2, HEIGHT / 2));
	bg = new Background();

}

Pong::~Pong()
{
	delete playerOne;
	delete playerTwo;
	delete playerOneScore;
	delete playerTwoScore;
	delete ball;
	delete bg;
}

void Pong::Start()
{
	renderObjects.push_back(bg);
	gameObjects.push_back(playerOne);
	gameObjects.push_back(playerTwo);
	gameObjects.push_back(playerOneScore);
	gameObjects.push_back(playerTwoScore);
	gameObjects.push_back(ball);

	for (RenderObject* object : renderObjects)
	{
		object->Start();
	}

	for (GameObject* object : gameObjects)
	{
		object->Start();
	}

}

void Pong::Update(float deltaTime)
{
	for (GameObject* object : gameObjects)
	{
		if (object) { object->Update(deltaTime); }
	}
}

void Pong::Render(sf::RenderWindow* window)
{
	for (RenderObject* object : renderObjects)
	{
		if (object) { object->Render(window); }
	}

	for (GameObject* object : gameObjects)
	{
		if (object) { object->Render(window); }
	}
}

