#pragma once
#include <TyryEngine\State.h>
#include <TyryEngine\GameStateManager.h>
#include <SFML\Window.hpp>

class SplashState : public State
{
public:
	SplashState(GameStateManager *gsm, sf::RenderWindow *window);
	~SplashState();

	void Init();
	void Cleanup();

	void OnPause();
	void OnResume();

	void HandleEvents();
	void Update();
	void Render();

private:
	GameStateManager *gsm;
	sf::RenderWindow *window;
};

