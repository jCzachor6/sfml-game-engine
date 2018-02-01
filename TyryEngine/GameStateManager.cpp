#include "GameStateManager.h"



GameStateManager::GameStateManager()
{
	this->isPuttingOnTop = false;
	this->stateToPutOnTop = -1;
	inputPtr = new InputManager();
}

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
	if (isPuttingOnTop) {
		std::stack<StatePtr> tmpStack;
		while (stateStack.top()->getID() != stateToPutOnTop) {
			tmpStack.push(std::move(stateStack.top()));
			stateStack.pop();
		}
		statesToBeAdded.push(tmpState{
			false,
			true,
			false,
			std::move(stateStack.top())
			});
		stateStack.pop();
		while (!tmpStack.empty()) {
			stateStack.push(std::move(tmpStack.top()));
			tmpStack.pop();
		}
		isPuttingOnTop = false;
		stateToPutOnTop = -1;
	}

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
			statesToBeAdded.front().stateToBeAdded->inputPtr = inputPtr;
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
	if(stateStack.top()->getID() != id && isPuttingOnTop == false){
		for (const auto &i : stateIds) {
			if (i == id) {
				this->isPuttingOnTop = true;
				this->stateToPutOnTop = id;
				removeIdFromStateIds(id);
			}
		}
	}
}

StatePtr & GameStateManager::CurrentState()
{
	return this->stateStack.top();
}

void GameStateManager::removeIdFromStateIds(long id)
{
	for (int i = 0; i < stateIds.size(); i++) {
		if (stateIds.at(i) == id) {
			stateIds.erase(stateIds.begin() + i);
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

void GameStateManager::setInputManager(InputManager * im)
{
	this->inputPtr = im;
}
