#include "Score.h"

Score::Score(sf::Vector2f startPosition)
	: position{startPosition}
{
	InitScore();
}

void Score::InitScore()
{
	scoreFont.loadFromFile("D:/Repos/pong/fonts/Gameplay.ttf");
	scoreText.setFont(scoreFont);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setString("0");
}

void Score::Start()
{

}

void Score::Update(float deltaTime)
{
}

void Score::Render(sf::RenderWindow* renderWindow)
{
	renderWindow->draw(scoreText);
}
