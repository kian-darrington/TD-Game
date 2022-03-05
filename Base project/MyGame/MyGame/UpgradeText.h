#pragma once
#include "Engine/GameEngine.h"

class UpgradeText : public GameObject {
public:
	UpgradeText(int level, float range, float attack, int power, int money);
	void draw();
	void update(sf::Time& elapsed);
	void handleEvent(sf::Event& eve);
private:
	int moneySpent_;
	int power_;
	int level_;
	float range_;
	float attack_;
	sf::Text text_;
};

typedef std::shared_ptr<UpgradeText> UpgradeTextPtr;