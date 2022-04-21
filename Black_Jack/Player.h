#ifndef __PLAYER_H__
#define __PLAYER_H__
#pragma once
#include "GenericPlayer.h"

class Player : public GenericPlayer {
public:
	Player(const string& name = "");

	virtual ~Player();

	virtual bool IsHitting() const;

	void Win() const;
	
	void Lose() const;
	
	void Push() const;
};

#endif // __PLAYER_H__