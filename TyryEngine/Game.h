#pragma once
#include <string>
#include <memory>
#include "GameStateManager.h"
#include <SFML\Window.hpp>

typedef std::shared_ptr<GameStateManager> GameStateManagerPtr;
class Game
{
public:
	Game(std::string name, int screenWidth, int screenHeight, long gameDetails = 0);
	void Run(StatePtr state);
	GameStateManagerPtr &getGsmPtr();
	~Game();
	
private:
	void Loop();
	GameStateManagerPtr gsmPtr;
	sf::RenderWindow *window;
};

