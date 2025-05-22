#pragma once
#include "Level.h"
#include "Paddle.h"
#include "Score.h"
#include "Ball.h"

class Pong : public Level
{

public:
	Pong();
	~Pong();

private:
	void Start() override;
	void Update(float deltaTime) override;
	void Render(sf::RenderWindow* window) override;

	Paddle* playerOne;
	Paddle* playerTwo;
	Score* playerOneScore;
	Score* playerTwoScore;
	Ball* ball;
};

