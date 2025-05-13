#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"


class Paddle :
    public GameObject
{

public:
    Paddle(sf::Vector2f startPosition);
    void Start() override;
    void Update(float deltaTime) override;
    void Render(sf::RenderWindow* window) override;

private:
    sf::RectangleShape shape;
    sf::Vector2f position;
};

