#include "InputManager.h"

InputManager* InputManager::Instance = nullptr;

void InputManager::UpdateEvents(const sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		keyStates[event.key.code] = true;
	}
	else if (event.type == sf::Event::KeyReleased)
	{
		keyStates[event.key.code] = false;
	}
}

bool InputManager::IsKeypressed(sf::Keyboard::Key key)
{
	return keyStates[key];
}

bool InputManager::IsKeyReleased(sf::Keyboard::Key key)
{
	return !keyStates[key];
}
