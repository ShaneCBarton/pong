#pragma once
#include <SFML/Graphics.hpp>
#include "Level.h"
#include "InputManager.h"

#define WIDTH 1280
#define HEIGHT 720
#define FRAME_RATE 60
#define TIME_STEP 1.f / FRAME_RATE

class Game
{
public:
	Game();
	~Game();
	void Run();
	std::shared_ptr<Level> GetLoadedLevel();

private:
	void Init();
	void Input();
	void Update(float deltaTime);
	void Render(std::shared_ptr<sf::RenderWindow> window);
	void SetLevel(std::shared_ptr<Level> level);

	std::shared_ptr<sf::RenderWindow> renderWindow;
	std::shared_ptr<Level> loadedLevel{ nullptr };
	sf::Clock clock;
	bool IsRunning{ false };
};