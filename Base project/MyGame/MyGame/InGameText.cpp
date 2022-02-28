#include "InGameText.h"
#include "GameScene.h"
#include <sstream>
#include <string.h>

InGameText::InGameText() {
	text_.setFont(GAME.getFont("Resources/Courneuf-Regular.ttf"));
	text_.setPosition(sf::Vector2f(10.0f, 10.0f));
	text_.setCharacterSize(24);
	assignTag("score");
}

void InGameText::draw() {
	GAME.getRenderWindow().draw(text_);
}

void InGameText::update(sf::Time& elapsed) {
	std::stringstream stream;
	GameScene& scene = (GameScene&)GAME.getCurrentScene();
	int lives = scene.getLives(), money = scene.getMoney(), DL = scene.getDangerLevel();
	stream << "Lives: " << lives << "\nMoney: " << money << "\nDanger Level: " << DL;
	text_.setString(stream.str());
}