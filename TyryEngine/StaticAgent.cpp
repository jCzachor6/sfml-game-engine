#include "StaticAgent.h"

StaticAgent::StaticAgent()
{
}

StaticAgent::StaticAgent(sf::Texture & texture, sf::Vector2f position)
{
	this->sprite.setTexture(texture);
	this->position = position;
	this->sprite.setPosition(position);
}

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
