#include "Player.h"

Player::Player(const string& name) :GenericPlayer(name) {}

Player::~Player() {}

bool Player::IsHitting() const {
	cout << _Name << ", do you want a hit? (Y/N): ";
	char response;
	cin >> response;
	return (response == 'y' || response == 'Y');
}

void Player::Win() const {
	cout << _Name << " wins.\n";
}

void Player::Lose() const {
	cout << _Name << " loses.\n";
}

void Player::Push() const {
	cout << _Name << " pushes.\n";
}