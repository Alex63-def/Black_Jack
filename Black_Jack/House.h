#ifndef __HOUSE_H__
#define __HOUSE_H__
#pragma once
#include "GenericPlayer.h"

class House : public GenericPlayer {
public:
	House(const string& name = "House");

	virtual ~House();

	virtual bool IsHitting() const;

	void FlipFirstCard();
};

#endif // __HOUSE_H__