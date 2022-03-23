#include "GameOverText.h"
#include "GameScene.h"
#include <sstream>
//Text that is printed at the start of the game, and the death of the player
GameOverText::GameOverText(bool startScreen) {
	text_.setFont(GAME.getFont("Resources/Courneuf-Regular.ttf"));
	text_.setPosition(sf::Vector2f(50.0f, 50.0f));
	text_.setCharacterSize(48);
	std::stringstream stream;
	startScreen_ = startScreen;
	if (!startScreen) {
		text_.setFillColor(sf::Color::Red);
		text_.setOutlineColor(sf::Color::Red);
		stream << "YOU DIED!\n\nPRESS ENTER TO START AGAIN";
	}
	else {
		stream << "WELCOME TO COOKIE CRUSH TD\n\nPRESS 'I' FOR INSTRUCTIONS\n\nPRESS ENTER TO START";
	}
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::I) && startScreen_) {
		std::stringstream stream;
		stream << "PRESS 'T' TO LAY DOWN TOWERS FOR 50 MONEY\nCLICK ON A TOWER TO SELECT IT\nPRESS SPACE WHILE SELECTING A TOWER\nTO UPGRADE\nPRESS BACKSPACE WHILE SELECTING A TOWER\nTO SELL IT\n\n\nPRESS ENTER TO START";
		text_.setString(stream.str());
		startScreen_ = false;
	}
}