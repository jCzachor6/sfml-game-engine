#pragma once
#include <stack>
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
	std::stack<StatePtr> stateStack;
	StatePtr stateToBeAdded;
	bool isDeleting;
	bool isAdding;
	bool isReplacing;
};

