#pragma once
#include <string>
#include <memory>
#include "GameStateManager.h"
#include "State.h"
#include <SFML\Window.hpp>


class Game
{
public:
	Game(std::string name, int screenWidth, int screenHeight, long gameDetails = 0);
	void Run(StatePtr state);
	~Game();
	
private:
	void Loop();
	GameStateManager gsm;
	sf::RenderWindow *window;
};

