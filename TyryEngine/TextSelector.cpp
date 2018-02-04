#include "TextSelector.h"

TextSelector::TextSelector(sf::Vector2f position, sf::Vector2f size, sf::Font & font):
font(font), position(position), size(size)
{
	this->currentOption = 0;
	this->text.setFillColor(sf::Color::White);
	this->text.setFont(this->font);
}

void TextSelector::setTextDetails(sf::Text text)
{
	this->text = text;
}

void TextSelector::addOption(std::string option)
{
	sf::Text tmp(text);
	tmp.setPosition(position.x + 15, position.y + items.size() * text.getCharacterSize());
	tmp.setString(option);
	items.push_back(tmp);
}

int TextSelector::getSelectedPosition()
{
	return this->currentOption;
}

std::string TextSelector::getSelectedOption()
{
	return items.at(currentOption).getString();
}

void TextSelector::handleInput(sf::Event * event, InputManager &input)
{

}

void TextSelector::draw(sf::RenderWindow * window)
{
	for (auto &i : items) {
		window->draw(i);
	}
}
