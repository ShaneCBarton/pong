#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Ball :
    public GameObject
{

public:
    Ball(sf::Vector2f startPosition);
    void Start() override;
    void Update(float deltaTime) override;
    void Render(std::shared_ptr<sf::RenderWindow> window) override;

private:
    sf::RectangleShape shape;
    sf::Vector2f position;
    float moveSpeed;
};

