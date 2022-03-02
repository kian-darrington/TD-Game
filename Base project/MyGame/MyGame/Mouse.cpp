#include "Mouse.h"

Cursor::Cursor() {
	sprite_.setTexture(GAME.getTexture("Resources/mouse.png"));
	assignTag("mouse");
}

void Cursor::draw() {
	GAME.getRenderWindow().draw(sprite_);
}

void Cursor::update(sf::Time& elapsed) {
	sprite_.setPosition(sf::Vector2f(sf::Mouse::getPosition().x - 92, sf::Mouse::getPosition().y - 67));
}

sf::FloatRect Cursor::getCollisionRect() {
	return sprite_.getGlobalBounds();
}