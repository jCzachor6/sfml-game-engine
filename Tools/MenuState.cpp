#include "MenuState.h"



MenuState::MenuState()
{
	assetManager->LoadAssetsFromFile("MenuStateAssets.te");
}

void MenuState::Init()
{
	background = new StaticAgent(assetManager->GetTexture("MenuScreen.png"), sf::Vector2f(0, 0));
	buttonAdd = new Button(sf::Vector2f(761, 314), assetManager->GetTexture("ic_add2.png"));
	buttonLoad = new Button(sf::Vector2f(761, 351), assetManager->GetTexture("ic_load2.png"));
	buttonDelete = new Button(sf::Vector2f(761, 388), assetManager->GetTexture("ic_delete2.png"));
	textSelector = new TextSelector(sf::Vector2f(250, 320), sf::Vector2f(500, 250), assetManager->GetFont("Dhurjati.ttf"));
	textSelector->addOption("option1");
	textSelector->addOption("option2");
	textSelector->addOption("option3");
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
	buttonAdd->handleInput(event, getInputManager());
	buttonLoad->handleInput(event, getInputManager());
	buttonDelete->handleInput(event, getInputManager());
	textSelector->handleInput(event, getInputManager());
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
	textSelector->draw(window);
}
