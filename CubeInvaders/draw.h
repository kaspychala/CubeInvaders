#ifndef draw_h
#define draw_h
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

class Draw {
protected:
	int position_x;
	int position_y;
public:
	void draw();
	void moveLeft(int);
	void moveRight(int);
	void moveDown(int);
	int positionX();
	int positionY();
};

#endif