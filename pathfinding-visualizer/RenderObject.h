#pragma once
#include <SFML/Graphics.hpp>

class RenderObject
{

public:
	virtual void Start() = 0;
	virtual void Render(sf::RenderWindow* window) = 0;

protected:
	sf::RectangleShape shape;
};

