#include "drawable.h"


void Drawable::draw() {
	al_draw_rectangle(position_x, position_y, position_x, position_y, al_map_rgb(120, 120, 120), size);
}

void Drawable::moveLeft(int speed) {
	position_x -= speed;
}

void Drawable::moveRight(int speed) {
	position_x += speed;
}

void Drawable::moveDown(int speed) {
	position_y += speed;
}

void Drawable::moveUp(int speed) {
	position_y -= speed;
}

int Drawable::positionX() {
	return position_x;
}

int Drawable::positionY() {
	return position_y;
}