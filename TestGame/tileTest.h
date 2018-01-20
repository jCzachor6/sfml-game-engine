#pragma once
#include <TyryEngine\GameAgent.h>
#include <SFML\Graphics.hpp>

class tileTest : public GameAgent
{
public:
	tileTest(sf::Texture &texture, sf::Vector2f pos);
	~tileTest();
};

