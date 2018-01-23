#include "Game.h"

long State::idCounter = 0l;
Game::Game(std::string name, int screenWidth, int screenHeight, long gameDetails)
{
	window = new sf::RenderWindow(sf::VideoMode(screenWidth, screenHeight), name, sf::Style::Default);
	window->setFramerateLimit(60);
}

void Game::Run(StatePtr state)
{
	gsm.AddState(std::move(state));
	Loop();
}

GameStateManager & Game::getGameStateManager()
{
	return this->gsm;
}

Game::~Game()
{
	delete this->window;
}

void Game::Loop()
{
	while (window->isOpen()) {
		gsm.ProcessChanges();
		sf::Event event;
		while (window->pollEvent(event)) {
			gsm.CurrentState()->HandleEvents(&event);
			if (sf::Event::Closed == event.type) {
				window->close();
			}
		}	
		gsm.CurrentState()->Update(1.0f);
		window->clear();
		gsm.CurrentState()->Render(window);
		window->display();
	}
}
