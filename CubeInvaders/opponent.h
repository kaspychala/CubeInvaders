#ifndef opponent_h
#define opponent_h
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

class Opponent {
protected:
	int opponent_x;
	int opponent_y;
public:
	void initOpponent(int, int);
	void drawOpponent();
	void moveLeft(int);
	void moveRight(int);
	void moveDown(int);
	int positionX();
	int positionY();
};

#endif