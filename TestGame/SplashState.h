#pragma once
#include <TyryEngine\State.h>
#include <SFML\Window.hpp>

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

};

