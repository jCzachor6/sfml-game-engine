#include "MenuState.h"



MenuState::MenuState()
{
	assetManager->LoadAssetsFromFile("MenuStateAssets.te");
}

void MenuState::Init()
{
	background = new StaticAgent(assetManager->GetTexture("MenuScreen.png"), sf::Vector2f(0, 0));
}

void MenuState::Cleanup()
{
	delete background;
}

void MenuState::OnPause()
{
}

void MenuState::OnResume()
{
}

void MenuState::HandleEvents(sf::Event * event)
{
}

void MenuState::Update(float deltaTime)
{
}

void MenuState::Render(sf::RenderWindow * window)
{
	background->draw(window);
}
