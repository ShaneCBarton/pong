#pragma once
#include "RenderObject.h"
class Background :
    public RenderObject
{
public:
    Background();
    void Start() override;
    void Render(std::shared_ptr<sf::RenderWindow> window) override;

private:
    sf::Vector2f position;
    std::vector<sf::RectangleShape> rects;
    int numberOfDashes{ 0 };
};

