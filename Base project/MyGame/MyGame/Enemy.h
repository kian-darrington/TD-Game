#pragma once
#include "Engine/GameEngine.h"

class Enemy : public GameObject {
public:
	Enemy(sf::Vector2f pos);
	void draw();
	void update(sf::Time& elapsed);
	sf::FloatRect getCollisionRect();
	void handleCollision(GameObject& otherGameObject);
private:
	sf::Sprite sprite_;
	int xSpeed_ = 0;
	int ySpeed_ = -0.02f;
	int enemyType_;
};

typedef std::shared_ptr<Enemy> EnemyPtr;