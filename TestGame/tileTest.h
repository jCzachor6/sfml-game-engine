#pragma once
#include <TyryEngine\StaticAgent.h>
#include <SFML\Graphics.hpp>

class tileTest : public StaticAgent
{
public:
	tileTest(sf::Texture &texture, sf::Vector2f pos);
	~tileTest();
};

