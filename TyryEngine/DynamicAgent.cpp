#include "DynamicAgent.h"

DynamicAgent::DynamicAgent()
{
	this->movement = sf::Vector2f(0, 0);
}

void DynamicAgent::update(float deltaTime)
{
	this->position += movement;
	sprite.setPosition(this->position);
}
