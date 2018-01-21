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
		false,
		nullptr
		});
}

void GameStateManager::ProcessChanges()
{
	while (!statesToBeAdded.empty()) {

		if (statesToBeAdded.front().isDeleting
			&& !this->stateStack.empty()) 
		{
			this->stateStack.top()->Cleanup();
			this->stateStack.pop();
			if (!this->stateStack.empty()) {
				this->stateStack.top()->OnResume();
			}
			statesToBeAdded.pop();
		}

		if (statesToBeAdded.front().isAdding) {
			if (!this->stateStack.empty()) {
				if (statesToBeAdded.front().isReplacing) {
					this->stateStack.top()->Cleanup();
					this->stateStack.pop();
				}else {
					this->stateStack.top()->OnPause();
				}
			}
			this->stateStack
				.push(std::move(statesToBeAdded.front().stateToBeAdded));
			this->stateStack.top()->Init();
			statesToBeAdded.pop();
		}
	}
}

StatePtr & GameStateManager::CurrentState()
{
	return this->stateStack.top();
}
