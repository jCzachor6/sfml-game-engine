#pragma once
#include <SFML\Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class GameAgent
{
public:
	void setTexture(sf::Texture  &texture);
	void setPosition(sf::Vector2f position);
	virtual void draw(sf::RenderWindow *window);
private:
	sf::Sprite sprite;
	sf::Vector2f position;
};

