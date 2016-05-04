#include "bullet.h"

void Bullet::initBullet(int bullet_x, int bullet_y) {
	this->bullet_x = bullet_x;
	this->bullet_y = bullet_y;
	hit = false;
}

void Bullet::drawBullet() {
	al_draw_rectangle(bullet_x, bullet_y, bullet_x, bullet_y, al_map_rgb(120, 120, 120), 10);
}

void Bullet::moveBullet() {
	bullet_y -= 15;
}

void Bullet::bulletHit(bool hit) {
	this->hit = hit;
}

bool Bullet::isHit() {
	return hit;
}

int Bullet::positionX() {
	return bullet_x;
}

int Bullet::positionY() {
	return bullet_y;
}