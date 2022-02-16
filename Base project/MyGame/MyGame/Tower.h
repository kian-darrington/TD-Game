#pragma once
#include "Engine/GameEngine.h"

class Tower : public GameObject {
public:
	Tower(sf::Vector2f);
	void draw();
	void update(sf::Time& elapsed);
	sf::FloatRect getCollisionRect();
private:
	sf::Sprite tower_;
	sf::Sprite towerRange_;
};