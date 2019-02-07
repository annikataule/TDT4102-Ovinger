#include "std_lib_facilities.h"
#include "Card.h"

int main(){

#pragma region Task 1
	// a - d
	// Testing functions and mapping
	cout << suitToString(Suit::diamonds) << endl;
	cout << rankToString(Rank::ace) << endl;
	
	// e
	/*
	Det er lurt � bruke symboler fordi
		- Mindre sansynlighet for misforst�else
		- Lettere � lese koden til senere
	*/

#pragma endregion

#pragma region Task 2
	CardStruct card1 = { Suit::spades, Rank::ace };
	CardStruct card2 = { Suit::diamonds, Rank::ten };
	cout << toString(card1) << endl;
	cout << toStringShort(card2) << endl;


#pragma endregion

	Card c = Card(Suit::clubs, Rank::two);

	cout << c.toString() << endl;

	return 0;
}