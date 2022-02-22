#pragma once
#include "Engine/GameEngine.h"

class Enemy : public GameObject {
public:
	Enemy(sf::Vector2f pos);
	void draw();
	void update(sf::Time& elapsed);
	sf::FloatRect getCollisionRect();
	sf::Vector2f getObjectPosition();
	void handleCollision(GameObject& otherGameObject);
private:
	sf::Sprite sprite_;
	int xSpeed_ = 0.2f;
	int ySpeed_ = 0;
	int enemyType_;
	bool collision = false;
	int direction_ = 0;
};

typedef std::shared_ptr<Enemy> EnemyPtr;