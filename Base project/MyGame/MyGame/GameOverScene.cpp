#include "GameOverScene.h"
#include "GameOverText.h"
#include "Enemy.h"
// makes the beginning and ending scenes
GameOverScene::GameOverScene(bool startScreen) {
	GameOverTextPtr text = std::make_shared<GameOverText>(startScreen);
	addGameObject(text);
}