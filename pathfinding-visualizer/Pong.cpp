#include "Pong.h"
#include "Paddle.h"
#include "Game.h"

Pong::Pong()
{
	playerOne = new Paddle(sf::Vector2f(10, HEIGHT / 2 - 50));
	playerTwo = new Paddle(sf::Vector2f(1280 - 40, HEIGHT / 2 - 50));

	playerOneScore = new Score(sf::Vector2f(WIDTH / 4, 100));
	playerTwoScore = new Score(sf::Vector2f(WIDTH / 4, 100));
}

Pong::~Pong()
{
	delete playerOne;
	delete playerTwo;
	delete playerOneScore;
	delete playerTwoScore;
}

void Pong::Start()
{
	gameObjects.push_back(playerOne);
	gameObjects.push_back(playerTwo);
	gameObjects.push_back(playerOneScore);
	gameObjects.push_back(playerTwoScore);

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

