#ifndef __DECK_H__
#define __DECK_H__
#pragma once
#include "Hand.h"
#include "GenericPlayer.h"

class Deck : public Hand {
public:
	Deck();

	virtual ~Deck();

	void Populate();

	void Shuffle();
	
	void Deal(Hand& aHand);
	
	void AddItionalCards(GenericPlayer& aGenericPlayer);
};

#endif // __DECK_H__