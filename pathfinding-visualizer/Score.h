#pragma once
#include "GameObject.h"

class Score :
    public GameObject
{
public:
    Score(sf::Vector2f startPosition);
    void Start() override;
    void Update(float deltaTime) override;
    void Render(std::shared_ptr<sf::RenderWindow> renderWindow) override;

private:
    void InitScore();
    sf::Vector2f position;
    sf::Text scoreText;
    sf::Font scoreFont;
    int score;
};

