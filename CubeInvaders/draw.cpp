#include "draw.h"


void Draw::draw() {
	al_draw_rectangle(position_x, position_y, position_x, position_y, al_map_rgb(120, 120, 120), 30);
}

void Draw::moveLeft(int speed) {
	position_x -= speed;
}

void Draw::moveRight(int speed) {
	position_x += speed;
}

void Draw::moveDown(int speed) {
	position_y += speed;
}

int Draw::positionX() {
	return position_x;
}

int Draw::positionY() {
	return position_y;
}