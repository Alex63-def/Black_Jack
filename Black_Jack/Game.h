#ifndef __GAME_H__
#define __GAME_H__
#pragma once
#include "Deck.h"
#include "House.h"
#include "Player.h"

class Game {
public:
	Game(vector <string>& names);

	~Game();

	void Play();

private:
	Deck _Deck;
	House _House;
	vector<Player> _Players;
};

#endif // __GAME_H__