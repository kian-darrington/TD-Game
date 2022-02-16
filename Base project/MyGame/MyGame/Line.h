#pragma once
#include "Engine/GameEngine.h"

class Line : public GameObject {
public:
	Line(int type, sf::Vector2f pos);
	void draw();
	void update(sf::Time& elapsed);
	void changePos(sf::Vector2f pos);
	sf::FloatRect getCollisionRect();
private:
	sf::Sprite sprite_;
	int linetype_;
};

typedef std::shared_ptr<Line> LinePtr;