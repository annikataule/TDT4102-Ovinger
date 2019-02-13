#include "std_lib_facilities.h"
#include "CardDeck.h"
#include "Blackjack.h"

int main(){

#pragma region Task 1
	// a - d
	// Testing functions and mapping
	//cout << suitToString(Suit::diamonds) << endl;
	//cout << rankToString(Rank::ace) << endl;
	
	// e
	/*
	Det er lurt å bruke symboler fordi
		- Mindre sansynlighet for misforståelse
		- Lettere å lese koden til senere
	*/

#pragma endregion

#pragma region Task 2
	/*
	CardStruct card1 = { Suit::spades, Rank::ace };
	CardStruct card2 = { Suit::diamonds, Rank::ten };
	cout << toString(card1) << endl;
	cout << toStringShort(card2) << endl;

	*/
#pragma endregion
	
	Card c = Card(Suit::clubs, Rank::two);

	cout << c.toString() << endl;
	
	
	CardDeck cD = CardDeck();

	cD.print();

	cD.shuffle();
	cD.printShort();

	for (int i = 0; i < 52; i++)
	{
		Card c = cD.drawCard();
		cout << c.toString() << endl;
	}
	

	Blackjack bJack = Blackjack();

	bJack.printCards();

	keep_window_open();
	return 0;
}