#include "player.h"

void Player::initPlayer(int player_x, int player_y, int size) {
	this->position_x = player_x;
	this->position_y = player_y;
	this->size = size;
	shoot = false;
}

void Player::shootPlayer(bool shoot) {
	this->shoot = shoot;
}

bool Player::isShoot() {
	return shoot;
}