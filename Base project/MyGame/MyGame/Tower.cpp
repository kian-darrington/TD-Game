#include "Tower.h"

Tower::Tower(sf::Vector2f pos){
	tower_.setTexture(GAME.getTexture("Resources/tower.png"));
	towerRange_.setTexture(GAME.getTexture("Resources/towerrange.png"));
	assignTag("tower");
	tower_.setPosition(pos);
	towerRange_.setPosition(sf::Vector2f(pos.x - (towerRange_.getGlobalBounds().width / 2), pos.y - (towerRange_.getGlobalBounds().height / 2)));
	setCollisionCheckEnabled(true);
}

void Tower::draw() {
	GAME.getRenderWindow().draw(tower_);
}

sf::FloatRect Tower::getCollisionRect() {
	return tower_.getGlobalBounds();
}