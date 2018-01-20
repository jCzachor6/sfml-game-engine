#pragma once
#include "StaticAgent.h"

class DynamicAgent : public StaticAgent
{
public:
	DynamicAgent();
	virtual void update(float deltaTime);
private:
	sf::Vector2f movement;
};

