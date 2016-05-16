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
	bool left_to_right = true;
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
	Player player2;
	player.initPlayer(400, 500);
	if (save.gameMode() == "co-op") {
		player.initPlayer(200, 500);
		player2.initPlayer(600, 500);
	}
	Bullet bullet;
	Bullet bullet2;
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

			case ALLEGRO_KEY_A:
				player.moveLeft(20);
				break;

			case ALLEGRO_KEY_D:
				player.moveRight(20);
				break;

			case ALLEGRO_KEY_SPACE:
				if (player.isShoot() == false) {
					bullet.initBullet(player.positionX(), player.positionY());
					player.shootPlayer(true);
				}
				break;
			
			if (save.gameMode() == "co-op") {

				case ALLEGRO_KEY_LEFT:
					player2.moveLeft(20);
					break;

				case ALLEGRO_KEY_RIGHT:
					player2.moveRight(20);
					break;
			
				case ALLEGRO_KEY_PAD_0:
					if (player2.isShoot() == false) {
						bullet2.initBullet(player2.positionX(), player2.positionY());
						player2.shootPlayer(true);
					}
					break;
			}

			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			}
		}
		if (events.type == ALLEGRO_EVENT_TIMER) {
			bullet.moveBullet();
			if (save.gameMode() == "co-op") {
				bullet2.moveBullet();
			}
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
			if (player.isShoot() == true && bullet.isHit() == false) {
				for (int i = 0; i < save.opponentAmount(); i++) {
					if ((bullet.positionX() >= opponent[i].positionX() - 10 && bullet.positionX() <= opponent[i].positionX() + 10) && (bullet.positionY() <= opponent[i].positionY() +10 && bullet.positionY() >= opponent[i].positionY()-10) && opponentHit[i] == false) {
						opponentHit[i] = true;
						bullet.bulletHit(true);
						score++;
					}
				}
			}
			if (save.gameMode() == "co-op") {
				if (player2.isShoot() == true && bullet2.isHit() == false) {
					for (int i = 0; i < save.opponentAmount(); i++) {
						if ((bullet2.positionX() >= opponent[i].positionX() - 10 && bullet2.positionX() <= opponent[i].positionX() + 10) && (bullet2.positionY() <= opponent[i].positionY() + 10 && bullet2.positionY() >= opponent[i].positionY() - 10) && opponentHit[i] == false) {
							opponentHit[i] = true;
							bullet2.bulletHit(true);
							score++;
						}
					}
				}
			}
		}
		al_clear_to_color(al_map_rgb(0, 0, 0));
		player.draw();
		if (save.gameMode() == "co-op") {
			player2.draw();
		}
		for (int i = 0; i < save.opponentAmount(); i++) {
			if (opponentHit[i] == false) {
				opponent[i].draw();
			}
		}
		if ((player.isShoot() == true && bullet.isHit() == false)) {
			bullet.drawBullet();
			if (bullet.positionY() < -20) {
				bullet.initBullet(player.positionX(), player.positionY());
				player.shootPlayer(false);
			}
		}
		if (bullet.isHit() == true) {
			bullet.initBullet(player.positionX(), player.positionY());
			bullet.bulletHit(false);
			player.shootPlayer(false);
		}
		if (save.gameMode() == "co-op") {
			if ((player2.isShoot() == true && bullet2.isHit() == false)) {
				bullet2.drawBullet();
				if (bullet2.positionY() < -20) {
					bullet2.initBullet(player2.positionX(), player2.positionY());
					player2.shootPlayer(false);
				}
			}
			if (bullet2.isHit() == true) {
				bullet2.initBullet(player2.positionX(), player2.positionY());
				bullet2.bulletHit(false);
				player2.shootPlayer(false);
			}
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