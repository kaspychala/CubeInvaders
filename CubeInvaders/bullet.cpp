#include "bullet.h"

void Bullet::initBullet(int bullet_x, int bullet_y, int size) {
	this->position_x = bullet_x;
	this->position_y = bullet_y;
	this->size = size;
	hit = false;
}

void Bullet::bulletHit(bool hit) {
	this->hit = hit;
}

bool Bullet::isHit() {
	return hit;
}