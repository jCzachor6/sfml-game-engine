#include "Button.h"

Button::Button(sf::Vector2f position, sf::Texture & texture)
	:StaticAgent(texture, position)
{
	this->onClick = defaultOnClick;
}

void Button::handleInput(sf::Event *event, InputManager &im)
{
	if (im.IsSpritePressed(this->sprite, sf::Mouse::Button::Left, *event)) {
		this->onClick();
	}
}

void Button::setOnClick(std::function<void()> onClick)
{
	this->onClick = onClick;
}

