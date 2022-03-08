#include "GameOverText.h"
#include "GameScene.h"
#include <sstream>

GameOverText::GameOverText() {
	text_.setFont(GAME.getFont("Resources/Courneuf-Regular.ttf"));
	text_.setPosition(sf::Vector2f(50.0f, 50.0f));
	text_.setCharacterSize(48);
	std::stringstream stream;
	text_.setFillColor(sf::Color::Red);
	text_.setOutlineColor(sf::Color::Red);
	stream << "YOU DIED!\n\nPRESS ENTER TO START AGAIN";
	text_.setString(stream.str());
	assignTag("text");
}

void GameOverText::draw() {
	GAME.getRenderWindow().draw(text_);
}

void GameOverText::update(sf::Time& elapsed) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		GameScenePtr scene = std::make_shared<GameScene>();
		GAME.setScene(scene);
		return;
	}
}