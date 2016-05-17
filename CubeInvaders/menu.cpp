#include "menu.h"

void Menu::createMenu(ALLEGRO_FONT* font, ALLEGRO_FONT* font_start, ALLEGRO_EVENT_QUEUE* event_queue) {
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_text(font, al_map_rgb(255, 255, 255), 410, 50, ALLEGRO_ALIGN_CENTER, "CUBE INVADERS");
	al_draw_text(font_start, al_map_rgb(255, 255, 255), 400, 300, ALLEGRO_ALIGN_CENTER, "> Start game");
	al_draw_text(font_start, al_map_rgb(255, 255, 255), 400, 400, ALLEGRO_ALIGN_CENTER, "Options");
	al_flip_display();
	while (done==false) {
		al_wait_for_event(event_queue, &events);
			if (events.type == ALLEGRO_EVENT_KEY_DOWN) {
				switch (events.keyboard.keycode) {

				case ALLEGRO_KEY_DOWN:
					if (options == false) {
						al_clear_to_color(al_map_rgb(0, 0, 0));
						al_draw_text(font, al_map_rgb(255, 255, 255), 410, 50, ALLEGRO_ALIGN_CENTER, "CUBE INVADERS");
						al_draw_text(font_start, al_map_rgb(255, 255, 255), 400, 300, ALLEGRO_ALIGN_CENTER, "Start game");
						al_draw_text(font_start, al_map_rgb(255, 255, 255), 400, 400, ALLEGRO_ALIGN_CENTER, "> Options");
						al_flip_display();
						start_game = false;
					}
					if (options == true && enemies_amount == false && game_mode == false) {
						al_clear_to_color(al_map_rgb(0, 0, 0));
						al_draw_text(font, al_map_rgb(255, 255, 255), 410, 50, ALLEGRO_ALIGN_CENTER, "OPTIONS");
						al_draw_textf(font_start, al_map_rgb(255, 255, 255), 400, 300, ALLEGRO_ALIGN_CENTER, "Enemies speed: %d", e_speed);
						al_draw_textf(font_start, al_map_rgb(255, 255, 255), 400, 400, ALLEGRO_ALIGN_CENTER, "> Enemies amount: %d", e_amount);
						al_draw_textf(font_start, al_map_rgb(255, 255, 255), 400, 500, ALLEGRO_ALIGN_CENTER, "Game mode: %s", g_mode.c_str());
						al_flip_display();
						enemies_amount = true;
						enemies_speed = false;
						game_mode = false;
					}
					else if (options == true && enemies_amount == true) {
						al_clear_to_color(al_map_rgb(0, 0, 0));
						al_draw_text(font, al_map_rgb(255, 255, 255), 410, 50, ALLEGRO_ALIGN_CENTER, "OPTIONS");
						al_draw_textf(font_start, al_map_rgb(255, 255, 255), 400, 300, ALLEGRO_ALIGN_CENTER, "Enemies speed: %d", e_speed);
						al_draw_textf(font_start, al_map_rgb(255, 255, 255), 400, 400, ALLEGRO_ALIGN_CENTER, "Enemies amount: %d", e_amount);
						al_draw_textf(font_start, al_map_rgb(255, 255, 255), 400, 500, ALLEGRO_ALIGN_CENTER, "> Game mode: %s", g_mode.c_str());
						al_flip_display();
						enemies_amount = false;
						enemies_speed = false;
						game_mode = true;
					}
					break;
				
				case ALLEGRO_KEY_UP:
					if (options == false) {
						al_clear_to_color(al_map_rgb(0, 0, 0));
						al_draw_text(font, al_map_rgb(255, 255, 255), 410, 50, ALLEGRO_ALIGN_CENTER, "CUBE INVADERS");
						al_draw_text(font_start, al_map_rgb(255, 255, 255), 400, 300, ALLEGRO_ALIGN_CENTER, "> Start game");
						al_draw_text(font_start, al_map_rgb(255, 255, 255), 400, 400, ALLEGRO_ALIGN_CENTER, "Options");
						al_flip_display();
						start_game = true;
					}
					if ((options == true && enemies_amount == true) || (enemies_speed == true && options == true)) {
						al_clear_to_color(al_map_rgb(0, 0, 0));
						al_draw_text(font, al_map_rgb(255, 255, 255), 410, 50, ALLEGRO_ALIGN_CENTER, "OPTIONS");
						al_draw_textf(font_start, al_map_rgb(255, 255, 255), 400, 300, ALLEGRO_ALIGN_CENTER, "> Enemies speed: %d", e_speed);
						al_draw_textf(font_start, al_map_rgb(255, 255, 255), 400, 400, ALLEGRO_ALIGN_CENTER, "Enemies amount: %d", e_amount);
						al_draw_textf(font_start, al_map_rgb(255, 255, 255), 400, 500, ALLEGRO_ALIGN_CENTER, "Game mode: %s", g_mode.c_str());
						al_flip_display();
						enemies_speed = true;
						enemies_amount = false;
						game_mode = false;
						start_game = false;
					}
					else if (options == true && enemies_amount == false) {
						al_clear_to_color(al_map_rgb(0, 0, 0));
						al_draw_text(font, al_map_rgb(255, 255, 255), 410, 50, ALLEGRO_ALIGN_CENTER, "OPTIONS");
						al_draw_textf(font_start, al_map_rgb(255, 255, 255), 400, 300, ALLEGRO_ALIGN_CENTER, "Enemies speed: %d", e_speed);
						al_draw_textf(font_start, al_map_rgb(255, 255, 255), 400, 400, ALLEGRO_ALIGN_CENTER, "> Enemies amount: %d", e_amount);
						al_draw_textf(font_start, al_map_rgb(255, 255, 255), 400, 500, ALLEGRO_ALIGN_CENTER, "Game mode: %s", g_mode.c_str());
						al_flip_display();
						enemies_amount = true;
						enemies_speed = false;
						game_mode = false;
					}
					break;

				case ALLEGRO_KEY_LEFT:
					if (options == true && enemies_amount == true && enemies_speed == false) {
						al_clear_to_color(al_map_rgb(0, 0, 0));
						al_draw_text(font, al_map_rgb(255, 255, 255), 410, 50, ALLEGRO_ALIGN_CENTER, "OPTIONS");
						al_draw_textf(font_start, al_map_rgb(255, 255, 255), 400, 300, ALLEGRO_ALIGN_CENTER, "Enemies speed: %d", e_speed);
						al_draw_textf(font_start, al_map_rgb(255, 255, 255), 400, 400, ALLEGRO_ALIGN_CENTER, "> Enemies amount: %d", --e_amount);
						al_draw_textf(font_start, al_map_rgb(255, 255, 255), 400, 500, ALLEGRO_ALIGN_CENTER, "Game mode: %s", g_mode.c_str());
						al_flip_display();
					}
					if (options == true && enemies_amount == false && enemies_speed == true) {
						al_clear_to_color(al_map_rgb(0, 0, 0));
						al_draw_text(font, al_map_rgb(255, 255, 255), 410, 50, ALLEGRO_ALIGN_CENTER, "OPTIONS");
						al_draw_textf(font_start, al_map_rgb(255, 255, 255), 400, 300, ALLEGRO_ALIGN_CENTER, "> Enemies speed: %d", --e_speed);
						al_draw_textf(font_start, al_map_rgb(255, 255, 255), 400, 400, ALLEGRO_ALIGN_CENTER, "Enemies amount: %d", e_amount);
						al_draw_textf(font_start, al_map_rgb(255, 255, 255), 400, 500, ALLEGRO_ALIGN_CENTER, "Game mode: %s", g_mode.c_str());
						al_flip_display();
					}
					if (options == true && enemies_amount == false && enemies_speed == false) {
						g_mode = "single";
						al_clear_to_color(al_map_rgb(0, 0, 0));
						al_draw_text(font, al_map_rgb(255, 255, 255), 410, 50, ALLEGRO_ALIGN_CENTER, "OPTIONS");
						al_draw_textf(font_start, al_map_rgb(255, 255, 255), 400, 300, ALLEGRO_ALIGN_CENTER, "Enemies speed: %d", e_speed);
						al_draw_textf(font_start, al_map_rgb(255, 255, 255), 400, 400, ALLEGRO_ALIGN_CENTER, "Enemies amount: %d", e_amount);
						al_draw_textf(font_start, al_map_rgb(255, 255, 255), 400, 500, ALLEGRO_ALIGN_CENTER, "> Game mode: %s", g_mode.c_str());
						al_flip_display();
					}
					break;

				case ALLEGRO_KEY_RIGHT:
					if (options == true && enemies_amount == true && enemies_speed == false) {
						al_clear_to_color(al_map_rgb(0, 0, 0));
						al_draw_text(font, al_map_rgb(255, 255, 255), 410, 50, ALLEGRO_ALIGN_CENTER, "OPTIONS");
						al_draw_textf(font_start, al_map_rgb(255, 255, 255), 400, 300, ALLEGRO_ALIGN_CENTER, "Enemies speed: %d", e_speed);
						al_draw_textf(font_start, al_map_rgb(255, 255, 255), 400, 400, ALLEGRO_ALIGN_CENTER, "> Enemies amount: %d", ++e_amount);
						al_draw_textf(font_start, al_map_rgb(255, 255, 255), 400, 500, ALLEGRO_ALIGN_CENTER, "Game mode: %s", g_mode.c_str());
						al_flip_display();
					}
					if (options == true && enemies_amount == false && enemies_speed == true) {
						al_clear_to_color(al_map_rgb(0, 0, 0));
						al_draw_text(font, al_map_rgb(255, 255, 255), 410, 50, ALLEGRO_ALIGN_CENTER, "OPTIONS");
						al_draw_textf(font_start, al_map_rgb(255, 255, 255), 400, 300, ALLEGRO_ALIGN_CENTER, "> Enemies speed: %d", ++e_speed);
						al_draw_textf(font_start, al_map_rgb(255, 255, 255), 400, 400, ALLEGRO_ALIGN_CENTER, "Enemies amount: %d", e_amount);
						al_draw_textf(font_start, al_map_rgb(255, 255, 255), 400, 500, ALLEGRO_ALIGN_CENTER, "Game mode: %s", g_mode.c_str());
						al_flip_display();
					}
					if (options == true && enemies_amount == false && enemies_speed == false) {
						g_mode = "co-op";
						al_clear_to_color(al_map_rgb(0, 0, 0));
						al_draw_text(font, al_map_rgb(255, 255, 255), 410, 50, ALLEGRO_ALIGN_CENTER, "OPTIONS");
						al_draw_textf(font_start, al_map_rgb(255, 255, 255), 400, 300, ALLEGRO_ALIGN_CENTER, "Enemies speed: %d", e_speed);
						al_draw_textf(font_start, al_map_rgb(255, 255, 255), 400, 400, ALLEGRO_ALIGN_CENTER, "Enemies amount: %d", e_amount);
						al_draw_textf(font_start, al_map_rgb(255, 255, 255), 400, 500, ALLEGRO_ALIGN_CENTER, "> Game mode: %s", g_mode.c_str());
						al_flip_display();
					}
					break;

				case ALLEGRO_KEY_ENTER:
					if (start_game == true) {
						saveConfig(e_speed, e_amount, g_mode);
						done = true;
					}
					if (start_game == false) {
						al_clear_to_color(al_map_rgb(0, 0, 0));
						al_draw_text(font, al_map_rgb(255, 255, 255), 410, 50, ALLEGRO_ALIGN_CENTER, "OPTIONS");
						al_draw_textf(font_start, al_map_rgb(255, 255, 255), 400, 300, ALLEGRO_ALIGN_CENTER, "> Enemies speed: %d", e_speed);
						al_draw_textf(font_start, al_map_rgb(255, 255, 255), 400, 400, ALLEGRO_ALIGN_CENTER, "Enemies amount: %d", e_amount);
						al_draw_textf(font_start, al_map_rgb(255, 255, 255), 400, 500, ALLEGRO_ALIGN_CENTER, "Game mode: %s", g_mode.c_str());
						al_flip_display();
						enemies_speed = true;
						enemies_amount = false;
						game_mode = false;
						options = true;
					}
					break;
				
				case ALLEGRO_KEY_ESCAPE:
					al_clear_to_color(al_map_rgb(0, 0, 0));
					al_draw_text(font, al_map_rgb(255, 255, 255), 410, 50, ALLEGRO_ALIGN_CENTER, "CUBE INVADERS");
					al_draw_text(font_start, al_map_rgb(255, 255, 255), 400, 300, ALLEGRO_ALIGN_CENTER, "> Start game");
					al_draw_text(font_start, al_map_rgb(255, 255, 255), 400, 400, ALLEGRO_ALIGN_CENTER, "Options");
					al_flip_display();
					options = false;
					start_game = true;
					break;
				}
			}
	}
	done = false;
	start_game = true;
	options = false;
	enemies_amount = false;
	enemies_speed = false;
	game_mode = false;
}

void Menu::createWin(ALLEGRO_FONT* font) {
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_text(font, al_map_rgb(255, 255, 255), 410, 300, ALLEGRO_ALIGN_CENTER, "YOU WIN!");
	al_flip_display();
	al_rest(3.0);
}

void Menu::createLose(ALLEGRO_FONT* font) {
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_text(font, al_map_rgb(255, 255, 255), 410, 300, ALLEGRO_ALIGN_CENTER, "GAME OVER :C");
	al_flip_display();
	al_rest(3);
}
