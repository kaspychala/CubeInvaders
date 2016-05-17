#ifndef player_h
#define player_h
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "drawable.h"

class Player : public Drawable{
protected:
	bool shoot;
public:
	void initPlayer(int, int, int);
	void shootPlayer(bool);
	bool isShoot();
};

#endif
