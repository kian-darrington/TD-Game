#define _USE_MATH_DEFINES
#include <math.h>
#include "Tower.h"
#include "Projectile.h"
Tower::Tower(sf::Vector2f pos){
	power_ = 1;
	tower_.setTexture(GAME.getTexture("Resources/tower.png"));
	towerRange_.setTexture(GAME.getTexture("Resources/towerrange.png"));
	towerRange_.setColor(sf::Color::Transparent);
	assignTag("tower");
	tower_.setPosition(pos);
	towerRange_.setPosition(sf::Vector2f(pos.x - (towerRange_.getGlobalBounds().width / 2) + (tower_.getGlobalBounds().width / 2), pos.y - (towerRange_.getGlobalBounds().height / 2) + (tower_.getGlobalBounds().width / 2)));
	setCollisionCheckEnabled(true);
	attackTimer_ = attackDelay_;
	// tower_.setOrigin(sf::Vector2f(tower_.getGlobalBounds().width / 2,tower_.getGlobalBounds().height / 2));
	// tower_.setPosition(pos);
}

void Tower::draw() {
	GAME.getRenderWindow().draw(tower_);
	GAME.getRenderWindow().draw(towerRange_);
}

void Tower::update(sf::Time& elapsed) {
	int msElapsed = elapsed.asMilliseconds();
	int whichone = 0;
	float angleTotal = 0.0;
	attackTimer_ -= msElapsed;
	if (attack_ && attackTimer_ <= 0 && attackObject_.size() > 0) {
		for (int i = 0; i < attackObject_.size(); i++) {
			bool rightOne = true;
			for (int o = 0; o < attackObject_.size(); o++) {
				if (attackObject_[i].x < attackObject_[o].x) {
					rightOne = false;
				}
			}
			if (rightOne == true) {
				whichone = i;
				break;
			}
		}
		sf::Vector2f towerCenter(tower_.getPosition().x + tower_.getGlobalBounds().width / 2, tower_.getPosition().y + tower_.getGlobalBounds().height / 2);
		sf::Vector2f attackPoint = sf::Vector2f(towerCenter.x - attackObject_[whichone].x, towerCenter.y - attackObject_[whichone].y);
		ProjectilePtr projectile = std::make_shared<Projectile>(towerCenter, attackPoint, attackPoint.x, attackPoint.y, power_);
		GAME.getCurrentScene().addGameObject(projectile);
		if (attackPoint.x > 0 && attackPoint.y < 0) {
			angleTotal += 90.0 * 0;
		}
		else if (attackPoint.x < 0 && attackPoint.y < 0) {
			angleTotal += 90* 0;
		}
		else if (attackPoint.x < 0 && attackPoint.y > 0) {
			angleTotal += 90 * 0;
		}
		angleTotal += 180;
		if (attackPoint.x != 0) {
			angleTotal += atanf(attackPoint.y / attackPoint.x) * attackPoint.y;
		}
		else {
			angleTotal += 90;
		}
		// tower_.setRotation(angleTotal);
		attackTimer_ = attackDelay_;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
		towerRange_.setColor(sf::Color::White);
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
		towerRange_.setColor(sf::Color::Transparent);
	}
	attack_ = false;
	attackObject_.clear();
}

sf::FloatRect Tower::getCollisionRect() {
	return towerRange_.getGlobalBounds();
}

void Tower::handleCollision(GameObject& otherGameObject) {
	if (otherGameObject.hasTag("enemy")) {
		attack_ = true;
		attackObject_.push_back(otherGameObject.getObjectPosition());
	}
}