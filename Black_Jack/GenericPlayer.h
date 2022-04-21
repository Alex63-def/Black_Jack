#ifndef __GENERICPLAYER_H__
#define __GENERICPLAYER_H__
#pragma once
#include "Hand.h"
#include <string>

class GenericPlayer : public Hand {
public:
	GenericPlayer(const string& name = "");

	virtual ~GenericPlayer();

	virtual bool IsHitting() const = 0;

	bool IsBoosted() const;

	void Bust() const;

	friend ostream& operator<< (ostream& out, const GenericPlayer& aGenericPlayer);

protected:
	string _Name;
};

#endif // __GENERICPLAYER_H__