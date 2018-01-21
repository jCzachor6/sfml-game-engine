#include "SplashState.h"


SplashState::SplashState(GameStateManagerPtr gsm)
{
	this->gsmPtr = gsm;
	assetManager->LoadAllFromFile("SplashAssets.tea");
	std::cout << "On construct" << std::endl;
}

SplashState::~SplashState()
{
	assetManager->RemoveAll();
	std::cout << "On desctruct" << std::endl;
}

void SplashState::Init()
{
	std::cout << "On init" << std::endl;
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
	std::cout << "On cleanup" << std::endl;
	gameAgentList.clear();
}

void SplashState::OnPause()
{
	std::cout << "On pause" << std::endl;
}

void SplashState::OnResume()
{
	std::cout << "On resume" << std::endl;
}

void SplashState::HandleEvents(sf::Event *event)
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
