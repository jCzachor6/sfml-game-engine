#pragma once
#include "AssetManager.h"
#include "GameStateManager.h"
#include "InputManager.h"
#include <memory>

class GameStateManager;
class State
{
public:
	friend GameStateManager;
	State();
	virtual void Init() = 0;
	virtual void Cleanup() = 0;

	virtual void OnPause() {};
	virtual void OnResume() {};

	virtual void HandleEvents(sf::Event *event) = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render(sf::RenderWindow *window) = 0;
	static long idCounter;
	long getID();
protected:
	const long id;
	std::unique_ptr<AssetManager> assetManager;
	GameStateManager &getGameStateManager();
	InputManager &getInputManager();
private:
	GameStateManager *gsmPtr;
	InputManager *inputPtr;
};
