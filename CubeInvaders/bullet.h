#ifndef bullet_h
#define bullet_h
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "drawable.h"

class Bullet : public Drawable{
protected:
	bool hit;
public:
	void initBullet(int, int, int);
	void bulletHit(bool);
	bool isHit();
};

#endif