#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "RenderObject.h"

class Level
{

public:
	virtual void Start() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render(std::shared_ptr<sf::RenderWindow> window) = 0;

protected:
	std::vector<std::unique_ptr<GameObject>> gameObjects;
	std::vector<std::unique_ptr<RenderObject>> renderObjects;
};

