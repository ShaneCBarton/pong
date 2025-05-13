#pragma once
#include <SFML/Graphics.hpp>
#include "Level.h"

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
	Level* GetLoadedLevel();

private:
	void Init();
	void Input();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	void SetLevel(Level* level);

	sf::RenderWindow* renderWindow;
	sf::Clock clock;
	bool IsRunning{ false };
	Level* loadedLevel{ nullptr };
};