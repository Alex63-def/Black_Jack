#ifndef __HAND_H__
#define __HAND_H__
#pragma once
#include "Card.h"
#include <vector>
//using namespace std;

class Hand {
public:
	Hand();
	virtual ~Hand();

	void Add(Card* pCard);
	void Clear();
	int GetTotal() const;

protected:
	vector<Card*> _Cards;
};

#endif // __HAND_H__