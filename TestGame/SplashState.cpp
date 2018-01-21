#include "SplashState.h"


SplashState::SplashState(GameStateManagerPtr gsm)
{
	this->gsmPtr = gsm;
	assetManager->LoadAllFromFile("SplashAssets.tea");
	std::cout << "On construct" << std::endl;
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

	idText.setFont(assetManager->GetFont("Pixeled.ttf"));
	idText.setCharacterSize(30);
	idText.setPosition(300, 300);
	idText.setFillColor(sf::Color::White);
	idText.setString(std::to_string(id));

}

void SplashState::Cleanup()
{
	std::cout << "On cleanup" << std::endl;
	gameAgentList.clear();
	assetManager->RemoveAll();
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
	if (event->type == sf::Event::KeyPressed) {
		if (event->key.code == sf::Keyboard::A) {
			gsmPtr->AddState(StatePtr(new SplashState(gsmPtr)));
			gsmPtr->AddState(StatePtr(new SplashState(gsmPtr)));
			gsmPtr->AddState(StatePtr(new SplashState(gsmPtr)));
			gsmPtr->AddState(StatePtr(new SplashState(gsmPtr)));
		}
		if (event->key.code == sf::Keyboard::D) {
			gsmPtr->DeleteState();
		}
		if (event->key.code == sf::Keyboard::R) {
			gsmPtr->ReplaceState(StatePtr(new SplashState(gsmPtr)));
		}
	}
}

void SplashState::Update(float deltaTime)
{
}

void SplashState::Render(sf::RenderWindow *window)
{
	window->draw(idText);
	for (auto &i : gameAgentList) {
		i->draw(window);
	}
}
