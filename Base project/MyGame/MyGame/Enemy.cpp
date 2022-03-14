#include "Enemy.h"
#include "GameScene.h"

const float SPEED = 0.05f;

Enemy::Enemy(sf::Vector2f pos, int layer) {
	layer_ = layer;
	layerCheck();
	sprite_.setPosition(pos);
	setCollisionCheckEnabled(true);
	assignTag("enemy");
}

// Assigns a sprite cover bases upon the layer, then changes layer to increase difficulty
void Enemy::layerCheck() {
	if (layer_ < 1) {
		makeDead();
	}
	else if (layer_ == 1) {
		sprite_.setTexture(GAME.getTexture("Resources/meteor.png"));
	}
	else if (layer_ == 2) {
		sprite_.setTexture(GAME.getTexture("Resources/cake.png"));
	}
	else if (layer_ == 3) {
		sprite_.setTexture(GAME.getTexture("Resources/icecream.png"));
		layer_ = 4;
	}
	else if (layer_ == 4) {
		sprite_.setTexture(GAME.getTexture("Resources/donut.png"));
		layer_ = 8;
	}
	else if (layer_ == 5) {
		sprite_.setTexture(GAME.getTexture("Resources/crepe.png"));
		layer_ = 16;
	}
	else if (layer_ == 6) {
		sprite_.setTexture(GAME.getTexture("Resources/brownie.png"));
		layer_ = 32;
	}
	totalLayers_ = layer_;
	speedCheck();
}

// Makes enemies get slower as they lose layers
void Enemy::speedCheck() {
	speedBoost = 1.0f + ((float)layer_ / 8.0f);
	if (totalLayers_ > 16) {
		speedBoost = 1.0f + (float)(layer_ / 32.0f);
	}
}

void Enemy::draw() {
	GAME.getRenderWindow().draw(sprite_);
}

// Movement is done here
void Enemy::update(sf::Time& elapsed) {
	GameScene& scene = (GameScene&)GAME.getCurrentScene();
	sf::Vector2f pos = sprite_.getPosition();
	float x = pos.x;
	float y = pos.y;
	int msElapsed = elapsed.asMilliseconds();
	if (x > GAME.getRenderWindow().getSize().x) {
		GameScene& scene = (GameScene&)GAME.getCurrentScene();
		scene.decreaseLives(layer_);
		makeDead();
	}
	else if (!collision){
		x += 0.2f * msElapsed;
		y += 0.2f * msElapsed;
		sprite_.setPosition(sf::Vector2f(x, y));
	}
	if (collision) {
		if (direction_ == 0) {
			x += SPEED * msElapsed * speedBoost * (1.0f + (float)((float)((scene.getDangerLevel() - 1)) / 10.0f));
		}
		else if (direction_ == 3) {
			y += SPEED * msElapsed * speedBoost * (1.0f + (float)((float)((scene.getDangerLevel() - 1)) / 10.0f));
		}
		else if (direction_ == 1) {
			x -= SPEED * msElapsed * speedBoost * (1.0f + (float)((float)((scene.getDangerLevel() - 1)) / 10.0f));
		}
		else if (direction_ == 2) {
			y -= SPEED * msElapsed * speedBoost * (1.0f + (float)((float)((scene.getDangerLevel() - 1)) / 10.0f));
		}
		sprite_.setPosition(sf::Vector2f(x, y));
	}
}

// Returns values for the program to use
sf::FloatRect Enemy::getCollisionRect() {
	return sprite_.getGlobalBounds();
}
sf::Vector2f Enemy::getObjectPosition() {
	return sf::Vector2f(sprite_.getPosition().x + sprite_.getGlobalBounds().width / 2, sprite_.getPosition().y + sprite_.getGlobalBounds().height / 2);
}

// Based upon the direction, the enemy will go right, left, up, or down, also lets the enemy know when it's hit and makes it lose layers
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
	if (otherGameObject.hasTag("projectile")) {
		if (!otherGameObject.isDead()) {
			int pastLayer = layer_;
			layer_ -= otherGameObject.getPower();
			GameScene& scene = (GameScene&)GAME.getCurrentScene();
			if (layer_ < 1) {
				scene.increaseMoney(pastLayer);
			}
			else {
				scene.increaseMoney(otherGameObject.getPower());
			}
		}
		if (layer_ < 1) {
			makeDead();
		}
		speedCheck();
	}
}