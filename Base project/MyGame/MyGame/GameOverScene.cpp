#include "GameOverScene.h"
#include "GameOverText.h"
#include "Enemy.h"
// makes the beginning and ending scenes
GameOverScene::GameOverScene(bool startScreen, int score) {
	GameOverTextPtr text = std::make_shared<GameOverText>(startScreen, score);
	addGameObject(text);
}