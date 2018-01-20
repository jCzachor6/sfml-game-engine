#include "State.h"

State::State()
{
	assetManager = std::unique_ptr<AssetManager>(new AssetManager);
}

void State::drawAgents(sf::RenderWindow * window)
{
	for (auto &i: gameAgentList) {
		i->draw(window);
	}
}
