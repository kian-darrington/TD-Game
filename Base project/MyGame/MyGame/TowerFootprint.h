#pragma once
#include "Engine/GameEngine.h"
#include <string.h>

class TowerFoot : public GameObject {
public:
	TowerFoot(sf::Vector2f pos, int tower);
	void draw();
	sf::FloatRect getCollisionRect();
	void update(sf::Time& elapsed);
	void handleCollision(GameObject& otherGameObject);
	void handleEvent(sf::Event& eve);
private:
	bool clickedOn_ = false, mouseOn_ = false, spaceCheck_ = false;
	sf::Sprite sprite_;
	std::string tower_;
};

typedef std::shared_ptr<TowerFoot> TowerFootPtr;