#pragma once
#include <vector>
#include <thread>
#include "TextComponent.h"

class CardComponent;

class CardMatch
{
public:
	CardMatch();
	CardMatch(int numOfColumns, int numOfRows);
	void cardClicked(CardComponent* card);
	bool needsDelay;
	void DelayDone();
private:
	std::vector<CardComponent*> cards;
	std::vector<std::vector<int>> matches;
	int firstCard = -1;
	int secondCard = -1;
	TextComponent winText;
	int cardToFlip1;
	int cardToFlip2;
};

