#include "GameStateManager.h"



GameStateManager::GameStateManager()
{
	this->isDeleting = false;
	this->isAdding = false;
	this->isReplacing = false;
}

void GameStateManager::AddState(StatePtr state)
{
	this->isAdding = true;
	this->stateToBeAdded = std::move(state);
}

void GameStateManager::ReplaceState(StatePtr state)
{
	this->isAdding = true;
	this->isReplacing = isReplacing;
	this->stateToBeAdded = std::move(state);
}

void GameStateManager::DeleteState()
{
	this->isDeleting = true;
}

void GameStateManager::ProcessChanges()
{
	if (this->isDeleting && !this->stateStack.empty()) {
		this->stateStack.top()->Cleanup();
		this->stateStack.pop();
		if (!this->stateStack.empty()) {
			this->stateStack.top()->OnResume();
		}
		this->isDeleting = false;
	}
	if (this->isAdding) {
		if (!this->stateStack.empty()) {
			if (this->isReplacing) {
				this->stateStack.top()->Cleanup();
				this->stateStack.pop();
			}
			else {
				this->stateStack.top()->OnPause();
			}
		}
		this->stateStack.push(std::move(this->stateToBeAdded));
		this->stateStack.top()->Init();
		this->isAdding = false;
	}
}

StatePtr & GameStateManager::CurrentState()
{
	return this->stateStack.top();
}
