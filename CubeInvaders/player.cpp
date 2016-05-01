#include "player.h"

void Player::initPlayer(int player_x, int player_y) {
	this->player_x = player_x;
	this->player_y = player_y;
}

void Player::moveLeft() {
	player_x -= 20;
}

void Player::moveRight() {
	player_x += 20;
}

void Player::drawPlayer() {
	al_draw_rectangle(player_x, player_y, player_x, player_y, al_map_rgb(120, 120, 120), 30);
}

int Player::positionX(){
	return player_x;
}

int Player::positionY() {
	return player_y;
}