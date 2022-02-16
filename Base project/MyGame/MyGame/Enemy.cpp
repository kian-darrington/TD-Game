#include "Enemy.h"

const int SPEED = 0.02f;

Enemy::Enemy(sf::Vector2f pos) {
	sprite_.setTexture(GAME.getTexture("Resources/meteor.png"));
	sprite_.setPosition(pos);
	setCollisionCheckEnabled(true);
	assignTag("enemy");
}

void Enemy::draw() {
	GAME.getRenderWindow().draw(sprite_);
}

void Enemy::update(sf::Time& elapsed) {
	sf::Vector2f pos = sprite_.getPosition();
	float x = pos.x, y = pos.y;
	int msElapsed = elapsed.asMilliseconds();
	x += xSpeed_ * msElapsed;
	y += ySpeed_ * msElapsed;
	sprite_.setPosition(sf::Vector2f(x, y));
}

sf::FloatRect Enemy::getCollisionRect() {
	return sprite_.getGlobalBounds();
}

void Enemy::handleCollision(GameObject& otherGameObject) {
	if (otherGameObject.hasTag("right")) {
		xSpeed_ = SPEED;
		ySpeed_ = 0;
	}
	if (otherGameObject.hasTag("left")) {
		xSpeed_ = -SPEED;
		ySpeed_ = 0;
	}
	if (otherGameObject.hasTag("up")) {
		xSpeed_ = 0;
		ySpeed_ = -SPEED;
	}
	if (otherGameObject.hasTag("down")) {
		xSpeed_ = 0;
		ySpeed_ = SPEED;
	}
}