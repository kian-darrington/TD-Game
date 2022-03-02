#include "TowerPlacer.h"
#include "GameScene.h"
#include "Tower.h"
using namespace sf;

const int COST = 50;

TowerPlacer::TowerPlacer() {
	tower_.setTexture(GAME.getTexture("Resources/tower.png"));
	towerRadius_.setTexture(GAME.getTexture("Resources/towerrange.png"));
	setCollisionCheckEnabled(true);
	tower_.setPosition(Vector2f(0.0f, 0.0f));
	towerRadius_.setPosition(Vector2f(tower_.getPosition().x + (tower_.getGlobalBounds().width / 2) - towerRadius_.getGlobalBounds().width, tower_.getPosition().y + (tower_.getGlobalBounds().height / 2) - towerRadius_.getGlobalBounds().height));
	tower_.setColor(Color::Transparent);
	towerRadius_.setColor(Color::Transparent);
}

void TowerPlacer::draw() {
	GAME.getRenderWindow().draw(tower_);
	GAME.getRenderWindow().draw(towerRadius_);
}

sf::FloatRect TowerPlacer::getCollisionRect() {
	return tower_.getGlobalBounds();
}

void TowerPlacer::handleEvent(Event& eve) {
	if (eve.type == Event::KeyPressed && Keyboard::isKeyPressed(Keyboard::T)) {
		place_ = true;
	}
	else if (eve.type == Event::KeyPressed && !Keyboard::isKeyPressed(Keyboard::T)) {
		place_ = false;
	}
	else if (eve.type == Event::MouseButtonReleased && place_) {
		release_ = true;
	}
}

void TowerPlacer::update(Time& elapsed) {
	GameScene& scene = (GameScene&)GAME.getCurrentScene();
	if (scene.getMoney() < COST) {
		place_ = false;
	}
	if (!canPlace_) {
		towerRadius_.setColor(Color::Red);
	}
	else {
		tower_.setColor(Color::White);
		towerRadius_.setColor(Color::White);
	}
	if (place_) {
		tower_.setPosition(Vector2f(Mouse::getPosition().x - (towerRadius_.getGlobalBounds().width / 2), Mouse::getPosition().y - (towerRadius_.getGlobalBounds().height / 2)));
		towerRadius_.setPosition(Vector2f(tower_.getPosition().x + (tower_.getGlobalBounds().width / 2) - (towerRadius_.getGlobalBounds().width / 2), tower_.getPosition().y + (tower_.getGlobalBounds().height / 2) - (towerRadius_.getGlobalBounds().height/2)));
	}
	else {
		tower_.setColor(Color::Transparent);
		towerRadius_.setColor(Color::Transparent);
	}
	if (place_ && release_ && canPlace_) {
		TowerPtr tower = std::make_shared<Tower>(tower_.getPosition(), towernum_);
		towernum_++;
		GAME.getCurrentScene().addGameObject(tower);
		scene.decreaseMoney(COST);
		place_ = false, release_ = false;
	}
	release_ = false;
	canPlace_ = true;
}

void TowerPlacer::handleCollision(GameObject& otherGameObject) {
	if (otherGameObject.hasTag("path") || otherGameObject.hasTag("tower")) {
		tower_.setColor(Color::White);
		towerRadius_.setColor(Color::Red);
		canPlace_ = false;
	}
}