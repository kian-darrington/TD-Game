#include "UpgradeText.h"
#include "GameScene.h"
#include <sstream>
#include <string.h>

UpgradeText::UpgradeText(int level, float range, float attack, int power) {
	text_.setFont(GAME.getFont("Resources/Courneuf-Regular.ttf"));
	text_.setPosition(sf::Vector2f(GAME.getRenderWindow().getSize().x - 250, 10.0f));
	text_.setCharacterSize(24);
	assignTag("score");
	power_ = power;
	level_ = level;
	range_ = range;
	attack_ = attack;
}

void UpgradeText::draw() {
	GAME.getRenderWindow().draw(text_);
}

void UpgradeText::update(sf::Time& elapsed) {
	std::stringstream stream;
	stream << "Level: " << level_ << "\nRange: " << range_ << "\nAttack Speed: " << attack_ << "\nPower: " << power_ << "\nUpgrade Cost: " << 5 + level_ * 10;
	text_.setString(stream.str());
}

void UpgradeText::handleEvent(sf::Event& eve) {
	if (eve.type == sf::Event::KeyPressed) {
		makeDead();
	}
	if (eve.type == sf::Event::MouseButtonPressed) {
		makeDead();
	}
}