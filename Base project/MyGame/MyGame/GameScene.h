#pragma once

#include "Engine/GameEngine.h"

class GameScene : public Scene {
 public:
  // Creates our Scene.
  GameScene();
  void setLevelOne();
  void increaseMoney();
  void decreaseLives(int layer);
  void increaseDangerLevel();
  int getLives();
  int getMoney();
  int getDangerLevel();
private:
	int lives_ = 100;
	int money_ = 0;
	int dangerLevel_ = 1;
};

typedef std::shared_ptr<GameScene> GameScenePtr;
