#include "Card.h"

Card::Card(Rank r, Suit s, bool ifu) :_Rank(r), _Suit(s), _IsFaceUp(ifu) {}

void Card::Flip() { 
	_IsFaceUp = !(_IsFaceUp);
}

int Card::GetValue() const { 
	int value = 0;
	if (_IsFaceUp) {
		value = _Rank;
		if (value > 10)
			value = 10;
	}
	return value;
}

ostream& operator<< (ostream& out, const Card& aCard) {
	const string RANKS[] = {
		"0", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"
	};
	const string SUITS[] = {
		"c", "d", "h", "s"
	};

	if (aCard._IsFaceUp)
		out << RANKS[aCard._Rank] << SUITS[aCard._Suit];
	else
		out << "??";

	return out;
}


