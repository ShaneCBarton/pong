#include "game.h"
#include "Pong.h"
#include <iostream>

Game::Game()
	: renderWindow(new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "WINDOW")), clock{}
{
	renderWindow->setFramerateLimit(FRAME_RATE);
}

Game::~Game()
{
	delete renderWindow;
	delete loadedLevel;
}

void Game::Init()
{	
	SetLevel(new Pong());
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
	}
}

void Game::Update(float deltaTime)
{
	loadedLevel->Update(deltaTime);
	static int updateCount = 0;
	updateCount++;
	std::cout << "Update called: " << updateCount << std::endl;
}

void Game::Render(sf::RenderWindow* window)
{
	renderWindow->clear(sf::Color::Black);
	loadedLevel->Render(renderWindow);
	renderWindow->display();
}

void Game::SetLevel(Level* level)
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

Level* Game::GetLoadedLevel()
{
	if (loadedLevel)
	{
		return loadedLevel;
	}
}
