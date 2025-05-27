#pragma once
#include "Level.h"
#include "Paddle.h"
#include "Score.h"
#include "Ball.h"
#include "Background.h"

class Pong : public Level
{

public:
	Pong();
	~Pong();

private:
	void Start() override;
	void Update(float deltaTime) override;
	void Render(std::shared_ptr<sf::RenderWindow> window) override;

	std::unique_ptr<Paddle> playerOne;
	std::unique_ptr<Paddle> playerTwo;
	std::unique_ptr<Score> playerOneScore;
	std::unique_ptr<Score> playerTwoScore;
	std::unique_ptr<Ball> ball;
	std::unique_ptr<Background> bg;
};

