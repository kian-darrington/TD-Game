#define _USE_MATH_DEFINES
#include <math.h>
#include "Tower.h"
#include "TowerFootprint.h"
#include "Projectile.h"
#include <sstream>
#include "UpgradeText.h"
#include "GameScene.h"

const float RADIANS_TO_DEGREES = 57.2958f;
// Makes tower
Tower::Tower(sf::Vector2f pos, int towernum){
	power_ = 1;
	tower_.setTexture(GAME.getTexture("Resources/tower.png"));
	towerRange_.setTexture(GAME.getTexture("Resources/towerrange.png"));
	towerRange_.setColor(sf::Color::Transparent);
	assignTag("towerrange");
	std::stringstream name;
	name << "tower" << towernum;
	assignTag(name.str());
	tower_.setOrigin(tower_.getGlobalBounds().width / 2, tower_.getGlobalBounds().height / 2);
	TowerFootPtr towerfoot = std::make_shared<TowerFoot>(pos, towernum);
	GAME.getCurrentScene().addGameObject(towerfoot);
	towerRange_.setPosition(sf::Vector2f(pos.x - (towerRange_.getGlobalBounds().width / 2) + (tower_.getGlobalBounds().width / 2), pos.y - (towerRange_.getGlobalBounds().height / 2) + (tower_.getGlobalBounds().width / 2)));
	setCollisionCheckEnabled(true);
	attackTimer_ = attackDelay_;
	tower_.setPosition(pos.x + tower_.getGlobalBounds().width / 2, pos.y + tower_.getGlobalBounds().height / 2);
}

void Tower::draw() {
	GAME.getRenderWindow().draw(tower_);
	GAME.getRenderWindow().draw(towerRange_);
}
// Handles what to do if it's clicked on, and fires at objects
void Tower::update(sf::Time& elapsed) {
	GameScene& scene = (GameScene&)GAME.getCurrentScene();
	int msElapsed = elapsed.asMilliseconds();
	int whichone = 0;
	float angleTotal = 0.0f;
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
		sf::Vector2f towerCenter(tower_.getPosition());
		sf::Vector2f attackPoint(towerCenter.x - attackObject_[whichone].x, towerCenter.y - attackObject_[whichone].y);
		ProjectilePtr projectile = std::make_shared<Projectile>(towerCenter, attackPoint, attackPoint.x, attackPoint.y, power_);
		GAME.getCurrentScene().addGameObject(projectile);
		if (attackPoint.y > 0) {
			if (attackPoint.x > 0) {
				angleTotal += atan2f(-attackPoint.x, attackPoint.y) * RADIANS_TO_DEGREES;
			}
			else if (attackPoint.x < 0) {
				angleTotal -= atan2f(attackPoint.y, -attackPoint.x) * RADIANS_TO_DEGREES;
				angleTotal += 90;
			}
		}
		else if (attackPoint.y < 0) {
			if (attackPoint.x > 0) {
				angleTotal -= atan2f(attackPoint.x, attackPoint.y) * RADIANS_TO_DEGREES;
			}
			else if (attackPoint.x < 0) {
				angleTotal -= atan2f(attackPoint.y, -attackPoint.x) * RADIANS_TO_DEGREES;
				angleTotal += 90;
			}
		}
		tower_.setRotation(angleTotal);
		attackTimer_ = attackDelay_;
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
		towerRange_.setColor(sf::Color::Transparent);
	}
	if (clickedOn_) {
		towerRange_.setColor(sf::Color::White);
		if (!textOne_) {
			UpgradeTextPtr text = std::make_shared<UpgradeText>(level_, towerRange_.getScale().x, (float)(attackDelay_ / 1000.0f), power_, moneySpent_);
			GAME.getCurrentScene().addGameObject(text);
			textOne_ = true;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
			scene.increaseMoney(((moneySpent_) / 2));
			makeDead();
			clickedOn_ = false;
		}
	}
	else {
		textOne_ = false;
	}
	if (spaceCheck_ && scene.getMoney() >= (int)(((5 + (level_ * 15))) * (float)(1.0f + (float)((level_ - 1) / 10.0f)))) {
		if (upgradeOnce_) {
			level_++;
			if ((level_) % 3 == 0) {
				power_++;
			}
			moneySpent_ += (int)(((5 + ((level_ - 1) * 15))) * (float)(1.0f + (float)((level_ - 2) / 10.0f)));
			towerRange_.setScale(1.0f + (float)((level_ - 1) / 10.0f), 1.0f + (float)(level_ - 1) / 10.0f);
			sf::Vector2f pos = tower_.getPosition();
			towerRange_.setPosition(sf::Vector2f(pos.x - towerRange_.getGlobalBounds().width / 2, pos.y - towerRange_.getGlobalBounds().height / 2));
			attackDelay_ = attackDelay_ / 1.1f;
			if (attackDelay_ < 10) {
				attackDelay_ = 10;
			}
			scene.decreaseMoney((int)((5 + ((level_ - 1)* 15)) * (float)(1.0f + (float)((level_ - 2) / 10.0f))));
			clickedOn_ = false;
			upgradeOnce_ = false;
		}
	}
	if (!spaceCheck_) {
		upgradeOnce_ = true;
	}
	attack_ = false;
	attackObject_.clear();
}

void Tower::setClickedOn(bool click, bool space) {
	clickedOn_ = click;
	spaceCheck_ = space;
}

sf::FloatRect Tower::getCollisionRect() {
	return towerRange_.getGlobalBounds();
}

void Tower::handleEvent(sf::Event eve) {
	if (eve.type == sf::Event::MouseButtonPressed) {
		clickedOn_ = false;
	}
}

void Tower::handleCollision(GameObject& otherGameObject) {
	if (otherGameObject.hasTag("enemy")) {
		attack_ = true;
		attackObject_.push_back(otherGameObject.getObjectPosition());
	}
}