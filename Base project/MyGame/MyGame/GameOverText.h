#pragma once
#include "Engine/GameEngine.h"

class GameOverText : public GameObject {
public:
	GameOverText();
	void draw();
	void update(sf::Time& elapsed);
private:
	sf::Text text_;
};

typedef std::shared_ptr<GameOverText> GameOverTextPtr;