#pragma once
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics.hpp>

class GameObject
{

public:
	virtual void Start() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render(sf::RenderWindow* window) = 0;

protected:
	sf::Transformable transform;
	sf::CircleShape shape;
};

