#pragma once
#include <TyryEngine\State.h>
#include <memory>
#include <TyryEngine\StaticAgent.h>
#include <TyryEngine\Button.h>

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
	Button *buttonAdd;
	Button *buttonLoad;
	Button *buttonDelete;
};

