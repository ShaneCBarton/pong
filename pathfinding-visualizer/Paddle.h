#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"


class Paddle :
    public GameObject
{

public:
    Paddle(sf::Vector2f startPosition, sf::Keyboard::Key upKey, sf::Keyboard::Key downKey);
    void Start() override;
    void Update(float deltaTime) override;
    void Render(std::shared_ptr<sf::RenderWindow> window) override;

private:
    void HandleInput(float deltaTime);
    sf::RectangleShape shape;
    sf::Vector2f position;
    sf::Keyboard::Key upKey;
    sf::Keyboard::Key downKey;
    float moveSpeed;
};

