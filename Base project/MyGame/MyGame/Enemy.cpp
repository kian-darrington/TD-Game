#include "Enemy.h"

const float SPEED = 0.05f;

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
	float x = pos.x;
	float y = pos.y;
	int msElapsed = elapsed.asMilliseconds();
	if (x > GAME.getRenderWindow().getSize().x) {
		makeDead();
	}
	else if (!collision){
		x += 0.2f * msElapsed;
		y += 0.2f * msElapsed;
		sprite_.setPosition(sf::Vector2f(x, y));
	}
	if (collision) {
		if (direction_ == 0) {
			x += SPEED * msElapsed;
		}
		else if (direction_ == 3) {
			y += SPEED * msElapsed;
		}
		else if (direction_ == 1) {
			x -= SPEED * msElapsed;
		}
		else if (direction_ == 2) {
			y -= SPEED * msElapsed;
		}
		sprite_.setPosition(sf::Vector2f(x, y));
	}
}

sf::FloatRect Enemy::getCollisionRect() {
	return sprite_.getGlobalBounds();
}

sf::Vector2f Enemy::getObjectPosition() {
	return sprite_.getPosition();
}

void Enemy::handleCollision(GameObject& otherGameObject) {
	collision = true;
	if (otherGameObject.hasTag("right")) {
		direction_ = 0;
	}
	if (otherGameObject.hasTag("left")) {
		direction_ = 1;
	}
	if (otherGameObject.hasTag("up")) {
		direction_ = 2;
	}
	if (otherGameObject.hasTag("down")) {
		direction_ = 3;
	}
}