#include "TowerFootprint.h"
#include <sstream>

TowerFoot::TowerFoot(sf::Vector2f pos, int tower) {
	sprite_.setTexture(GAME.getTexture("Resources/tower.png"));
	sprite_.setPosition(pos);
	assignTag("tower");
	std::stringstream temp;
	temp << "tower" << tower;
	tower_ = temp.str();
	setCollisionCheckEnabled(true);
	sprite_.setColor(sf::Color::Transparent);
}

void TowerFoot::draw() {
	GAME.getRenderWindow().draw(sprite_);
}

sf::FloatRect TowerFoot::getCollisionRect() {
	return sprite_.getGlobalBounds();
}

void TowerFoot::handleCollision(GameObject& otherGameObject) {
	if (otherGameObject.hasTag("mouse")) {
		mouseOn_ = true;
	}
	if (otherGameObject.hasTag(tower_)) {
		otherGameObject.setClickedOn(clickedOn_, spaceCheck_);
		if (otherGameObject.isDead()) {
			makeDead();
		}
	}
}

void TowerFoot::update(sf::Time& elapsed) {

}

void TowerFoot::handleEvent(sf::Event& eve) {
	if (eve.type == sf::Event::MouseButtonPressed && clickedOn_) {
		clickedOn_ = false;
	}
	else if (eve.type == sf::Event::MouseButtonPressed && mouseOn_) {
		clickedOn_ = true;
	}
	else if (eve.type == sf::Event::MouseButtonPressed && !mouseOn_) {
		clickedOn_ = false;
	}
	if (eve.type == sf::Event::KeyReleased && spaceCheck_) {
		clickedOn_ = true;
		spaceCheck_ = false;
	}
	if (eve.type == sf::Event::KeyPressed) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && clickedOn_) {
			spaceCheck_ = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && clickedOn_) {
			makeDead();
		}
		clickedOn_ = false;
	}
	if (eve.type == sf::Event::MouseButtonReleased && mouseOn_) {
		clickedOn_ = true;
	}
	if (eve.type == sf::Event::MouseButtonReleased && !mouseOn_) {
		clickedOn_ = false;
	}
	mouseOn_ = false;
}