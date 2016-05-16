#ifndef player_h
#define player_h
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "draw.h";

class Player : public Draw{
protected:
	bool shoot;
public:
	void initPlayer(int, int);
	void shootPlayer(bool);
	bool isShoot();
};

#endif
