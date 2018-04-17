#include <stdio.h>
#include <iostream>
#include <ctime>
#include <allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>
//#include<allegro5/allegro_audio.h>
#include<allegro5/allegro_acodec.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_ttf.h>
#include<vector>

using namespace std;


// constants
bool collision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);
const float FPS = 60; //speed of game
const int SCREEN_W = 1920; //width of screen
const int SCREEN_H = 1080; // height of screen
const int PLAYER_HEIGHT = 32; //player height
const int PLAYER_WIDTH = 512; // player width
const int BALL_SIZE = 32;  // ball width and height
const int BRICK_WIDTH = 50; // brick width
const int BRICK_HEIGHT = 50; // brick height

int Player1Score;
int HitCounter;

class brick {
private:
	int xPos;
	int yPos;
	bool Alive;



public:
	void initBrick(int x, int y);
	void drawBlueBrick();
	void drawWhiteBrick();
	void drawDarkBlueBrick();
	void killBrick();
	int collision(int ballx, int  bally, int  ballw, int  ballh);
	bool isAlive();

};

enum MYKEYS { // keys
	KEY_RIGHT, KEY_LEFT
};
double speed = 1;
int main(int argc, char **argv) { // main

	vector <brick> bricks;
	ALLEGRO_DISPLAY *display = NULL; //Display
	ALLEGRO_EVENT_QUEUE *event_queue = NULL; // Event
	ALLEGRO_TIMER *timer = NULL; // Timer
	ALLEGRO_SAMPLE*sample = NULL; // Ball Bouncing off paddle sound
	ALLEGRO_BITMAP *player1 = NULL; // player 1
	ALLEGRO_BITMAP *ball = NULL; // player 2



	float player1_x = SCREEN_H / 2.0 - PLAYER_WIDTH; // player 1 x
	float player1_y = 1000 - PLAYER_HEIGHT / 2.0; // player 1 y
	float ball_x = SCREEN_W / 2.0 - BALL_SIZE / 2.0; // ball x
	float ball_y = SCREEN_H / 2.0 - BALL_SIZE / 2.0; // ball y
	float ball_dx = -10.0;
	float ball_dy = 10.0;


	bool key[4] = { false, false, false, false };
	bool redraw = true;
	bool doexit = false;



	//declares all of the bricks
	brick brick1;
	brick brick2;
	brick brick3;
	brick brick4;
	brick brick5;
	brick brick6;
	brick brick7;
	brick brick8;
	brick brick9;
	brick brick10;
	brick brick11;
	brick brick12;
	brick brick13;
	brick brick14;
	brick brick15;
	brick brick16;
	brick brick17;
	brick brick18;
	brick brick19;
	brick brick20;
	brick brick21;
	brick brick22;
	brick brick23;
	brick brick24;
	brick brick25;
	brick brick26;
	brick brick27;
	brick brick28;
	brick brick29;
	brick brick30;
	brick brick31;
	brick brick32;
	brick brick33;
	brick brick34;
	brick brick35;
	brick brick36;
	brick brick37;
	brick brick38;
	brick brick39;
	brick brick40;
	brick brick41;
	brick brick42;
	brick brick43;
	brick brick44;
	brick brick45;
	brick brick46;
	brick brick47;
	brick brick48;
	brick brick49;
	brick brick50;
	brick brick51;
	brick brick52;
	brick brick53;
	brick brick54;
	brick brick55;
	brick brick56;
	brick brick57;
	brick brick58;
	brick brick59;
	brick brick60;
	brick brick61;
	brick brick62;
	brick brick63;
	brick brick64;
	brick brick65;
	brick brick66;
	brick brick67;
	brick brick68;
	brick brick69;
	brick brick70;
	brick brick71;
	brick brick72;
	brick brick73;
	brick brick74;
	brick brick75;
	brick brick76;
	brick brick77;
	brick brick78;
	brick brick79;
	brick brick80;
	brick brick81;
	brick brick82;
	brick brick83;
	brick brick84;
	brick brick85;
	brick brick86;
	brick brick87;
	brick brick88;
	brick brick89;
	brick brick90;
	brick brick91;
	brick brick92;
	brick brick93;
	brick brick94;
	brick brick95;
	brick brick96;
	brick brick97;
	brick brick98;
	brick brick99;
	brick brick100;
	brick brick101;
	brick brick102;
	brick brick103;
	brick brick104;
	brick brick105;
	brick brick106;
	brick brick107;
	brick brick108;
	brick brick109;
	brick brick110;
	brick brick111;
	brick brick112;
	brick brick113;
	brick brick114;
	brick brick115;
	brick brick116;
	brick brick117;
	brick brick118;
	brick brick119;
	brick brick120;
	brick brick121;
	brick brick122;
	brick brick123;
	brick brick124;
	brick brick125;
	brick brick126;
	brick brick127;
	brick brick128;
	brick brick129;
	brick brick130;
	brick brick131;
	brick brick132;
	brick brick133;
	brick brick134;
	brick brick135;
	brick brick136;
	brick brick137;
	brick brick138;
	brick brick139;
	brick brick140;
	brick brick141;
	brick brick142;
	brick brick143;
	brick brick144;
	brick brick145;
	brick brick146;
	brick brick147;
	brick brick148;
	brick brick149;
	brick brick150;
	brick brick151;
	brick brick152;
	brick brick153;
	brick brick154;
	brick brick155;
	brick brick156;
	brick brick157;
	brick brick158;



	//initializes all bricks
	//LAYER 1
	brick1.initBrick(860, 50);
	brick2.initBrick(910, 50);
	brick3.initBrick(960, 50);
	brick4.initBrick(1010, 50);
	//LAYER 2
	brick5.initBrick(760, 100);
	brick6.initBrick(810, 100);
	brick7.initBrick(860, 100);
	brick8.initBrick(910, 100);
	brick9.initBrick(960, 100);
	brick10.initBrick(1010, 100);
	brick11.initBrick(1060, 100);
	brick12.initBrick(1110, 100);
	//LAYER 3
	brick13.initBrick(710, 150);
	brick14.initBrick(760, 150);
	brick15.initBrick(810, 150);
	brick16.initBrick(860, 150);
	brick17.initBrick(910, 150);
	brick18.initBrick(960, 150);
	brick19.initBrick(1010, 150);
	brick20.initBrick(1060, 150);
	brick21.initBrick(1110, 150);
	brick22.initBrick(1160, 150);
	//LAYER 4
	brick23.initBrick(660, 200);
	brick24.initBrick(710, 200);
	brick25.initBrick(760, 200);
	brick26.initBrick(810, 200);
	brick27.initBrick(860, 200);
	brick28.initBrick(910, 200);
	brick29.initBrick(960, 200);
	brick30.initBrick(1010, 200);
	brick31.initBrick(1060, 200);
	brick32.initBrick(1110, 200);
	brick33.initBrick(1160, 200);
	brick34.initBrick(1210, 200);
	//LAYER 5
	brick35.initBrick(660, 250);
	brick36.initBrick(710, 250);
	brick37.initBrick(760, 250);
	brick38.initBrick(810, 250);
	brick39.initBrick(860, 250);
	brick40.initBrick(910, 250);
	brick41.initBrick(960, 250);
	brick42.initBrick(1010, 250);
	brick43.initBrick(1060, 250);
	brick44.initBrick(1110, 250);
	brick45.initBrick(1160, 250);
	brick46.initBrick(1210, 250);
	//LAYER 6
	brick47.initBrick(660, 300);
	brick48.initBrick(710, 300);
	brick49.initBrick(760, 300);
	brick50.initBrick(810, 300);
	brick51.initBrick(860, 300);
	brick52.initBrick(910, 300);
	brick53.initBrick(960, 300);
	brick54.initBrick(1010, 300);
	brick55.initBrick(1060, 300);
	brick56.initBrick(1110, 300);
	brick57.initBrick(1160, 300);
	brick58.initBrick(1210, 300);
	//LAYER 7
	brick59.initBrick(610, 350);
	brick60.initBrick(660, 350);
	brick61.initBrick(710, 350);
	brick62.initBrick(760, 350);
	brick63.initBrick(810, 350);
	brick64.initBrick(860, 350);
	brick65.initBrick(910, 350);
	brick66.initBrick(960, 350);
	brick67.initBrick(1010, 350);
	brick68.initBrick(1060, 350);
	brick69.initBrick(1110, 350);
	brick70.initBrick(1160, 350);
	brick71.initBrick(1210, 350);
	brick72.initBrick(1260, 350);
	//LAYER 8
	brick73.initBrick(610, 400);
	brick74.initBrick(660, 400);
	brick75.initBrick(710, 400);
	brick76.initBrick(760, 400);
	brick77.initBrick(810, 400);
	brick78.initBrick(860, 400);
	brick79.initBrick(910, 400);
	brick80.initBrick(960, 400);
	brick81.initBrick(1010, 400);
	brick82.initBrick(1060, 400);
	brick83.initBrick(1110, 400);
	brick84.initBrick(1160, 400);
	brick85.initBrick(1210, 400);
	brick86.initBrick(1260, 400);
	//LAYER 9
	brick87.initBrick(610, 450);
	brick88.initBrick(660, 450);
	brick89.initBrick(710, 450);
	brick90.initBrick(760, 450);
	brick91.initBrick(810, 450);
	brick92.initBrick(860, 450);
	brick93.initBrick(910, 450);
	brick94.initBrick(960, 450);
	brick95.initBrick(1010, 450);
	brick96.initBrick(1060, 450);
	brick97.initBrick(1110, 450);
	brick98.initBrick(1160, 450);
	brick99.initBrick(1210, 450);
	brick100.initBrick(1260, 450);
	//LAYER 10
	brick101.initBrick(610, 500);
	brick102.initBrick(660, 500);
	brick103.initBrick(710, 500);
	brick104.initBrick(760, 500);
	brick105.initBrick(810, 500);
	brick106.initBrick(860, 500);
	brick107.initBrick(910, 500);
	brick108.initBrick(960, 500);
	brick109.initBrick(1010, 500);
	brick110.initBrick(1060, 500);
	brick111.initBrick(1110, 500);
	brick112.initBrick(1160, 500);
	brick113.initBrick(1210, 500);
	brick114.initBrick(1260, 500);
	//LAYER 11
	brick115.initBrick(610, 550);
	brick116.initBrick(660, 550);
	brick117.initBrick(710, 550);
	brick118.initBrick(760, 550);
	brick119.initBrick(810, 550);
	brick120.initBrick(860, 550);
	brick121.initBrick(910, 550);
	brick122.initBrick(960, 550);
	brick123.initBrick(1010, 550);
	brick124.initBrick(1060, 550);
	brick125.initBrick(1110, 550);
	brick126.initBrick(1160, 550);
	brick127.initBrick(1210, 550);
	brick128.initBrick(1260, 550);
	//LAYER 12
	brick129.initBrick(610, 600);
	brick130.initBrick(660, 600);
	brick131.initBrick(710, 600);
	brick132.initBrick(760, 600);
	brick133.initBrick(810, 600);
	brick134.initBrick(860, 600);
	brick135.initBrick(910, 600);
	brick136.initBrick(960, 600);
	brick137.initBrick(1010, 600);
	brick138.initBrick(1060, 600);
	brick139.initBrick(1110, 600);
	brick140.initBrick(1160, 600);
	brick141.initBrick(1210, 600);
	brick142.initBrick(1260, 600);
	//LAYER 13
	brick143.initBrick(610, 650);
	brick144.initBrick(660, 650);
	brick145.initBrick(760, 650);
	brick146.initBrick(810, 650);
	brick147.initBrick(860, 650);
	brick148.initBrick(1010, 650);
	brick149.initBrick(1060, 650);
	brick150.initBrick(1110, 650);
	brick151.initBrick(1210, 650);
	brick152.initBrick(1260, 650);
	//LAYER 14
	brick153.initBrick(610, 700);
	brick154.initBrick(810, 700);
	brick155.initBrick(860, 700);
	brick156.initBrick(1010, 700);
	brick157.initBrick(1060, 700);
	brick158.initBrick(1260, 700);







	if (!al_init()) { // initializes, if not print failed to initialize
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}
	if (!al_init_primitives_addon()) {
		fprintf(stderr, "failed to initialize primitves");
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

	//ALLEGRO_FONT*font = al_load_ttf_font("zig.ttf", 46, 0); // creates the first addon font
	//if (!font) {
	//	fprintf(stderr, "failed to initialize the font!\n");
	//}


	if (!al_init_acodec_addon()) {
		fprintf(stderr, "failed to initialize the sound acodec!\n");
	}

	//if (al_install_audio()) {
	//	fprintf(stderr, "failed to initialize the audio!\n");
	//}

	//if (!al_reserve_samples(1)) {
	//	fprintf(stderr, "failed to initialize the Sound sample!\n");
	//}
	ALLEGRO_FONT*font = al_load_ttf_font("zig.ttf", 46, 0); // creates the first addon font
	if (!font) {
		fprintf(stderr, "failed to initialize the font!\n");
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
	;
	//creates ball bitmap
	al_set_target_bitmap(ball);

	al_clear_to_color(al_map_rgb(255, 255, 255)); // changes ball's color

	al_set_target_bitmap(al_get_backbuffer(display));


	event_queue = al_create_event_queue(); // creates event queue, if error prints error and destroys bitmaps, display, and timer
	if (!event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");
		al_destroy_bitmap(player1); // destroys player 1
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


	while (!doexit) { //start of game loop
		ALLEGRO_EVENT ev; //ev is the allegro event
		al_wait_for_event(event_queue, &ev); // starts if event is made

		if (ev.type == ALLEGRO_EVENT_TIMER) {//start of timer section (physics engine)

			if (collision(player1_x, player1_y, PLAYER_WIDTH, PLAYER_HEIGHT, ball_x, ball_y, 32, 32) == true) { //paddle collision

				ball_dy = -ball_dy;




			}

			if (key[KEY_LEFT] && player1_y >= 4.0) { // player 1 move left
				player1_x -= 10.0;
			}

			if (key[KEY_RIGHT] && player1_y <= SCREEN_H - PLAYER_HEIGHT - 10.0) { // player 1 move right
				player1_x += 10.0;
			}


			if (ball_x > 1920 || ball_x < 0) { // bounces off walls



				ball_dx = -ball_dx;

			}


			if (ball_y < 0 || ball_y > 1080) { // cieling and floors
				ball_dy = -ball_dy;

			}

			//add the x velocity to the x position, 
			//and the y velocity to the y position
			ball_x += ball_dx;
			ball_y += ball_dy;

			if (brick1.collision(ball_x, ball_y, 32, 32)) { // brick collision
				if (brick1.isAlive()) {
					brick1.killBrick();
					Player1Score++;
					if (brick1.collision(ball_x, ball_y, 32, 32) == 1) { // bottom brick
						ball_dx = -ball_dx;
					}
					else if (brick1.collision(ball_x, ball_y, 32, 32) == 2) { // top brick
						ball_dx = -ball_dy;
					}
				}
			}
			if (brick2.collision(ball_x, ball_y, 32, 32)) { // brick collision
				if (brick2.isAlive()) {
					brick2.killBrick();
					Player1Score++;
					if (brick2.collision(ball_x, ball_y, 32, 32) == 1) { // bottom brick
						ball_dx = -ball_dx;
					}
					else if (brick2.collision(ball_x, ball_y, 32, 32) == 2) { // top brick
						ball_dx = -ball_dy;
					}
				}
			}
			if (brick3.collision(ball_x, ball_y, 32, 32)) { // brick collision
				if (brick3.isAlive()) {
					brick3.killBrick();
					Player1Score++;
					if (brick3.collision(ball_x, ball_y, 32, 32) == 1) { // bottom brick
						ball_dx = -ball_dx;
					}
					else if (brick3.collision(ball_x, ball_y, 32, 32) == 2) { // top brick
						ball_dx = -ball_dy;
					}
				}
			}
			if (brick4.collision(ball_x, ball_y, 32, 32)) { // brick collision
				if (brick4.isAlive()) {
					brick4.killBrick();
					Player1Score++;
					if (brick4.collision(ball_x, ball_y, 32, 32) == 1) { // bottom brick
						ball_dx = -ball_dx;
					}
					else if (brick4.collision(ball_x, ball_y, 32, 32) == 2) { // top brick
						ball_dx = -ball_dy;
					}
				}
			}
			if (brick5.collision(ball_x, ball_y, 32, 32)) { // brick collision
				if (brick5.isAlive()) {
					brick5.killBrick();
					Player1Score++;
					if (brick5.collision(ball_x, ball_y, 32, 32) == 1) { // bottom brick
						ball_dx = -ball_dx;
					}
					else if (brick5.collision(ball_x, ball_y, 32, 32) == 2) { // top brick
						ball_dx = -ball_dy;
					}
				}
			}
			if (brick6.collision(ball_x, ball_y, 32, 32)) { // brick collision
				if (brick6.isAlive()) {
					brick6.killBrick();
					Player1Score++;
					if (brick6.collision(ball_x, ball_y, 32, 32) == 1) { // bottom brick
						ball_dx = -ball_dx;
					}
					else if (brick6.collision(ball_x, ball_y, 32, 32) == 2) { // top brick
						ball_dx = -ball_dy;
					}
				}
			}
			if (brick7.collision(ball_x, ball_y, 32, 32)) { // brick collision
				if (brick7.isAlive()) {
					brick7.killBrick();
					Player1Score++;
					if (brick7.collision(ball_x, ball_y, 32, 32) == 1) { // bottom brick
						ball_dx = -ball_dx;
					}
					else if (brick7.collision(ball_x, ball_y, 32, 32) == 2) { // top brick
						ball_dx = -ball_dy;
					}
				}
			}
			if (brick8.collision(ball_x, ball_y, 32, 32)) { // brick collision
				if (brick8.isAlive()) {
					brick8.killBrick();
					Player1Score++;
					if (brick8.collision(ball_x, ball_y, 32, 32) == 1) { // bottom brick
						ball_dx = -ball_dx;
					}
					else if (brick8.collision(ball_x, ball_y, 32, 32) == 2) { // top brick
						ball_dx = -ball_dy;
					}
				}
			}
			if (brick9.collision(ball_x, ball_y, 32, 32)) { // brick collision
				if (brick9.isAlive()) {
					brick9.killBrick();
					Player1Score++;
					if (brick9.collision(ball_x, ball_y, 32, 32) == 1) { // bottom brick
						ball_dx = -ball_dx;
					}
					else if (brick9.collision(ball_x, ball_y, 32, 32) == 2) { // top brick
						ball_dx = -ball_dy;
					}
				}
			}
			if (brick10.collision(ball_x, ball_y, 32, 32)) { // brick collision
				if (brick10.isAlive()) {
					brick10.killBrick();
					Player1Score++;
					if (brick10.collision(ball_x, ball_y, 32, 32) == 1) { // bottom brick
						ball_dx = -ball_dx;
					}
					else if (brick10.collision(ball_x, ball_y, 32, 32) == 2) { // top brick
						ball_dx = -ball_dy;
					}
				}
			}



			redraw = true;
		}//end of timer section


		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) { // when the event queue is done
			break;
		}


		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {

			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = true;
				break;

			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = true;
				break;

			case ALLEGRO_KEY_ESCAPE:
				doexit = true;
				break;
			}
		}


		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {

			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = false;
				break;

			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = false;
				break;

			case ALLEGRO_KEY_ESCAPE:
				doexit = false;
				break;
			}
		}

		//render section
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			al_clear_to_color(al_map_rgb(0, 0, 0));

			al_draw_bitmap(player1, player1_x, player1_y, 0); // draws player 1
			al_draw_bitmap(ball, ball_x, ball_y, 0); // draws ball
			al_draw_textf(font, al_map_rgb(255, 255, 255), 1800, 40, ALLEGRO_ALIGN_RIGHT, "Player 1 Score: " "%d", Player1Score);
			//LAYER1
			if (brick1.isAlive())
				brick1.drawBlueBrick();
			if (brick2.isAlive())
				brick2.drawBlueBrick();
			if (brick3.isAlive())
				brick3.drawBlueBrick();
			if (brick4.isAlive())
				brick4.drawBlueBrick();
			//LAYER 2
			if (brick5.isAlive())
				brick5.drawBlueBrick();
			if (brick6.isAlive())
				brick6.drawBlueBrick();
			if (brick7.isAlive())
				brick7.drawBlueBrick();
			if (brick8.isAlive())
				brick8.drawBlueBrick();
			if (brick9.isAlive())
				brick9.drawBlueBrick();
			if (brick10.isAlive())
				brick10.drawBlueBrick();
			if (brick11.isAlive())
				brick11.drawBlueBrick();
			if (brick12.isAlive())
				brick12.drawBlueBrick();
			// LAYER 3
			if (brick13.isAlive())
				brick13.drawBlueBrick();
			if (brick14.isAlive())
				brick14.drawBlueBrick();
			if (brick15.isAlive())
				brick15.drawBlueBrick();
			if (brick16.isAlive())
				brick16.drawBlueBrick();
			if (brick17.isAlive())
				brick17.drawBlueBrick();
			if (brick18.isAlive())
				brick18.drawBlueBrick();
			if (brick19.isAlive())
				brick19.drawBlueBrick();
			if (brick20.isAlive())
				brick20.drawBlueBrick();
			if (brick21.isAlive())
				brick21.drawBlueBrick();
			if (brick22.isAlive())
				brick22.drawBlueBrick();
			//LAYER 4
			if (brick23.isAlive())
				brick23.drawBlueBrick();
			if (brick24.isAlive())
				brick24.drawBlueBrick();
			if (brick25.isAlive())
				brick25.drawBlueBrick();
			if (brick26.isAlive())
				brick26.drawWhiteBrick();
			if (brick27.isAlive())
				brick27.drawWhiteBrick();
			if (brick28.isAlive())
				brick28.drawBlueBrick();
			if (brick29.isAlive())
				brick29.drawBlueBrick();
			if (brick30.isAlive())
				brick30.drawBlueBrick();
			if (brick31.isAlive())
				brick31.drawBlueBrick();
			if (brick32.isAlive())
				brick32.drawWhiteBrick();
			if (brick33.isAlive())
				brick33.drawWhiteBrick();
			if (brick34.isAlive())
				brick34.drawBlueBrick();
			//Layer 5
			if (brick35.isAlive())
				brick35.drawBlueBrick();
			if (brick36.isAlive())
				brick36.drawBlueBrick();
			if (brick37.isAlive())
				brick37.drawWhiteBrick();
			if (brick38.isAlive())
				brick38.drawWhiteBrick();
			if (brick39.isAlive())
				brick39.drawWhiteBrick();
			if (brick40.isAlive())
				brick40.drawWhiteBrick();
			if (brick41.isAlive())
				brick41.drawBlueBrick();
			if (brick42.isAlive())
				brick42.drawBlueBrick();
			if (brick43.isAlive())
				brick43.drawWhiteBrick();
			if (brick44.isAlive())
				brick44.drawWhiteBrick();
			if (brick45.isAlive())
				brick45.drawWhiteBrick();
			if (brick46.isAlive())
				brick46.drawWhiteBrick();
			//LAAYER 6
			if (brick47.isAlive())
				brick47.drawBlueBrick();
			if (brick48.isAlive())
				brick48.drawBlueBrick();
			if (brick49.isAlive())
				brick49.drawWhiteBrick();
			if (brick50.isAlive())
				brick50.drawWhiteBrick();
			if (brick51.isAlive())
				brick51.drawDarkBlueBrick();
			if (brick52.isAlive())
				brick52.drawDarkBlueBrick();
			if (brick53.isAlive())
				brick53.drawBlueBrick();
			if (brick54.isAlive())
				brick54.drawBlueBrick();
			if (brick55.isAlive())
				brick55.drawWhiteBrick();
			if (brick56.isAlive())
				brick56.drawWhiteBrick();
			if (brick57.isAlive())
				brick57.drawDarkBlueBrick();
			if (brick58.isAlive())
				brick58.drawDarkBlueBrick();
			//LAYER 7
			if (brick59.isAlive())
				brick59.drawBlueBrick();
			if (brick60.isAlive())
				brick60.drawBlueBrick();
			if (brick61.isAlive())
				brick61.drawBlueBrick();
			if (brick62.isAlive())
				brick62.drawWhiteBrick();
			if (brick63.isAlive())
				brick63.drawWhiteBrick();
			if (brick64.isAlive())
				brick64.drawDarkBlueBrick();
			if (brick65.isAlive())
				brick65.drawDarkBlueBrick();
			if (brick66.isAlive())
				brick66.drawBlueBrick();
			if (brick67.isAlive())
				brick67.drawBlueBrick();
			if (brick68.isAlive())
				brick68.drawWhiteBrick();
			if (brick69.isAlive())
				brick69.drawWhiteBrick();
			if (brick70.isAlive())
				brick70.drawDarkBlueBrick();
			if (brick71.isAlive())
				brick71.drawDarkBlueBrick();
			if (brick72.isAlive())
				brick72.drawBlueBrick();
			//LAYER 8
			if (brick73.isAlive())
				brick73.drawBlueBrick();
			if (brick74.isAlive())
				brick74.drawBlueBrick();
			if (brick75.isAlive())
				brick75.drawBlueBrick();
			if (brick76.isAlive())
				brick76.drawBlueBrick();
			if (brick77.isAlive())
				brick77.drawWhiteBrick();
			if (brick78.isAlive())
				brick78.drawWhiteBrick();
			if (brick79.isAlive())
				brick79.drawBlueBrick();
			if (brick80.isAlive())
				brick80.drawBlueBrick();
			if (brick81.isAlive())
				brick81.drawBlueBrick();
			if (brick82.isAlive())
				brick82.drawBlueBrick();
			if (brick83.isAlive())
				brick83.drawWhiteBrick();
			if (brick84.isAlive())
				brick84.drawWhiteBrick();
			if (brick85.isAlive())
				brick85.drawBlueBrick();
			if (brick86.isAlive())
				brick86.drawBlueBrick();
			//LAYER 9
			if (brick87.isAlive())
				brick87.drawBlueBrick();
			if (brick88.isAlive())
				brick88.drawBlueBrick();
			if (brick89.isAlive())
				brick89.drawBlueBrick();
			if (brick90.isAlive())
				brick90.drawBlueBrick();
			if (brick91.isAlive())
				brick91.drawBlueBrick();
			if (brick92.isAlive())
				brick92.drawBlueBrick();
			if (brick93.isAlive())
				brick93.drawBlueBrick();
			if (brick94.isAlive())
				brick94.drawBlueBrick();
			if (brick95.isAlive())
				brick95.drawBlueBrick();
			if (brick96.isAlive())
				brick96.drawBlueBrick();
			if (brick97.isAlive())
				brick97.drawBlueBrick();
			if (brick98.isAlive())
				brick98.drawBlueBrick();
			if (brick99.isAlive())
				brick99.drawBlueBrick();
			if (brick100.isAlive())
				brick100.drawBlueBrick();
			//LAYER 10
			if (brick101.isAlive())
				brick101.drawBlueBrick();
			if (brick102.isAlive())
				brick102.drawBlueBrick();
			if (brick103.isAlive())
				brick103.drawBlueBrick();
			if (brick104.isAlive())
				brick104.drawBlueBrick();
			if (brick105.isAlive())
				brick105.drawBlueBrick();
			if (brick106.isAlive())
				brick106.drawBlueBrick();
			if (brick107.isAlive())
				brick107.drawBlueBrick();
			if (brick108.isAlive())
				brick108.drawBlueBrick();
			if (brick109.isAlive())
				brick109.drawBlueBrick();
			if (brick110.isAlive())
				brick110.drawBlueBrick();
			if (brick111.isAlive())
				brick111.drawBlueBrick();
			if (brick112.isAlive())
				brick112.drawBlueBrick();
			if (brick113.isAlive())
				brick113.drawBlueBrick();
			if (brick114.isAlive())
				brick114.drawBlueBrick();
			//LAYER 11
			if (brick115.isAlive())
				brick115.drawBlueBrick();
			if (brick116.isAlive())
				brick116.drawBlueBrick();
			if (brick117.isAlive())
				brick117.drawBlueBrick();
			if (brick118.isAlive())
				brick118.drawBlueBrick();
			if (brick119.isAlive())
				brick119.drawBlueBrick();
			if (brick120.isAlive())
				brick120.drawBlueBrick();
			if (brick121.isAlive())
				brick121.drawBlueBrick();
			if (brick122.isAlive())
				brick122.drawBlueBrick();
			if (brick123.isAlive())
				brick123.drawBlueBrick();
			if (brick124.isAlive())
				brick124.drawBlueBrick();
			if (brick125.isAlive())
				brick125.drawBlueBrick();
			if (brick126.isAlive())
				brick126.drawBlueBrick();
			if (brick127.isAlive())
				brick127.drawBlueBrick();
			if (brick128.isAlive())
				brick128.drawBlueBrick();
			//LAYER 12
			if (brick129.isAlive())
				brick129.drawBlueBrick();
			if (brick130.isAlive())
				brick130.drawBlueBrick();
			if (brick131.isAlive())
				brick131.drawBlueBrick();
			if (brick132.isAlive())
				brick132.drawBlueBrick();
			if (brick133.isAlive())
				brick133.drawBlueBrick();
			if (brick134.isAlive())
				brick134.drawBlueBrick();
			if (brick135.isAlive())
				brick135.drawBlueBrick();
			if (brick136.isAlive())
				brick136.drawBlueBrick();
			if (brick137.isAlive())
				brick137.drawBlueBrick();
			if (brick138.isAlive())
				brick138.drawBlueBrick();
			if (brick139.isAlive())
				brick139.drawBlueBrick();
			if (brick140.isAlive())
				brick140.drawBlueBrick();
			if (brick141.isAlive())
				brick141.drawBlueBrick();
			if (brick142.isAlive())
				brick142.drawBlueBrick();
			//LAYER 13
			if (brick143.isAlive())
				brick143.drawBlueBrick();
			if (brick144.isAlive())
				brick144.drawBlueBrick();
			if (brick145.isAlive())
				brick145.drawBlueBrick();
			if (brick146.isAlive())
				brick146.drawBlueBrick();
			if (brick147.isAlive())
				brick147.drawBlueBrick();
			if (brick148.isAlive())
				brick148.drawBlueBrick();
			if (brick149.isAlive())
				brick149.drawBlueBrick();
			if (brick150.isAlive())
				brick150.drawBlueBrick();
			if (brick151.isAlive())
				brick151.drawBlueBrick();
			if (brick152.isAlive())
				brick152.drawBlueBrick();
			//LAYER 14
			if (brick153.isAlive())
				brick153.drawBlueBrick();
			if (brick154.isAlive())
				brick154.drawBlueBrick();
			if (brick155.isAlive())
				brick155.drawBlueBrick();
			if (brick156.isAlive())
				brick156.drawBlueBrick();
			if (brick157.isAlive())
				brick157.drawBlueBrick();
			if (brick158.isAlive())
				brick158.drawBlueBrick();


			al_flip_display();
		} // end of render section
	} // game loop
	// Destroys the game when the player quits
	al_destroy_bitmap(player1); // destroys player 1
	al_destroy_bitmap(ball); // destroys ball
	al_destroy_timer(timer); // destroys timer
	al_destroy_display(display); // destroys display
	al_destroy_event_queue(event_queue); // destroys event queue 

	return 0;

} // main

bool collision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2) { // collision function
	if ((x1 + w1) > x2 && x1 <(x2 + w2) && (y1 + h1) > y2 && y1 < (y2 + h2)) { // if it collides return true
		return true;
	}

	else { // else false
		return false;
	}
}
void brick::initBrick(int x, int y) {
	xPos = x;
	yPos = y;
	Alive = true;
}

void brick::drawBlueBrick() {
	al_draw_filled_rectangle(xPos, yPos, xPos + 50, yPos + 50, al_map_rgb(50, 150, 255));
}
void brick::drawWhiteBrick() {
	al_draw_filled_rectangle(xPos, yPos, xPos + 50, yPos + 50, al_map_rgb(255, 255, 255));
}
void brick::drawDarkBlueBrick() {
	al_draw_filled_rectangle(xPos, yPos, xPos + 50, yPos + 50, al_map_rgb(20, 20, 255));
}

int brick::collision(int ballx, int  bally, int  ballw, int  ballh) {
	if ((ballx + ballw) > xPos && ballx <(xPos + BRICK_WIDTH) && (bally + ballh) > yPos && bally < yPos + BRICK_HEIGHT) { // if it collides return true
		if (ballx < (xPos + BRICK_WIDTH) || (ballx + ballw) > xPos) { //ball has collided with right side of brick
			cout << "flag2" << endl;
			return 1;

		}
		else if ((bally + ballh) > yPos || bally < (yPos + BRICK_HEIGHT)) {// ball has collided top brick
			cout << "flag3" << endl;
			return 2;

		}
	}

	else { // else false
		return 0;
	}

}

bool brick::isAlive() {
	return Alive;
}
void brick::killBrick() {
	Alive = false;
}