#include "Game.h"
#include <vector>
using namespace std;

Game::Game(vector<string>& names) {
	vector<string>::const_iterator pName;
	for (pName = names.begin(); pName != names.end(); ++pName)
		_Players.push_back(*pName);

	srand(static_cast<unsigned int>(time(0)));
	_Deck.Populate();
	_Deck.Shuffle();
}

Game::~Game() {}

void Game::Play() {
	vector<Player>::iterator pPlayer;
	for (int i = 0; i < 2; ++i) {
		for (pPlayer = _Players.begin(); pPlayer != _Players.end(); ++pPlayer)
			_Deck.Deal(*pPlayer);
		_Deck.Deal(_House);
	}

	_House.FlipFirstCard();

	for (pPlayer = _Players.begin(); pPlayer != _Players.end(); ++pPlayer)
		cout << *pPlayer << endl;

	cout << _House << endl;

	for (pPlayer = _Players.begin(); pPlayer != _Players.end(); ++pPlayer)
		_Deck.AddItionalCards(*pPlayer);

	_House.FlipFirstCard();
	cout << endl << _House;

	_Deck.AddItionalCards(_House);

	if (_House.IsBoosted()) {
		for (pPlayer = _Players.begin(); pPlayer != _Players.end(); ++pPlayer)
			if (!(pPlayer->IsBoosted()))
				pPlayer->Win();
	}
	else
		for (pPlayer = _Players.begin(); pPlayer != _Players.end(); ++pPlayer)
			if (!(pPlayer->IsBoosted())) {
				if (pPlayer->GetTotal() > _House.GetTotal())
					pPlayer->Win();
				else if (pPlayer->GetTotal() < _House.GetTotal())
					pPlayer->Lose();
				else
					pPlayer->Push();
			}

	for (pPlayer = _Players.begin(); pPlayer != _Players.end(); ++pPlayer)
		pPlayer->Clear();
	_House.Clear();
}