#include "Card.h"


map<Suit, string> suitNames = { {Suit::clubs, "Clubs" },
								{Suit::diamonds, "Diamonds"},
								{Suit::hearts, "Hearts"},
								{Suit::spades, "Spades"} };

string suitToString(Suit s)
{
	return suitNames[s];
}

map<Rank, string> rankNames = { {Rank::two, "Two" },
								{Rank::three, "Three"},
								{Rank::four, "Four"},
								{Rank::five, "Five"},
								{Rank::six, "Six"},
								{Rank::seven, "Seven"},
								{Rank::eight, "Eight"},
								{Rank::nine, "Nine"},
								{Rank::ten, "Ten"},
								{Rank::jack, "Jack"},
								{Rank::queen, "Queen"},
								{Rank::king, "King"},
								{Rank::ace, "Ace"} };

string rankToString(Rank r) 
{
	return rankNames[r];
}

string toString(CardStruct card)
{
	return rankToString(card.rank) + " of " + suitToString(card.suit);
}

string toStringShort(CardStruct card) 
{
	string suit = suitToString(card.suit);
	string rank = to_string(int(card.rank));
	return suit.at(0) + rank;

}

#pragma region Card - Class

Card::Card()
{
	valid = false;
}

Card::Card(Suit suit, Rank rank)
{
	s = suit;
	r = rank;
	valid = true;
}

inline Suit Card::suit() { return s; }
inline Rank Card::rank() { return r; }
int Card::suitVal()
{
	return int(s);
}
int Card::rankVal()
{
	return int(r);
}
inline bool Card::isValid() { return valid; }

string Card::toString()
{
	if (valid)
		return rankToString(r) + " of " + suitToString(s);
	else
		return "Invalid card";
}

string Card::toStringShort()
{
	if (valid)
		return suitToString(s).at(0) + to_string(int(r));
	else
		return "Invalid card";
}

#pragma endregion
