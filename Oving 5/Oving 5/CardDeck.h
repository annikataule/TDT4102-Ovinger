#pragma once
#include "Card.h"

class CardDeck
{
public:
	CardDeck();
	void print();
	void printShort();
	void shuffle(int depth = 10000);
	const Card& drawCard();
private:
	vector<Card> cards;
	int currentCardIndex;
	void swap(int fromIndex, int toIndex);

};

