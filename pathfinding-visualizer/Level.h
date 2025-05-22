#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Level
{

public:
	virtual void Start() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render(sf::RenderWindow* window) = 0;

protected:
	std::vector<GameObject*> gameObjects;
	std::vector<RenderObject*> renderObjects;
};

