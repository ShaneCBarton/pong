#include "Pong.h"
#include "Paddle.h"
#include "Game.h"

Pong::Pong()
{
	playerOne = new Paddle(sf::Vector2f(10, HEIGHT / 2 - 50));
	playerTwo = new Paddle(sf::Vector2f(1280 - 40, HEIGHT / 2 - 50));
}

Pong::~Pong()
{
	delete playerOne;
	delete playerTwo;
}

void Pong::Start()
{
	gameObjects.push_back(playerOne);
	gameObjects.push_back(playerTwo);

	for (GameObject* object : gameObjects)
	{
		object->Start();
	}
}

void Pong::Input()
{
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
	for (GameObject* object : gameObjects)
	{
		if (object) { object->Render(window); }
	}
}

