#pragma once

#include "Engine/GameEngine.h"

class TowerPlacer : public GameObject {
public:
	TowerPlacer();
	void draw();
	void update(sf::Time& elapsed);

	sf::FloatRect getCollisionRect();

	void handleEvent(sf::Event& eve);
	void handleCollision(GameObject& otherGameObject);
private:
	sf::Sprite tower_;
	sf::Sprite towerRadius_;
	bool place_ = false;
	bool release_ = false;
	bool canPlace_ = true;
};

typedef std::shared_ptr<TowerPlacer> TowerPlacerPtr;