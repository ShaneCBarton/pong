#pragma once
#include "Level.h"
#include "Paddle.h"

class Pong : public Level
{

public:
	Pong();
	~Pong();

private:
	void Start() override;
	void Input() override;
	void Update(float deltaTime) override;
	void Render(sf::RenderWindow* window) override;

	Paddle* playerOne;
	Paddle* playerTwo;
};

