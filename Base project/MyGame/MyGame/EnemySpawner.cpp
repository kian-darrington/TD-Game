#include "EnemySpawner.h"
#include "GameScene.h"
#include "Enemy.h"

const int SPACE_DELAY = 920;
const int ENEMY_NUMBER = 3;

void EnemySpawner::update(sf::Time& elapsed) {
	timer_ -= elapsed.asMilliseconds();
	difficultyTimer_ += elapsed.asMilliseconds();
	if (difficultyTimer_ > 60000) {
		difficulty_++;
		GameScene& scene = (GameScene&)GAME.getCurrentScene();
		scene.increaseDangerLevel();
		difficultyTimer_ = 0;
	}
	if (timer_ < 1) {
		sf::Vector2f pos;
		pos.x = -64;
		pos.y = GAME.getRenderWindow().getSize().y / 2 - 15;
		int enemyType = 1;
		if (difficulty_ > 1 && difficulty_ <= ENEMY_NUMBER) {
			enemyType = 1 + rand() % difficulty_;
		}
		else if (difficulty_ >= ENEMY_NUMBER) {
			if (difficulty_ < ENEMY_NUMBER * 2) {
				enemyType = (difficulty_ - ENEMY_NUMBER) + rand() % (difficulty_ - ENEMY_NUMBER);
			}
			else {
				enemyType = ENEMY_NUMBER;
			}
		}
		EnemyPtr enemy1 = std::make_shared<Enemy>(pos, enemyType);
		GAME.getCurrentScene().addGameObject(enemy1);
		timer_ = SPACE_DELAY / (1 + (float)(difficulty_ / 10.0f));
	}
}