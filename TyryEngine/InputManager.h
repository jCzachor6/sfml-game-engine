#pragma once
#include <SFML/Graphics.hpp>

class InputManager
{
public:
	bool IsSpritePressed(sf::Sprite object, sf::Mouse::Button button, sf::Event &ev);
	bool IsMouseOnSprite(sf::Sprite object);
	sf::Vector2i GetMousePosition();
	void SetMousePosition(sf::Vector2i *mousePos);
private:
	sf::Vector2i mousePosition;
};

