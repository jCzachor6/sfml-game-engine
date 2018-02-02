#pragma once
#include "StaticAgent.h"
#include <SFML/Graphics.hpp>
#include <functional>
#include "InputManager.h"
#include "teError.h"

inline void defaultOnClick() {
	fatalError("Button method not initialized!");
}

class Button : public StaticAgent
{
public:
	Button(sf::Vector2f position, sf::Texture &texture);
	void handleInput(sf::Event *event, InputManager &im);
	void setOnClick(std::function<void()> onClick);
private:
	std::function<void()> onClick;
};

