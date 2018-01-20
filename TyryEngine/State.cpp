#include "State.h"

State::State()
{
	assetManager = std::unique_ptr<AssetManager>(new AssetManager);
}


