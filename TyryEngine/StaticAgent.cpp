#include "StaticAgent.h"

void StaticAgent::setTexture(sf::Texture & texture)
{
	this->sprite.setTexture(texture);
}

void StaticAgent::setPosition(sf::Vector2f position)
{
	this->position = position;
	this->sprite.setPosition(position);
}

void StaticAgent::draw(sf::RenderWindow * window)
{
	window->draw(sprite);
}
