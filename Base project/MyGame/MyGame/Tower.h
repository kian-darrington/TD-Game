#pragma once
#include "Engine/GameEngine.h"
#include <vector>

class Tower : public GameObject {
public:
	Tower(sf::Vector2f pos, int towernum);
	void draw();
	void update(sf::Time& elapsed);
	sf::FloatRect getCollisionRect();
	void handleCollision(GameObject& otherGameObject);
	void handleEvent(sf::Event eve);
	void setClickedOn(bool click, bool space);
private:
	int moneySpent_ = 50;
	int level_ = 1;
	int power_;
	int attackDelay_ = 1000;
	int attackTimer_ = 0;
	sf::Sprite tower_;
	sf::Sprite towerRange_;
	bool attack_ = false, clickedOn_ = false, textOne_ = false, spaceCheck_ = false;
	std::vector<sf::Vector2f> attackObject_;
	bool placeDown_;
};

typedef std::shared_ptr<Tower> TowerPtr;