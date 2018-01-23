#include "SplashState.h"


SplashState::SplashState()
{
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

	this->stateIds = getGameStateManager().getStateIds();
	for (int i = 0; i < 10; i++) {
		sf::Text text;
		text.setFont(assetManager->GetFont("Pixeled.ttf"));
		text.setCharacterSize(30);
		text.setPosition(700, 50*i + 50);
		text.setFillColor(sf::Color::White);
		idTexts.push_back(text);
	}
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
			getGameStateManager().AddState(StatePtr(new SplashState()));
		}
		if (event->key.code == sf::Keyboard::D) {
			getGameStateManager().DeleteState();
		}
		if (event->key.code == sf::Keyboard::R) {
			getGameStateManager().ReplaceState(StatePtr(new SplashState()));
		}
	}
}

void SplashState::Update(float deltaTime)
{
	for (int i = 0; i < stateIds->size(); i++) {
		int val = stateIds->at(i);
		if (i < 10) {
			idTexts.at(i).setString(std::to_string(val));
		}
	}
}

void SplashState::Render(sf::RenderWindow *window)
{
	window->draw(idText);
	for (auto &i : gameAgentList) {
		i->draw(window);
	}
	for (auto &i : idTexts) {
		window->draw(i);
	}
}
