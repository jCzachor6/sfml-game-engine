#pragma once
#include <TyryEngine\State.h>
#include <SFML\Window.hpp>
#include <TyryEngine\GameAgent.h>
#include "tileTest.h"
#include <list>

typedef std::unique_ptr<GameAgent> agent;
class SplashState : public State
{
public:
	SplashState();
	~SplashState();

	void Init();
	void Cleanup();

	void OnPause();
	void OnResume();

	void HandleEvents();
	void Update(float deltaTime);
	void Render(sf::RenderWindow *window);
private:
	std::list<agent> gameAgentList;
};

