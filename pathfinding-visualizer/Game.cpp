#include "game.h"
#include "Pong.h"
#include <iostream>

Game::Game()
	: renderWindow(new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "PONG")), clock{}
{
	renderWindow->setFramerateLimit(FRAME_RATE);
	InputManager::Instance = new InputManager();
}

Game::~Game()
{
	delete InputManager::Instance;
	InputManager::Instance = nullptr;
}

void Game::Init()
{
	SetLevel(std::shared_ptr<Pong> (new Pong()));
	IsRunning = true;
}

void Game::Input()
{
	sf::Event event;
	while (renderWindow->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			IsRunning = false;
		}

		InputManager::Instance->UpdateEvents(event);
	}

}

void Game::Update(float deltaTime)
{
	loadedLevel->Update(deltaTime);
}

void Game::Render(std::shared_ptr<sf::RenderWindow> window)
{
	renderWindow->clear(sf::Color::Black);
	loadedLevel->Render(renderWindow);
	renderWindow->display();
}

void Game::SetLevel(std::shared_ptr<Level> level)
{
	loadedLevel = level;
	loadedLevel->Start();
}

void Game::Run()
{
	if (!IsRunning)
	{
		Init();
	}

	clock.restart();
	float waitTime = 0.f;

	while (IsRunning)
	{
		float frameTime = clock.restart().asSeconds();
		waitTime += frameTime;

		Input();

		while (waitTime >= TIME_STEP)
		{
			Update(TIME_STEP);
			waitTime -= TIME_STEP;
		}

		Render(renderWindow);
	}
}

std::shared_ptr<Level> Game::GetLoadedLevel()
{
	if (loadedLevel)
	{
		return loadedLevel;
	}
}
