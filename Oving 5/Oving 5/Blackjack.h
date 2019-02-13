#pragma once
#include "CardDeck.h"

class Hand
{
public:
	Hand();
	Hand(bool dealer);
	void newCard(CardDeck& cards);
	void printCards();
	int sum();
private:
	void addValue();
	vector<Card> card;
	vector<int> cardsToShow;
	vector<int> total;
	bool d;
	int calculateSum();
};

class Blackjack
{
public:
	Blackjack();
	void printCards();
private:
	CardDeck cards;
	Hand player;
	Hand dealer;

};



