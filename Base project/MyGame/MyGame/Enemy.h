#pragma once
#include "Engine/GameEngine.h"

class Enemy : public GameObject {
public:
	Enemy(sf::Vector2f pos, int layer);
	void draw();
	void update(sf::Time& elapsed);
	sf::FloatRect getCollisionRect();
	sf::Vector2f getObjectPosition();
	void handleCollision(GameObject& otherGameObject);
	void layerCheck();
	void speedCheck();
private:
	int layer_;
	sf::Sprite sprite_;
	int xSpeed_ = 0.2f;
	int ySpeed_ = 0;
	int enemyType_;
	bool collision = false;
	int direction_ = 0;
	float speedBoost = 1.0f;
};

typedef std::shared_ptr<Enemy> EnemyPtr;