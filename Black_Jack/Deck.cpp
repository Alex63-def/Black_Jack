#include "Deck.h"
#include <algorithm>

Deck::Deck() {
	_Cards.reserve(52);
	Populate();
}

Deck::~Deck() {}

void Deck::Populate() {
	Clear();
	for (int s = Card::CLUBS; s <= Card::SPADES; ++s)
		for (int r = Card::ACE; r <= Card::KING; ++r)
			Add(new Card(static_cast<Card::Rank>(r), static_cast<Card::Suit>(s)));
}

void Deck::Shuffle() {
//srand(static_cast<unsigned int>(time(0)));
	random_shuffle(_Cards.begin(), _Cards.end());
}

void Deck::Deal(Hand& aHand) {
	if (!_Cards.empty()) {
		aHand.Add(_Cards.back());
		_Cards.pop_back();
	}
	else
		cout << "Out of cards. Unable to deal.";
}

void Deck::AddItionalCards(GenericPlayer& aGenericPlayer) {
	cout << endl;

	while (!(aGenericPlayer.IsBoosted()) && aGenericPlayer.IsHitting()) {
		Deal(aGenericPlayer);
		cout << aGenericPlayer << endl;

		if (aGenericPlayer.IsBoosted())
			aGenericPlayer.Bust();
	}
}