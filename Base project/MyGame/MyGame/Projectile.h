#pragma once
#include "Engine/GameEngine.h"

class Projectile : public GameObject {
public:
	Projectile(sf::Vector2f pos, sf::Vector2f ePos, float xSpeed, float ySpeed, int power);
	void draw();
	void update(sf::Time& elapsed);
	int getPower();
	sf::FloatRect getCollisionRect();
	void handleCollision(GameObject& otherGameObject);
private:
	sf::Sprite sprite_;
	sf::Vector2f ePos_;
	int power_;
	float xSpeed_;
	float ySpeed_;
};
typedef std::shared_ptr<Projectile> ProjectilePtr;