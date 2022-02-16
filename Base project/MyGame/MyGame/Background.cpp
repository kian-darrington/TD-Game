#include "Background.h"

Background::Background() {
	sprite_.setTexture(GAME.getTexture("Resources/greengrass.png"));
	sprite_.setPosition(sf::Vector2f(0, 0));
}

void Background::draw() {
	GAME.getRenderWindow().draw(sprite_);
}
