#include <iostream>
#include "SplashState.h"
#include <TyryEngine\Game.h>


int main() {
	Game game("", 800, 600);
	game.Run(StatePtr(new SplashState()));
}