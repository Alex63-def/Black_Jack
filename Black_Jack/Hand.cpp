#include "Hand.h"

Hand::Hand() {
	_Cards.reserve(7);
}

Hand::~Hand() {
	Clear();
}

void Hand::Add(Card* pCard) {
	_Cards.push_back(pCard);
	}

void Hand::Clear() {
	vector<Card*> ::iterator iter = _Cards.begin();
	for (iter; iter != _Cards.end(); ++iter) {
		delete* iter;
		*iter = 0;
	}
	_Cards.clear();
}

int Hand::GetTotal() const {
	if (_Cards.empty())
		return 0;
	if (_Cards[0]->GetValue() == 0)
		return 0;

	int total = 0;
	vector<Card*>::const_iterator iter;
	for (iter = _Cards.begin(); iter != _Cards.end(); ++iter)
		total += (*iter)->GetValue();

	bool containsAce = false;
	for (iter = _Cards.begin(); iter != _Cards.end(); ++iter)
		if ((*iter)->GetValue() == Card::ACE)
			containsAce = true;

	if (containsAce && total <= 11)
		total += 10;

	return total;
}

