#include "opponent.h"

void Opponent::initOpponent(int opponent_x, int opponent_y) {
	this->opponent_x = opponent_x;
	this->opponent_y = opponent_y;
}

void Opponent::drawOpponent() {
	al_draw_rectangle(opponent_x, opponent_y, opponent_x, opponent_y, al_map_rgb(120, 120, 120), 30);
}

void Opponent::moveLeft(int speed) {
	opponent_x -= speed;
}

void Opponent::moveRight(int speed) {
	opponent_x += speed;
}


void Opponent::moveDown(int speed) {
	opponent_y += speed;
}

int Opponent::positionX() {
	return opponent_x;
}

int Opponent::positionY() {
	return opponent_y;
}