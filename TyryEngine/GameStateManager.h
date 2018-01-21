#pragma once
#include <stack>
#include <queue>
#include <memory>
#include "State.h"


typedef std::unique_ptr<State> StatePtr;



class GameStateManager
{
public:
	GameStateManager();
	void AddState(StatePtr state);
	void ReplaceState(StatePtr state);
	void DeleteState();
	void ProcessChanges();
	StatePtr &CurrentState();
private:
	struct tmpState {
		bool isDeleting;
		bool isAdding;
		bool isReplacing;
		StatePtr stateToBeAdded;
	};

	std::stack<StatePtr> stateStack;
	std::queue<tmpState> statesToBeAdded;
	StatePtr stateToBeAdded;
	bool isDeleting;
	bool isAdding;
	bool isReplacing;

	
};
