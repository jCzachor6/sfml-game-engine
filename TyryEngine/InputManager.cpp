#include "InputManager.h"

bool InputManager::IsSpritePressed(sf::Sprite object, sf::Mouse::Button button, sf::Vector2i &mousePosition, sf::Event & ev)
{
	sf::IntRect tempRect(
		object.getPosition().x,
		object.getPosition().y,
		object.getGlobalBounds().width,
		object.getGlobalBounds().height);

	if (ev.type == sf::Event::MouseButtonPressed &&
		ev.key.code == button) {
		return (tempRect.contains(mousePosition));
	}
	return false;
}

bool InputManager::IsMouseOnSprite(sf::Sprite object, sf::Vector2i &mousePosition)
{
	sf::IntRect tempRect(
		object.getPosition().x,
		object.getPosition().y,
		object.getGlobalBounds().width,
		object.getGlobalBounds().height);
	return tempRect.contains(mousePosition);
}

sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow & window)
{
	return sf::Mouse::getPosition(window);
}

void InputManager::SetMousePosition(sf::Vector2i *mousePos)
{
	this->mousePosition = *mousePos;
}
