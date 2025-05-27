#pragma once
#include "RenderObject.h"
class Background :
    public RenderObject
{
public:
    Background();
    void Start() override;
    void Render(sf::RenderWindow* window) override;

private:
    sf::Vector2f position;
    std::vector<sf::RectangleShape> rects;
    int numberOfDashes{ 0 };
};

