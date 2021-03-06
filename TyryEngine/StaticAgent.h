#pragma once
#include <SFML\Graphics.hpp>
#include <SFML/Window.hpp>

class StaticAgent
{
public:
	StaticAgent();
	StaticAgent(sf::Texture &texture, sf::Vector2f position);
	virtual void draw(sf::RenderWindow *window);
protected:
	void setTexture(sf::Texture  &texture);
	void setPosition(sf::Vector2f position);
	sf::Sprite sprite;
	sf::Vector2f position;
private:
};

