#include "MenuState.h"



MenuState::MenuState()
{
	assetManager->LoadAssetsFromFile("MenuStateAssets.te");
}

void MenuState::Init()
{
	background = new StaticAgent(assetManager->GetTexture("MenuScreen.png"), sf::Vector2f(0, 0));
	buttonAdd = new Button(sf::Vector2f(100, 100), assetManager->GetTexture("ic_add2.png"));
	buttonLoad = new Button(sf::Vector2f(150, 100), assetManager->GetTexture("ic_load2.png"));
	buttonDelete = new Button(sf::Vector2f(200, 100), assetManager->GetTexture("ic_delete2.png"));
}

void MenuState::Cleanup()
{
	delete background;
	delete buttonAdd;
	delete buttonLoad;
	delete buttonDelete;
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
	buttonAdd->draw(window);
	buttonLoad->draw(window);
	buttonDelete->draw(window);
}
