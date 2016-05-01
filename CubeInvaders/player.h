#ifndef player_h
#define player_h
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

class Player{
protected:
	int player_x;
	int player_y;
public:
	void initPlayer(int, int);
	void moveLeft();
	void moveRight();
	void drawPlayer();
	int positionX();
	int positionY();
};

#endif
