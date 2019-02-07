#include "CardDeck.h"
#include "utilities.h"

CardDeck::CardDeck()
{
	currentCardIndex = 0;
	for (int s = 0; s < 4; s++)
	{
		for (int r = 2; r < 2 + 13; r++)
		{
			cards.push_back(Card((Suit)s, (Rank)r));
		}
	}
}

void CardDeck::swap(int fromIndex, int toIndex)
{
	Card c = cards[fromIndex];
	cards[fromIndex] = cards[toIndex];
	cards[toIndex] = c;
}

void CardDeck::print()
{
	for (Card c : cards) 
	{
		cout << c.toString() << endl;
	}
}

void CardDeck::printShort()
{
	for (Card c : cards)
	{
		cout << c.toStringShort() << endl;
	}
}

void CardDeck::shuffle(int depth)
{
	srand(static_cast<unsigned int>(time(nullptr)));
	for (int i = 0; i < depth; i++)
	{
		swap(randomWithLimits(0, cards.size() - 1), randomWithLimits(0, cards.size() - 1));
	}
	
}

const Card& CardDeck::drawCard()
{
	++currentCardIndex;
	return cards[currentCardIndex - 1];
}
