#pragma once
#include <SFML\Graphics.hpp>
#include "InputManager.h"
#include <string>
#include <vector>

class TextSelector
{
public:
	TextSelector(sf::Vector2f position, sf::Vector2f size, sf::Font &font);
	void setTextDetails(sf::Text text);
	void addOption(std::string option);
	int getSelectedPosition();
	std::string getSelectedOption();

	void handleInput(sf::Event *event, InputManager &input);
	void draw(sf::RenderWindow *window);
private:
	std::vector<sf::Text> items;
	int currentOption;
	sf::Font &font;
	sf::Text text;
	sf::Vector2f position;
	sf::Vector2f size;
};

