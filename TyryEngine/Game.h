#pragma once
#include <string>
#include <memory>
#include "GameStateManager.h"
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include "State.h"

class Game
{
public:
	Game(std::string name, int screenWidth, int screenHeight, long gameDetails = 0);
	void Run(StatePtr state);
	GameStateManager &getGameStateManager();
	~Game();
	
private:
	void Loop();
	GameStateManager gsm;
	sf::RenderWindow *window;
};

