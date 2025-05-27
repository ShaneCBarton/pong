#pragma once
#include <SFML/Graphics.hpp>

class RenderObject
{

public:
	virtual void Start() = 0;
	virtual void Render(std::shared_ptr<sf::RenderWindow> window) = 0;

protected:
	sf::RectangleShape shape;
};

