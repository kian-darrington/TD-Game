#include "Projectile.h"

const float BASE_SPEED = 0.5f;

Projectile::Projectile(sf::Vector2f pos, sf::Vector2f ePos, float xSpeed, float ySpeed, int power) {
	sprite_.setTexture(GAME.getTexture("Resources/spoon.png"));
	sprite_.setPosition(pos);
	assignTag("projectile");
	ePos_ = ePos;
	if (xSpeed == 0) {
		xSpeed_ = 0;
		ySpeed_ = 1;
	}
	else if (ySpeed_ == 0) {
		xSpeed_ = 1;
		ySpeed_ = 0;
	}
	else {
		xSpeed_ = xSpeed / ySpeed;
		ySpeed_ = ySpeed / xSpeed;
	}
	power_ = power;
}

void Projectile::draw() {
	GAME.getRenderWindow().draw(sprite_);
}

void Projectile::update(sf::Time& elapsed) {
	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = sprite_.getPosition();
	if (ePos_.x > 0 && ePos_.y > 0) {
		pos.x -= BASE_SPEED * msElapsed * atanf(xSpeed_);
		pos.y -= BASE_SPEED * msElapsed * atanf(ySpeed_);
	}
	else if (ePos_.x < 0 && ePos_.y < 0) {
		pos.x += BASE_SPEED * msElapsed * atanf(xSpeed_);
		pos.y += BASE_SPEED * msElapsed * atanf(ySpeed_);
	}
	else if (ePos_.x < 0 && ePos_.y > 0) {
		pos.x -= BASE_SPEED * msElapsed * atanf(xSpeed_);
		pos.y += BASE_SPEED * msElapsed * atanf(ySpeed_);
	}
	else if (ePos_.x > 0 && ePos_.y < 0) {
		pos.x += BASE_SPEED * msElapsed * atanf(xSpeed_);
		pos.y -= BASE_SPEED * msElapsed * atanf(ySpeed_);
	}
	else {
		pos.x += BASE_SPEED * msElapsed * atanf(xSpeed_);
		pos.y -= BASE_SPEED * msElapsed * atanf(ySpeed_);
	}
	if (pos.x < 0) {
		makeDead();
	}
	if (pos.x > GAME.getRenderWindow().getSize().x) {
		makeDead();
	}
	if (pos.y < 0) {
		makeDead();
	}
	if (pos.y > GAME.getRenderWindow().getSize().y) {
		makeDead();
	}
	sprite_.setPosition(pos);
}

int Projectile::getPower() {
	return power_;
}

sf::FloatRect Projectile::getCollisionRect() {
	return sprite_.getGlobalBounds();
}

void Projectile::handleCollision(GameObject& otherGameObject) {
	if (otherGameObject.hasTag("enemy")) {
		makeDead();
	}
}