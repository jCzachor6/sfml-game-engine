#include "SplashState.h"


SplashState::SplashState()
{
	assetManager->LoadAllFromFile("SplashAssets.txt");
}

SplashState::~SplashState()
{
	assetManager->RemoveAll();
}

void SplashState::Init()
{
}

void SplashState::Cleanup()
{
}

void SplashState::OnPause()
{
}

void SplashState::OnResume()
{
}

void SplashState::HandleEvents()
{
}

void SplashState::Update(float deltaTime)
{
}

void SplashState::Render(sf::RenderWindow *window)
{
}
