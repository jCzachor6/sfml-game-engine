#include "GameStateManager.h"



void GameStateManager::AddState(StatePtr state)
{
	statesToBeAdded.push(tmpState{
		false,
		true,
		false,
		std::move(state)
		});
}

void GameStateManager::ReplaceState(StatePtr state)
{
	statesToBeAdded.push(tmpState{
		false,
		true,
		true,
		std::move(state)
		});
}

void GameStateManager::DeleteState()
{
	statesToBeAdded.push(tmpState{
		true,
		false,
		false
		});
}

void GameStateManager::ProcessChanges()
{
	while (!statesToBeAdded.empty()) {

		if (statesToBeAdded.front().isDeleting
			&& this->stateStack.size() > 1) 
		{
			this->stateStack.top()->Cleanup();
			removeIdFromStateIds(this->stateStack.top()->getID());
			this->stateStack.pop();
			this->stateStack.top()->OnResume();
		}

		if (statesToBeAdded.front().isAdding) {
			if (!this->stateStack.empty()) {
				if (statesToBeAdded.front().isReplacing) {
					this->stateStack.top()->Cleanup();
					removeIdFromStateIds(this->stateStack.top()->getID());
					this->stateStack.pop();
				}else {
					this->stateStack.top()->OnPause();
				}
			}
			statesToBeAdded.front().stateToBeAdded->gsmPtr = this;
			this->stateStack
				.push(std::move(statesToBeAdded.front().stateToBeAdded));
			this->stateStack.top()->Init();
			stateIds.push_back(this->stateStack.top()->getID());
		}
		statesToBeAdded.pop();
	}
}

void GameStateManager::PutOnTop(long id)
{
	//todo
}

StatePtr & GameStateManager::CurrentState()
{
	return this->stateStack.top();
}

void GameStateManager::removeIdFromStateIds(long id)
{
	for (int i = 0; i < stateIds.size(); i++) {
		if (stateIds.at(i) == id) {
			stateIds.at(i) = stateIds.at(stateIds.size()-1);
			stateIds.pop_back();
		}
	}
}

bool GameStateManager::checkIfExists(long id)
{
	for (int i = 0; i < stateIds.size(); i++) {
		if (stateIds.at(i) == id) {
			return true;
		}
	}
	return false;
}

std::vector<long>* GameStateManager::getStateIds()
{
	return &this->stateIds;
}
