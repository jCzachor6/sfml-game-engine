#include "State.h"

State::State() :
	id(idCounter)
{
	idCounter++;
	assetManager = std::unique_ptr<AssetManager>(new AssetManager);
}

long State::getID()
{
	return this->id;
}

GameStateManager & State::getGameStateManager()
{
	return *this->gsmPtr;
}

InputManager & State::getInputManager()
{
	return *this->inputPtr;
}



