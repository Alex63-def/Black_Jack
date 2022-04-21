#include "GenericPlayer.h"
using namespace std;

GenericPlayer::GenericPlayer(const string& name) : _Name(name) {}

GenericPlayer::~GenericPlayer(){}

bool GenericPlayer::IsBoosted() const {
		return (GetTotal() > 21);
}

void GenericPlayer::Bust() const {
	cout << _Name << " busts.\n";
}

ostream& operator<< (ostream& out, const GenericPlayer& aGenericPlayer) {
	out << aGenericPlayer._Name << ":\t";

	vector<Card*>::const_iterator pCard;
	if (!aGenericPlayer._Cards.empty()) {
		for (pCard = aGenericPlayer._Cards.begin(); pCard != aGenericPlayer._Cards.end(); ++pCard)
			out << *(*pCard) << "\t";
		if (aGenericPlayer.GetTotal() != 0)
			cout << "(" << aGenericPlayer.GetTotal() << ")";
	}
	else
		out << "<empty";

	return out;
}