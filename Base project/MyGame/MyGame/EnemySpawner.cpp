#include "EnemySpawner.h"
#include "GameScene.h"
#include "Enemy.h"

const int SPACE_DELAY = 920;
const int ENEMY_NUMBER = 5;

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
		switch (difficulty_) {
		case 1:
			enemyType = 1;
			break;
		case 2:
			enemyType = 1 + rand() % 2;
			break;
		case 3:
			enemyType = 1 + rand() % 3;
			break;
		case 4:
			enemyType = 1 + rand() % 4;
			break;
		case 5:
			enemyType = 2 + rand() % 3;
			break;
		case 6:
			enemyType = 2 + rand() % 4;
			break;
		case 7:
			enemyType = 3 + rand() % 3;
			break;
		case 8:
			enemyType = 4 + rand() % 2;
			break;
		default:
			enemyType = ENEMY_NUMBER;
			break;
		}
		EnemyPtr enemy1 = std::make_shared<Enemy>(pos, enemyType);
		GAME.getCurrentScene().addGameObject(enemy1);
		timer_ = SPACE_DELAY / (1 + (float)(difficulty_ / 5.0f));
	}
}