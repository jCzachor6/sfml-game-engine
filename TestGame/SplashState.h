#pragma once
#include <TyryEngine\State.h>
#include <SFML\Window.hpp>
#include <TyryEngine\StaticAgent.h>
#include "tileTest.h"
#include <list>
#include <TyryEngine\Game.h>
#include <vector>

typedef std::unique_ptr<StaticAgent> agent;
class SplashState : public State
{
public:
	SplashState();

	void Init();
	void Cleanup();

	void OnPause();
	void OnResume();

	void HandleEvents(sf::Event *event);
	void Update(float deltaTime);
	void Render(sf::RenderWindow *window);
private:
	std::list<agent> gameAgentList;
	sf::Text idText;
	std::vector<long> *stateIds;
	std::vector<sf::Text> idTexts;
};

