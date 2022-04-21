#include "House.h"

House::House(const string& name) : GenericPlayer(name) {}

House::~House(){}

bool House::IsHitting() const {
	return (GetTotal() <= 16);
}

void House::FlipFirstCard() {
	if (!(_Cards.empty()))
		_Cards[0]->Flip();
	else
		cout << "No card to flip!\n";
}