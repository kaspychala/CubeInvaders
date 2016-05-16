#ifndef opponent_h
#define opponent_h
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "draw.h";

class Opponent : public Draw {
protected:
public:
	void initOpponent(int, int);
};

#endif