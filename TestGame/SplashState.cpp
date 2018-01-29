#include "SplashState.h"


SplashState::SplashState()
{
	assetManager->LoadAssetsFromFile("SplashAssets.tea");
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
	gameAgentList.clear();
	assetManager->RemoveAll();
}

void SplashState::OnPause()
{
}

void SplashState::OnResume()
{
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
		if (event->key.code == sf::Keyboard::Num1) {
			getGameStateManager().PutOnTop(1);
		}
		if (event->key.code == sf::Keyboard::Num2) {
			getGameStateManager().PutOnTop(2);
		}
		if (event->key.code == sf::Keyboard::Num3) {
			getGameStateManager().PutOnTop(3);
		}
		if (event->key.code == sf::Keyboard::Num4) {
			getGameStateManager().PutOnTop(4);
		}
		if (event->key.code == sf::Keyboard::Num5) {
			getGameStateManager().PutOnTop(5);
		}
		if (event->key.code == sf::Keyboard::Num6) {
			getGameStateManager().PutOnTop(6);
		}
		if (event->key.code == sf::Keyboard::Num7) {
			getGameStateManager().PutOnTop(7);
		}
		if (event->key.code == sf::Keyboard::Num8) {
			getGameStateManager().PutOnTop(8);
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
