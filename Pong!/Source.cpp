#include <stdio.h>
#include <iostream>
#include <ctime>
#include <allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>
#include<allegro5/allegro_audio.h>
#include<allegro5/allegro_acodec.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_ttf.h>

using namespace std;


// constants
bool collision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);
const float FPS = 60; //speed of game
const int SCREEN_W = 1920; //width of screen
const int SCREEN_H = 1080; // height of screen
const int PLAYER_HEIGHT = 256; //player height

const int BALL_SIZE = 32;  // ball width and height

int Player1Score;
int Player2Score;
int HitCounter;
int PLAYER_WIDTH = 32; //player width

enum MYKEYS { // keys
	KEY_UP, KEY_DOWN, KEY_W, KEY_S
};
double speed=1;
int main(int argc, char **argv){ // main
	

	ALLEGRO_DISPLAY *display = NULL; //Display
	ALLEGRO_EVENT_QUEUE *event_queue = NULL; // Event
	ALLEGRO_TIMER *timer = NULL; // Timer
	ALLEGRO_SAMPLE*sample = NULL; // Ball Bouncing off paddle sound
	ALLEGRO_BITMAP *player1 = NULL; // player 1
	ALLEGRO_BITMAP *player2 = NULL; // player 2
	ALLEGRO_BITMAP *ball= NULL; // ball


	float player1_x = 1920 - PLAYER_WIDTH; // player 1 x
	float player1_y = SCREEN_H / 2.0 - PLAYER_HEIGHT / 2.0; // player 1 y
	float player2_x = 0; // player 2 x
	float player2_y = SCREEN_H / 2.0 - PLAYER_HEIGHT / 2.0; // player 2 y
	float ball_x = SCREEN_W / 2.0 - BALL_SIZE / 2.0; // ball x
	float ball_y = SCREEN_H / 2.0 - BALL_SIZE / 2.0; // ball y
	float ball_dx = -10.0, ball_dy = 10.0;

	
	bool key[4] = { false, false, false, false };
	bool redraw = true;
	bool doexit = false;

	if (!al_init()) { // initializes, if not print failed to initialize
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}

	if (!al_install_keyboard()) {// initializes keyboard, with error print
		fprintf(stderr, "failed to initialize the keyboard!\n");
		return -1;
	}

	if (!al_init_font_addon()) {
		fprintf(stderr, "failed to initialize the font addon!\n");
		return -1;
	}
	
	if (!al_init_ttf_addon()) {
		fprintf(stderr, "failed to initialize the TTF addon!\n");
		return -1;
	}

	ALLEGRO_FONT*font = al_load_ttf_font("zig.ttf", 46, 0); // creates the first addon font
	if (!font) {
		fprintf(stderr, "failed to initialize the font!\n");
	}

	if (!al_init_acodec_addon()) {
		fprintf(stderr, "failed to initialize the sound acodec!\n");
	}

	if (al_install_audio()) {
		fprintf(stderr, "failed to initialize the audio!\n");
	}

	if (!al_reserve_samples(1)) {
		fprintf(stderr, "failed to initialize the Sound sample!\n");
	}


	timer = al_create_timer(1.0 / FPS); // creates timer , with error print
	if (!timer) {
		fprintf(stderr, "failed to create timer!\n");
		return -1;
	}

	display = al_create_display(SCREEN_W, SCREEN_H); // creates display, with error print
	if (!display) { 
		fprintf(stderr, "failed to create display!\n");
		al_destroy_timer(timer);
		return -1;
	}

	player1 = al_create_bitmap(PLAYER_WIDTH, PLAYER_HEIGHT); // creates player 1 with error print
	if (!player1) {
		fprintf(stderr, "failed to create Player 1 bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}
	player2 = al_create_bitmap(PLAYER_WIDTH, PLAYER_HEIGHT); // creates player 2 with error print
	if (!player2) {
		fprintf(stderr, "failed to create Player 2 bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);

		return -1;
	}
	ball = al_create_bitmap(BALL_SIZE, BALL_SIZE); // creates ball with error print
	if (!ball) {
		fprintf(stderr, "failed to create ball bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}
	
	//creates player 1 bitmap
	al_set_target_bitmap(player1);

	al_clear_to_color(al_map_rgb(255, 255, 255)); // changes player 1's color

	al_set_target_bitmap(al_get_backbuffer(display));

	//creates plaer 2 bitmap
	al_set_target_bitmap(player2);

	al_clear_to_color(al_map_rgb(255, 255, 255)); // changes player 2's color

	al_set_target_bitmap(al_get_backbuffer(display));

	//creates ball bitmap
	al_set_target_bitmap(ball);

	al_clear_to_color(al_map_rgb(255, 255, 255)); // changes ball's color

	al_set_target_bitmap(al_get_backbuffer(display));


	event_queue = al_create_event_queue(); // creates event queue, if error prints error and destroys bitmaps, display, and timer
	if (!event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");
		al_destroy_bitmap(player1); // destroys player 1
		al_destroy_bitmap(player2); // destroys player 2
		al_destroy_bitmap(ball); // destroys ball
		al_destroy_display(display); // destroys display
		al_destroy_timer(timer); // destroys timer
		return -1;
	}

	al_register_event_source(event_queue, al_get_display_event_source(display)); // registers event queue

	al_register_event_source(event_queue, al_get_timer_event_source(timer)); // registers timer

	al_register_event_source(event_queue, al_get_keyboard_event_source()); // registers keyboard input

	al_clear_to_color(al_map_rgb(0, 0, 0)); // background color

	al_flip_display();

	al_start_timer(timer); // starts timer

	while (!doexit)
	{
		ALLEGRO_EVENT ev; //ev is the allegro event
		al_wait_for_event(event_queue, &ev); // starts if event is made

		if (ev.type == ALLEGRO_EVENT_TIMER) { // game loop
			if (collision(player2_x, player2_y, PLAYER_WIDTH, PLAYER_HEIGHT, ball_x, ball_y, 32, 32) == true) {
				HitCounter++;
				if (HitCounter >= 5) {
					speed++;
					ball_dx = speed;
					HitCounter = 0;
					cout << speed << endl;
					PLAYER_WIDTH + 1;

				}
				ball_dx = -ball_dx;
				al_play_sample(sample, 1.0, 0.0, 1.5, ALLEGRO_PLAYMODE_LOOP, NULL);
			}
			if (collision(player1_x, player1_y, PLAYER_WIDTH, PLAYER_HEIGHT,  ball_x, ball_y, 32, 32) == true) {
				HitCounter++;
				if (HitCounter >= 5) {
					speed++;
					ball_dx = speed;
					HitCounter = 0;
					cout << speed << endl;
					PLAYER_WIDTH + 1;
				}
				ball_dx = -ball_dx;
				al_play_sample(sample, 1.0, 0.0, 1.5, ALLEGRO_PLAYMODE_LOOP, NULL);
				
				
			
			}
			if (key[KEY_UP] && player1_y >= 4.0) { // player 1 move up
				player1_y -= 10.0;
			}

			if (key[KEY_DOWN] && player1_y <= SCREEN_H - PLAYER_HEIGHT - 10.0) { // player 1 move down
				player1_y += 10.0;
			}

			if (key[KEY_W] && player2_y >= 4.0) { // player 2 move up
				player2_y -= 10.0;
			}

			if (key[KEY_S] && player2_y <= SCREEN_H - PLAYER_HEIGHT - 10.0) { // player 2 move down
				player2_y += 10.0;
			}
			if (ball_x < 0) { // bounces off left wall
				Player1Score++;

				ball_dx = -ball_dx;
				
			}

			if (ball_x > 1920) { // bounces off right wall
				Player2Score++;
				
				
				ball_dx = -ball_dx;
				
			}
			

			if (ball_y < 0 || ball_y > 1080) { // cieling and floors
				ball_dy = -ball_dy;
				
			}

			//add the x velocity to the x position, 
			//and the y velocity to the y position
			ball_x += ball_dx;
			ball_y += ball_dy;
			
			

			

			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) { // when the event queue is done
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = true;
				break;

			case ALLEGRO_KEY_DOWN:
				key[KEY_DOWN] = true;
				break;

			case ALLEGRO_KEY_W:
				key[KEY_W] = true;
				break;

			case ALLEGRO_KEY_S:
				key[KEY_S] = true;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = false;
				break;

			case ALLEGRO_KEY_DOWN:
				key[KEY_DOWN] = false;
				break;

			case ALLEGRO_KEY_W:
				key[KEY_W] = false;
				break;

			case ALLEGRO_KEY_S:
				key[KEY_S] = false;
				break;

			case ALLEGRO_KEY_ESCAPE:
				doexit = true;
				break;
			}
		}

		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			al_clear_to_color(al_map_rgb(0, 0, 0));

			al_draw_bitmap(player1, player1_x, player1_y, 0); // draws player 1
			al_draw_bitmap(player2, player2_x, player2_y, 0); // draws player 2
			al_draw_bitmap(ball, ball_x, ball_y, 0); // draws ball
			al_draw_textf(font, al_map_rgb(255, 255, 255), 1800, 40, ALLEGRO_ALIGN_RIGHT,"Player 1 Score: " "%d", Player1Score);
			al_draw_textf(font, al_map_rgb(200, 0, 200), 20, 50, ALLEGRO_ALIGN_LEFT,"Player 2 Score: " "%d", Player2Score);
			al_flip_display();
		}
	}
	 // Destroys the game when the player quits
	al_destroy_bitmap(player1); // destroys player 1
	al_destroy_bitmap(player2); // destroys player 2
	al_destroy_bitmap(ball); // destroys ball
	al_destroy_timer(timer); // destroys timer
	al_destroy_display(display); // destroys display
	al_destroy_event_queue(event_queue); // destroys event queue 

	return 0;
}

bool collision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2) { // collision function
	if ((x1 + w1) > x2 && x1 <(x2+w2) && (y1 + h1) > y2 && y1 <(y2 + h2)) { // if it collides return true
		return true;
	}

	else { // else false
		return false;
	}

}