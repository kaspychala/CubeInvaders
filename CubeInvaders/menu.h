#ifndef menu_h
#define menu_h
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <string>
#include "save.h"

class Menu: public Save {
protected:
	ALLEGRO_EVENT events;
	bool done = false;
	bool start_game = true;
	bool options = false;
	bool enemies_amount = false;
	bool enemies_speed = false;
	bool game_mode = false;
	int e_speed = opponentSpeed();
	int e_amount = opponentAmount();
	std::string g_mode = gameMode();
public:
	void createMenu(ALLEGRO_FONT* font, ALLEGRO_FONT* font_start, ALLEGRO_EVENT_QUEUE* event_queue);
	void createWin(ALLEGRO_FONT* font);
	void createLose(ALLEGRO_FONT* font);
};
#endif