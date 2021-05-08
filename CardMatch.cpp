#include <algorithm>
#include <time.h>
#include "CardMatch.h"
#include "CardComponent.h"

CardMatch::CardMatch()
{
}

CardMatch::CardMatch(int numOfColumns, int numOfRows)
{
	srand(time(NULL));
	winText = TextComponent("YOU WIN", PaletteColors::Green, 250, 250, Anchor::Center);
	winText.setVisible(false);
	matches = std::vector<std::vector<int>>();
	cards = std::vector<CardComponent*>();

	//generate col x row / 2 icons
	int iconCount = numOfColumns * numOfRows / 2;
	std::vector<std::vector<int>> iconVals = std::vector<std::vector<int>>();
	for (int i = 0; i < iconCount; i++) {
		bool iconInvalid = true;
		while (iconInvalid)
		{
			int val1 = rand() % 10;
			int val2 = rand() % 16;
			int val3 = rand() % 15;
			if (val3 >= val2) {
				val3++;
			}
			std::vector<int> iconVal = { val1, val2, val3 };
			iconInvalid = false;
			for (int j = 0; j < iconVals.size(); j++) {
				if (iconVal == iconVals[j]) {
					iconInvalid = true;
				}
			}
			if (!iconInvalid) {
				iconVals.push_back(iconVal);
			}
		}
	}
	int iconValsSize = iconVals.size();
	for (int i = 0; i < iconValsSize; i++) //each icon will now be in the array twice
	{
		iconVals.push_back(iconVals[i]);
	}

	std::random_shuffle(iconVals.begin(), iconVals.end());

	// calculate positions and sizes of cards
	double xmult = ((500.0 / (double)numOfColumns) * 0.9) / 100.0;
	double ymult = ((500.0 / (double)numOfRows) * 0.9) / 100.0;
	double iconMult = xmult * 0.8;
	if (ymult < xmult) {
		iconMult = ymult * 0.8;
	}
	double xOffset = 500 / (numOfColumns * 2);
	double yOffset = 500 / (numOfRows * 2);
	std::vector<std::vector<int>> positions;
	for (int i = 0; i < numOfColumns; i++) {
		for (int j = 0; j < numOfRows; j++) {
			std::vector<int> temp = {
				(int)((i * 2 + 1) * xOffset),
				(int)((j * 2 + 1) * yOffset)
			};
			positions.push_back(temp);
		}
	}

	// setup matches vector
	for (int i = iconVals.size()-1; i >= 0; i--) {
		bool alreadyInserted = false;
		for (int j = i; j < iconVals.size(); j++) { // check if this value will arleady be in the matches array
			if (iconVals[i] == iconVals[j] && i != j) {
				alreadyInserted = true;
			}
		}
		if (!alreadyInserted) {
			for (int j = i-1; j >= 0; j--) {
				if (iconVals[i] == iconVals[j]) {
					std::vector<int> temp = std::vector<int>();
					temp.push_back(iconVals.size() - i - 1);
					temp.push_back(iconVals.size() - j - 1);
					matches.push_back(temp);
				}
			}
		}
	}

	//initialize cards
	for (int i = 0; i < positions.size(); i++) {
		std::vector<int> pop = iconVals.back();
		iconVals.pop_back();
		Icon* tempIcon = new Icon(
			static_cast<Icons>(pop[0]),
			positions[i][0],
			positions[i][1],
			iconMult,
			static_cast<PaletteColors>(pop[1]),
			static_cast<PaletteColors>(pop[2]));
		CardComponent* temp = new CardComponent(
			*tempIcon,
			positions[i][0],
			positions[i][1],
			xmult,
			ymult,
			this
		);
		delete tempIcon;
		cards.push_back(temp);
	}
	for (int i = 0; i < cards.size(); i++) {
		cards[i]->flip();
	}
}

void CardMatch::cardClicked(CardComponent* card)
{
	int cardIndex;
	for (int i = 0; i < cards.size(); i++) {
		if (card == cards[i]) {
			cardIndex = i;
			break;
		}
	}
	if (firstCard == -1) {
		firstCard = cardIndex;
		return;
	}
	else if (secondCard == -1) {
		secondCard = cardIndex;
	}
	if (firstCard > secondCard) {
		int temp = secondCard;
		secondCard = firstCard;
		firstCard = temp;
	}
	int matchIndex = -1;
	for (int i = 0; i < matches.size(); i++) {
		if (matches[i][0] == firstCard) {
			matchIndex = i;
		}
	}
	if (matchIndex == -1 || matches[matchIndex][1] != secondCard) { //The two clicked cards dont match
		glutPostRedisplay();
		needsDelay = true;
		cardToFlip1 = firstCard;
		cardToFlip2 = secondCard;
	}
	else { // the two clicked cards match
		glutPostRedisplay();
		needsDelay = true;
		delete cards[firstCard];
		delete cards[secondCard];
		matches.erase(matches.begin() + matchIndex);
		if (matches.size() == 0) {
			winText.setVisible(true);
		}
	}
	firstCard = -1;
	secondCard = -1;
}

void CardMatch::DelayDone()
{
	if (cardToFlip1 != -1) {
		cards[cardToFlip1]->flip();
		cardToFlip1 = -1;
	}
	if (cardToFlip2 != -1) {
		cards[cardToFlip2]->flip();
		cardToFlip2 = -1;
	}
	glutPostRedisplay();
}


