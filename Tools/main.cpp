#include <iostream>
#include "MenuState.h"
#include <TyryEngine\Game.h>


int main() {
	Game game("Tools", 1024, 786);
	game.Run(StatePtr(new MenuState()));
}