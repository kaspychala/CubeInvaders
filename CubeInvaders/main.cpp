#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <vector>
#include "menu.h"
#include "player.h"
#include "opponent.h"
#include "bullet.h"

int main()
{
	////////////////////////////////////////////////////////
	//////VARIABLES INITIALIZATION
	////////////////////////////////////////////////////////
	const float FPS = 60;
	bool bulletHit = false;
	bool left_to_right = true;
	bool fire = false;
	int score = 0;
	int positionX = 100;
	int positionY = 100;
	bool done = false;
	/////////////////////////////////////////////////////////
	//////ALLEGRO INITIALIZATION
	/////////////////////////////////////////////////////////
	al_init();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();
	al_install_keyboard();
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	ALLEGRO_TIMER *timer = timer = al_create_timer(1.0 / FPS);
	ALLEGRO_DISPLAY* display = al_create_display(800, 600);
	ALLEGRO_FONT* font = al_load_font("space_invaders.ttf", 60, NULL);
	ALLEGRO_FONT* font_start = al_load_font("space_invaders.ttf", 20, NULL);
	ALLEGRO_FONT* font_score = al_load_font("space_invaders.ttf", 20, NULL);
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_start_timer(timer);
	////////////////////////////////////////////////////////
	//////MENU, SAVE, PLAYER, BULLET INITIALIZATION
	////////////////////////////////////////////////////////
	Menu menu;
	menu.createMenu(font, font_start, event_queue);
	Save save;
	Player player;
	player.initPlayer(400, 500);
	Bullet bullet;
	////////////////////////////////////////////////////////
	//////OPPONENT INITIALIZATION
	////////////////////////////////////////////////////////
	std::vector <Opponent> opponent;
	std::vector <bool> opponentHit;
	for (int i = 0; i < save.opponentAmount(); i++) {
		opponentHit.push_back(false);
	}
	for (int i = 0; i < save.opponentAmount(); i++) {
		opponent.push_back(Opponent());
	}
	for (int i = 0; i < save.opponentAmount(); i++) {
		opponent[i].initOpponent(positionX, positionY);
		positionX += 50;
		if (positionX > 660) {
			positionX = 100;
			positionY += 40;
		}
	}
	////////////////////////////////////////////////////////
	//////GAME
	////////////////////////////////////////////////////////
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();
	while (done == false) {
		ALLEGRO_EVENT events;
		al_wait_for_event(event_queue, &events);
		if (events.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (events.keyboard.keycode) {

			case ALLEGRO_KEY_LEFT:
				player.moveLeft();
				break;

			case ALLEGRO_KEY_RIGHT:
				player.moveRight();
				break;

			case ALLEGRO_KEY_SPACE:
				if (fire == false) {
					bullet.initBullet(player.positionX(), player.positionY());
					fire = true;
				}
				break;

			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			}
		}
		if (events.type == ALLEGRO_EVENT_TIMER) {
			bullet.moveBullet();
			if (left_to_right == true) {
				for (int i = 0; i < save.opponentAmount(); i++) {
					opponent[i].moveRight(save.opponentSpeed());
				}
			}
			if (left_to_right == false) {
				for (int i = 0; i < save.opponentAmount(); i++) {
					opponent[i].moveLeft(save.opponentSpeed());
				}
			}
			if (save.opponentAmount() >= 12) {
				if (opponent[10].positionX() > 720) {
					for (int i = 0; i < save.opponentAmount(); i++) {
						opponent[i].moveDown(20);
					}
					left_to_right = false;
				}
			}
			else {
				if (opponent[save.opponentAmount() - 1].positionX() > 740) {
					for (int i = 0; i < save.opponentAmount(); i++) {
						opponent[i].moveDown(20);
					}
					left_to_right = false;
				}
			}
			if (opponent[0].positionX() < 40) {
				for (int i = 0; i < save.opponentAmount(); i++) {
					opponent[i].moveDown(20);
				}
				left_to_right = true;
			}
			if (fire == true && bulletHit == false) {
				for (int i = 0; i < save.opponentAmount(); i++) {
					if ((bullet.positionX() >= opponent[i].positionX() - 10 && bullet.positionX() <= opponent[i].positionX() + 10) && (bullet.positionY() <= opponent[i].positionY() +10 && bullet.positionY() >= opponent[i].positionY()-10) && opponentHit[i] == false) {
						opponentHit[i] = true;
						bulletHit = true;
						score++;
					}
				}
			}
		}
		al_clear_to_color(al_map_rgb(0, 0, 0));
		player.drawPlayer();
		for (int i = 0; i < save.opponentAmount(); i++) {
			if (opponentHit[i] == false) {
				opponent[i].drawOpponent();
			}
		}
		if ((fire == true && bulletHit == false)) {
			bullet.drawBullet();
			if (bullet.positionY() < -20) {
				bullet.initBullet(player.positionX(), player.positionY());
				fire = false;
			}
		}
		if (bulletHit == true) {
			bullet.initBullet(player.positionX(), player.positionY());
			bulletHit = false;
			fire = false;
		}
		al_draw_textf(font_score, al_map_rgb(255, 255, 255), 60, 10, ALLEGRO_ALIGN_CENTER, "Score: %d", score);
		al_flip_display();
		if (score == save.opponentAmount()) {
			menu.createWin(font);
			done = true;
		}
		if (opponent[save.opponentAmount()/2].positionY() > 460) {
			menu.createLose(font);
			done = true;
		}
	}
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	al_destroy_font(font);
	al_destroy_font(font_start);
	al_destroy_font(font_score);
	return 0;
}