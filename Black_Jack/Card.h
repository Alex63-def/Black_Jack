#ifndef __CARD_H__
#define __CARD_H__
#pragma once
#include <iostream>
using namespace std;

class Card {
public:
	enum Suit {
		CLUBS, DIAMONDS, HEARTS, SPADES
	};

	enum Rank {
		ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
		JACK, QUEEN, KING
	};

	Card(Rank r = ACE, Suit s = SPADES, bool ifu = true);

	void Flip();
	int GetValue() const;
	friend ostream& operator<< (ostream& out, const Card& aCard);

private:
	bool _IsFaceUp;
	Suit _Suit;
	Rank _Rank;
};

#endif // __CARD_H__