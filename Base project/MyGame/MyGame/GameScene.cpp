#include "GameScene.h"
#include "GameOverScene.h"
#include "Line.h"
#include "Background.h"
#include "TowerPlacer.h"
#include "EnemySpawner.h"
#include "InGameText.h"
#include "Mouse.h"

const int vright = 0, vdown = 1, vleft = 2, vup = 3, right = 4, down = 5, left = 6, up = 7;
// Scene for the main game
GameScene::GameScene() {
	setLevelOne();
	EnemySpawnerPtr enemyspawner = std::make_shared<EnemySpawner>();
	addGameObject(enemyspawner);
	TowerPlacerPtr tower = std::make_shared<TowerPlacer>();
	addGameObject(tower);
	InGameTextPtr GameText = std::make_shared<InGameText>();
	addGameObject(GameText);
	CursorPtr mouse = std::make_shared<Cursor>();
	addGameObject(mouse);
}
// Sets the stage for the game
void GameScene::setLevelOne() {
	sf::Vector2f pos;
	pos.x = 0;
	pos.y = GAME.getRenderWindow().getSize().y / 2;
	LinePtr firstLine = std::make_shared<Line>(right, pos);
	addGameObject(firstLine);
	pos.x = 300;
	pos.y = (GAME.getRenderWindow().getSize().y / 2) - 300;
	LinePtr secondLine = std::make_shared<Line>(up, pos);
	addGameObject(secondLine);
	pos.x = 300;
	pos.y = GAME.getRenderWindow().getSize().y / 2 - 200;
	LinePtr bugline = std::make_shared<Line>(up, pos);
	addGameObject(bugline);
	pos.x = 300;
	pos.y = (GAME.getRenderWindow().getSize().y / 2) - 300;
	LinePtr thirdLine = std::make_shared<Line>(right, pos);
	addGameObject(thirdLine);
	pos.x = 600;
	pos.y = (GAME.getRenderWindow().getSize().y / 2) - 300;
	LinePtr fourthLine = std::make_shared<Line>(down, pos);
	addGameObject(fourthLine);
	pos.x = 600;
	pos.y = (GAME.getRenderWindow().getSize().y / 2);
	LinePtr fifthLine = std::make_shared<Line>(down, pos);
	addGameObject(fifthLine);
	pos.x = 600;
	pos.y = (GAME.getRenderWindow().getSize().y / 2) + 300;
	LinePtr sixthLine = std::make_shared<Line>(right, pos);
	addGameObject(sixthLine);
	pos.x = 900;
	pos.y = (GAME.getRenderWindow().getSize().y / 2);
	LinePtr Line7 = std::make_shared<Line>(up, pos);
	addGameObject(Line7);
	pos.x = 900;
	pos.y = (GAME.getRenderWindow().getSize().y / 2);
	LinePtr Line8 = std::make_shared<Line>(right, pos);
	addGameObject(Line8);
	BackgroundPtr background = std::make_shared<Background>();
	addGameObject(background);

	//visible path
	pos.x = 0;
	pos.y = GAME.getRenderWindow().getSize().y / 2 - 23;
	LinePtr vfirstLine = std::make_shared<Line>(vright, pos);
	addGameObject(vfirstLine);
	pos.x = 20;
	pos.y = GAME.getRenderWindow().getSize().y / 2 - 23;
	LinePtr filler1 = std::make_shared<Line>(vright, pos);
	addGameObject(filler1);
	pos.x = 240;
	pos.y = (GAME.getRenderWindow().getSize().y / 2) - 300;
	LinePtr vsecondLine = std::make_shared<Line>(vup, pos);
	addGameObject(vsecondLine);
	pos.x = 240;
	pos.y = (GAME.getRenderWindow().getSize().y / 2) - 310;
	LinePtr vthirdLine = std::make_shared<Line>(vright, pos);
	addGameObject(vthirdLine);
	pos.x = 320;
	pos.y = (GAME.getRenderWindow().getSize().y / 2) - 310;
	LinePtr filler2 = std::make_shared<Line>(vright, pos);
	addGameObject(filler2);
	pos.x = 540;
	pos.y = (GAME.getRenderWindow().getSize().y / 2) - 300;
	LinePtr vfourthLine = std::make_shared<Line>(vdown, pos);
	addGameObject(vfourthLine);
	pos.x = 540;
	pos.y = (GAME.getRenderWindow().getSize().y / 2);
	LinePtr vfifthLine = std::make_shared<Line>(vdown, pos);
	addGameObject(vfifthLine);
	pos.x = 540;
	pos.y = (GAME.getRenderWindow().getSize().y / 2) + 240;
	LinePtr vsixthLine = std::make_shared<Line>(vright, pos);
	addGameObject(vsixthLine);
	pos.x = 620;
	pos.y = (GAME.getRenderWindow().getSize().y / 2) + 240;
	LinePtr filler3 = std::make_shared<Line>(vright, pos);
	addGameObject(filler3);
	pos.x = 840;
	pos.y = (GAME.getRenderWindow().getSize().y / 2) - 10;
	LinePtr vLine7 = std::make_shared<Line>(vup, pos);
	addGameObject(vLine7);
	pos.x = 900;
	pos.y = (GAME.getRenderWindow().getSize().y / 2) - 10;
	LinePtr vLine8 = std::make_shared<Line>(vright, pos);
	addGameObject(vLine8);
}

void GameScene::increaseMoney(int increase) {
	money_ += increase;
}

void GameScene::decreaseMoney(int cost) {
	money_ -= cost;
}

void GameScene::increaseDangerLevel() {
	dangerLevel_++;
}

void GameScene::decreaseLives(int layer) {
	lives_ -= layer;
	if (lives_ <= 0) {
		GameOverScenePtr scene = std::make_shared<GameOverScene>(false);
		GAME.setScene(scene);
	}
}

int GameScene::getLives() {
	return lives_;
}

int GameScene::getMoney() {
	return money_;
}

int GameScene::getDangerLevel() {
	return dangerLevel_;
}