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

void Enemy::layerCheck() {
	if (layer_ < 1) {
		makeDead();
	}
	else if (layer_ == 1) {
		sprite_.setTexture(GAME.getTexture("Resources/meteor.png"));
	}
	else if (layer_ == 2) {
		sprite_.setTexture(GAME.getTexture("Resources/cake.png"));
		speedBoost = 1.25f;
	}
	else if (layer_ == 3) {
		sprite_.setTexture(GAME.getTexture("Resources/icecream.png"));
		speedBoost = 1.5f;
	}
	else if (layer_ == 4) {
		sprite_.setTexture(GAME.getTexture("Resources/donut.png"));
		speedBoost = 1.75f;
	}
}

void Enemy::speedCheck() {
	if (layer_ == 1) {
		speedBoost = 1.0f;
	}
	else if (layer_ == 2) {
		speedBoost = 1.25f;
	}
	else if (layer_ == 3) {
		speedBoost = 1.5f;
	}
	else if (layer_ == 4) {
		speedBoost = 1.75;
	}
	else {
		speedBoost = 1.0f;
	}
}

void Enemy::draw() {
	GAME.getRenderWindow().draw(sprite_);
}

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
			x += SPEED * msElapsed * speedBoost * (1.0f + (float)((float)((scene.getDangerLevel() - 1) / 1.5f) / 10.0f));
		}
		else if (direction_ == 3) {
			y += SPEED * msElapsed * speedBoost * (1.0f + (float)((float)((scene.getDangerLevel() - 1) / 1.5f) / 10.0f));
		}
		else if (direction_ == 1) {
			x -= SPEED * msElapsed * speedBoost * (1.0f + (float)((float)((scene.getDangerLevel() - 1) / 1.5f) / 10.0f));
		}
		else if (direction_ == 2) {
			y -= SPEED * msElapsed * speedBoost * (1.0f + (float)((float)((scene.getDangerLevel() - 1) / 1.5f) / 10.0f));
		}
		sprite_.setPosition(sf::Vector2f(x, y));
	}
}

sf::FloatRect Enemy::getCollisionRect() {
	return sprite_.getGlobalBounds();
}

sf::Vector2f Enemy::getObjectPosition() {
	return sf::Vector2f(sprite_.getPosition().x + sprite_.getGlobalBounds().width / 2, sprite_.getPosition().y + sprite_.getGlobalBounds().height / 2);
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