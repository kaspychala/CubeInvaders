#ifndef bullet_h
#define bullet_h
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

class Bullet {
protected:
	bool hit;
	int bullet_x;
	int bullet_y;
public:
	void initBullet(int, int);
	void drawBullet();
	void moveBullet();
	void bulletHit(bool);
	bool isHit();
	int positionX();
	int positionY();

};

#endif