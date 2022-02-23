#pragma once
#include "Engine/GameEngine.h"

class Tower : public GameObject {
public:
	Tower(sf::Vector2f);
	void draw();
	void update(sf::Time& elapsed);
	sf::FloatRect getCollisionRect();
	void handleCollision(GameObject& otherGameObject);
private:
	int pierce_;
	int attackDelay_ = 1000;
	int attackTimer_;
	sf::Sprite tower_;
	sf::Sprite towerRange_;
	bool attack_ = false;
	sf::Vector2f attackObject_;
	bool placeDown_;
};

typedef std::shared_ptr<Tower> TowerPtr;