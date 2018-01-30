#pragma once
#include <TyryEngine\State.h>
#include <memory>
#include <TyryEngine\StaticAgent.h>

class MenuState : public State
{
public:
	MenuState();
	void Init();
	void Cleanup();

	void OnPause();
	void OnResume();

	void HandleEvents(sf::Event *event);
	void Update(float deltaTime);
	void Render(sf::RenderWindow *window);

private:
	StaticAgent *background;
};

