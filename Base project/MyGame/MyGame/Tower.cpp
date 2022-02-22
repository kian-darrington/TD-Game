#define _USE_MATH_DEFINES
#include <math.h>
#include "Tower.h"

Tower::Tower(sf::Vector2f pos){
	tower_.setTexture(GAME.getTexture("Resources/tower.png"));
	towerRange_.setTexture(GAME.getTexture("Resources/towerrange.png"));
	assignTag("tower");
	tower_.setPosition(pos);
	towerRange_.setPosition(sf::Vector2f(pos.x - (towerRange_.getGlobalBounds().width / 2), pos.y - (towerRange_.getGlobalBounds().height / 2)));
	setCollisionCheckEnabled(true);
	attackTimer_ = attackDelay_;
}

void Tower::draw() {
	GAME.getRenderWindow().draw(tower_);
	GAME.getRenderWindow().draw(towerRange_);
}

void Tower::update(sf::Time& elapsed) {
	int msElapsed = elapsed.asMilliseconds();
	float angleTotal = 0.0;
	attackTimer_ -= msElapsed;
	if (attack_ && attackTimer_ <= 0) {
		sf::Vector2f attackPoint = sf::Vector2f(tower_.getPosition().x - attackObject_.x, tower_.getPosition().y - attackObject_.y);
		if (attackPoint.x > 0 && attackPoint.y < 0) {
			angleTotal += 90.0;
			attackPoint.y = - attackPoint.y;
		}
		else if (attackPoint.x < 0 && attackPoint.y < 0) {
			angleTotal += 180.0;
			attackPoint.y = -attackPoint.y;
			attackPoint.x = -attackPoint.x;
		}
		else if (attackPoint.x < 0 && attackPoint.y > 0) {
			angleTotal += 270.0;
			attackPoint.x = -attackPoint.x;
		}
		if (attackPoint.x != 0) {
			angleTotal += atanf(attackPoint.y / attackPoint.x);
		}
		else {
			angleTotal += 90;
		}
		tower_.setRotation(angleTotal);
		attackTimer_ = attackDelay_;
		attack_ = false;
	}
}

sf::FloatRect Tower::getCollisionRect() {
	return towerRange_.getGlobalBounds();
}

void Tower::handleCollision(GameObject& otherGameObject) {
	if (otherGameObject.hasTag("enemy")) {
		attack_ = true;
		attackObject_ = otherGameObject.getObjectPosition();
		attackObject_.x += otherGameObject.getCollisionRect().width / 2;
		attackObject_.y += otherGameObject.getCollisionRect().height / 2;
	}
}