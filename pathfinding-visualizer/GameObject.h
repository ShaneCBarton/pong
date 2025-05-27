#pragma once
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics.hpp>

class GameObject
{

public:
	virtual void Start() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render(std::shared_ptr<sf::RenderWindow> window) = 0;
	sf::FloatRect GetPosition() { return shape.getLocalBounds(); }

protected:
	sf::RectangleShape shape;
};

