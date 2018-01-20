#include "GameAgent.h"




void GameAgent::setTexture(sf::Texture & texture)
{
	this->sprite.setTexture(texture);
}

void GameAgent::setPosition(sf::Vector2f position)
{
	this->position = position;
	this->sprite.setPosition(position);
}

void GameAgent::draw(sf::RenderWindow * window)
{
	window->draw(sprite);
}
