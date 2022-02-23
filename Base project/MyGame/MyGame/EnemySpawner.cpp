#include "EnemySpawner.h"
#include "Enemy.h"

const int SPACE_DELAY = 920;

void EnemySpawner::update(sf::Time& elapsed) {
	timer_ -= elapsed.asMilliseconds();
	if (timer_ < 1 && !sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		sf::Vector2f pos;
		pos.x = -64;
		pos.y = GAME.getRenderWindow().getSize().y / 2 - 15;
		EnemyPtr enemy1 = std::make_shared<Enemy>(pos, 1);
		GAME.getCurrentScene().addGameObject(enemy1);
		timer_ = SPACE_DELAY;
	}
}