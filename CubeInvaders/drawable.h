#ifndef drawable_h
#define drawable_h
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

class Drawable {
protected:
	int size;
	int position_x;
	int position_y;
public:
	void draw();
	void moveLeft(int);
	void moveRight(int);
	void moveDown(int);
	void moveUp(int);
	int positionX();
	int positionY();
};

#endif