#pragma once
#include <TyryEngine\State.h>
#include <SFML\Window.hpp>
#include <TyryEngine\StaticAgent.h>
#include "tileTest.h"
#include <list>
#include <TyryEngine\Game.h>

typedef std::unique_ptr<StaticAgent> agent;
class SplashState : public State
{
public:
	SplashState(GameStateManagerPtr gsm);

	void Init();
	void Cleanup();

	void OnPause();
	void OnResume();

	void HandleEvents(sf::Event *event);
	void Update(float deltaTime);
	void Render(sf::RenderWindow *window);
private:
	std::list<agent> gameAgentList;
	GameStateManagerPtr gsmPtr;
};

