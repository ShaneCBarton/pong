#include "Score.h"
#include <iostream>

Score::Score(sf::Vector2f startPosition)
	: position{ startPosition }, score{ 0 }
{
	InitScore();
}

void Score::InitScore()
{
	scoreFont.loadFromFile("fonts/Gameplay.ttf");
	scoreText.setFont(scoreFont);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setString("0");
	scoreText.setCharacterSize(50);
	sf::FloatRect bounds = scoreText.getLocalBounds();
	scoreText.setOrigin(bounds.left + bounds.width / 2, bounds.top + bounds.height / 2);
}

void Score::Start()
{
	scoreText.setPosition(position);
}

void Score::Update(float deltaTime)
{
	scoreText.setString(std::to_string(score));
}

void Score::Render(sf::RenderWindow* renderWindow)
{
	renderWindow->draw(scoreText);
}
