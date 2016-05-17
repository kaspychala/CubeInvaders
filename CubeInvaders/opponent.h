#ifndef opponent_h
#define opponent_h
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "drawable.h"

class Opponent : public Drawable {
protected:
public:
	void initOpponent(int, int, int);
};

#endif