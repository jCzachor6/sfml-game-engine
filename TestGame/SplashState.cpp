#include "SplashState.h"


SplashState::SplashState(GameStateManagerPtr gsm)
{
	this->gsmPtr = gsm;
	assetManager->LoadAllFromFile("SplashAssets.tea");
}

SplashState::~SplashState()
{
	assetManager->RemoveAll();
}

void SplashState::Init()
{
	gameAgentList.push_back(agent(
		new tileTest(assetManager->GetTexture("circle.png"), sf::Vector2f(100, 100))));
	gameAgentList.push_back(agent(
		new tileTest(assetManager->GetTexture("cross.png"), sf::Vector2f(150, 150))));
	gameAgentList.push_back(agent(
		new tileTest(assetManager->GetTexture("empty.png"), sf::Vector2f(200, 200))));
	gameAgentList.push_back(agent(
		new tileTest(assetManager->GetTexture("selected.png"), sf::Vector2f(250, 250))));
}

void SplashState::Cleanup()
{
	gameAgentList.clear();
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
	for (auto &i : gameAgentList) {
		i->draw(window);
	}
}
