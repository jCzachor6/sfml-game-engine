#pragma once
#include <stack>
#include <queue>
#include <vector>
#include <memory>
#include "State.h"

class State;
typedef std::unique_ptr<State> StatePtr;
class GameStateManager
{
public:
	GameStateManager();
	void AddState(StatePtr state);
	void ReplaceState(StatePtr state);
	void DeleteState();
	void ProcessChanges();
	void PutOnTop(long id);
	StatePtr &CurrentState();
	std::vector<long> *getStateIds();
private:
	struct tmpState {
		bool isDeleting;
		bool isAdding;
		bool isReplacing;
		StatePtr stateToBeAdded;
	};
	bool isPuttingOnTop;
	int stateToPutOnTop;
	std::vector<long> stateIds;
	std::stack<StatePtr> stateStack;
	std::queue<tmpState> statesToBeAdded;	
	void removeIdFromStateIds(long id);
	bool checkIfExists(long id);

};
