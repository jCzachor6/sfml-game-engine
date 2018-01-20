#pragma once
#include "AssetManager.h"
#include <memory>

class State
{
public:
	State();
	virtual void Init() = 0;
	virtual void Cleanup() = 0;

	virtual void OnPause() {};
	virtual void OnResume() {};

	virtual void HandleEvents() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render(sf::RenderWindow *window) = 0;
protected:
	std::unique_ptr<AssetManager> assetManager;
private:
	
};
