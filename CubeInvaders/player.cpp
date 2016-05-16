#include "player.h"

void Player::initPlayer(int player_x, int player_y) {
	this->position_x = player_x;
	this->position_y = player_y;
	shoot = false;
}

void Player::shootPlayer(bool shoot) {
	this->shoot = shoot;
}

bool Player::isShoot() {
	return shoot;
}