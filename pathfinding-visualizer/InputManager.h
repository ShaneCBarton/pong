#pragma once
#include <SFML/Window.hpp>
#include <unordered_map>

class InputManager
{
public:
	static InputManager* Instance;
	
	void UpdateEvents(const sf::Event& event);
	bool IsKeypressed(sf::Keyboard::Key key);
	bool IsKeyReleased(sf::Keyboard::Key key);

private:
	std::unordered_map<sf::Keyboard::Key, bool > keyStates;
};

