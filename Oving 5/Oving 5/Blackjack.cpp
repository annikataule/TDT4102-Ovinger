#include "Blackjack.h"
#include "Card.h"

Blackjack::Blackjack()
{
	cards = CardDeck();
	cards.shuffle();

	
	player = Hand();
	dealer = Hand(true);

	for (int i = 0; i < 2; i++)
	{
		player.newCard(cards);
		dealer.newCard(cards);
	}

}

void Blackjack::printCards()
{
	cout << flush;
	dealer.printCards();
	cout << endl;
	player.printCards();
}

Hand::Hand()
{
	d = false;
}

Hand::Hand(bool dealer)
{
	d = dealer;
}

void Hand::newCard(CardDeck & cards)
{
	card.push_back(cards.drawCard());
	addValue();
}

/*
void Hand::addValue()
{
	Card c = card.back();
	int value = int(c.rankVal());
}
*/


void Hand::addValue()
{
	Card c = card.back();
	int valueOfCard = c.rankVal();
	if (valueOfCard >= 2 && valueOfCard <= 10)
		total.push_back(valueOfCard);
	else if (valueOfCard < 14)
		total.push_back(10);
	else if (valueOfCard == 14)
	{
		if (!d)
		{
			cout << "Do you want the ace to be 1 or 11? ";
			int aceVal;
			cin >> aceVal;
			if (aceVal > 11 || aceVal > 5)
				aceVal = 11;
			else if (aceVal <= 5)
				aceVal = 1;
			total.push_back(aceVal);
		}
		else
			total.push_back(11);
	}
	
}

void Hand::printCards()
{
	for (int i = 0; i < card.size(); ++i)
	{
		if (d && i > 0)
			cout << "Hidden dealer cards!" << endl;
		else
			cout << card[i].toString() << " \tValue: " << total[i] << endl;
	}
}

int Hand::sum()
{
	return calculateSum();
}



int Hand::calculateSum()
{
	int t = 0;
	for (int i : total)
	{
		t += i;
	}
	return t;
}
