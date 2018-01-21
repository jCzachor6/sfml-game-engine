#include "Game.h"


Game::Game(std::string name, int screenWidth, int screenHeight, long gameDetails)
{
	gsmPtr = std::make_shared<GameStateManager>();
	window = new sf::RenderWindow(sf::VideoMode(screenWidth, screenHeight), name, sf::Style::Default);
	window->setFramerateLimit(60);
}

void Game::Run(StatePtr state)
{
	gsmPtr->AddState(std::move(state));
	Loop();
}

GameStateManagerPtr & Game::getGsmPtr()
{
	return this->gsmPtr;
}

Game::~Game()
{
	delete this->window;
}

void Game::Loop()
{
	while (window->isOpen()) {
		gsmPtr->ProcessChanges();
		sf::Event event;
		while (window->pollEvent(event)) {
			gsmPtr->CurrentState()->HandleEvents(&event);
			if (sf::Event::Closed == event.type) {
				window->close();
			}
		}	
		gsmPtr->CurrentState()->Update(1.0f);
		window->clear();
		gsmPtr->CurrentState()->Render(window);
		window->display();
	}
}
