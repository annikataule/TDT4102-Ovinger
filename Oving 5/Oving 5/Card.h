#pragma once
#include "std_lib_facilities.h"


enum class Suit { clubs, diamonds, hearts, spades };

enum class Rank { two = 2, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace };

string suitToString(Suit s);

string rankToString(Rank r);

struct CardStruct
{
	Suit suit;
	Rank rank;
};

string toString(CardStruct card);

string toStringShort(CardStruct card);

#pragma region Card - Class


class Card
{
public:
	Card();
	Card(Suit suit, Rank rank);

	Suit suit();
	Rank rank();
	bool isValid();
	string toString();
	string toStringShort();
private:
	Suit s;
	Rank r;
	bool valid;
};



#pragma endregion