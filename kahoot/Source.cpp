#include<iostream>
#include<allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>
#include<ctime>
using namespace std;


const float FPS = 60;
const int SCREEN_W = 1920;
const int SCREEN_H = 1080;
bool clicked;



int main() {
	int right;
	int rightcount;
	int wrongcount;
	srand(time(NULL));
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL; //clock for your game
	bool redraw = true;
	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}
	if (!al_init_primitives_addon()) {
		fprintf(stderr, "failed to initialize primitives!\n");
		return -1;
	}

	if (!al_install_mouse()) {
		fprintf(stderr, "failed to initialize the mouse!\n");
		return -1;
	}

	timer = al_create_timer(1.0 / FPS);
	if (!timer) {
		fprintf(stderr, "failed to create timer!\n");
		return -1;
	}

	display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display) {
		fprintf(stderr, "failed to create display!\n");
		al_destroy_timer(timer);
		return -1;
	}

	event_queue = al_create_event_queue();
	if (!event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_register_event_source(event_queue, al_get_mouse_event_source());

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	al_start_timer(timer);

	while (1)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES ||
			ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) {
			right = rand() % 4 + 1;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			if (ev.mouse.x < 960 && ev.mouse.y < 540) {
				//top left corner
				al_draw_filled_rectangle(0, 0, 960, 540, al_map_rgb(rand(), rand(), rand()));
				if (right == 1) {
					cout << "you clicked the right square!" << endl;
					rightcount++;
				}
				else {
					cout << "you clicked the wrong square!" << endl;
					wrongcount++;
				}
			}
			else if (ev.mouse.x > 960 && ev.mouse.y < 540) {
				//top right corner
				al_draw_filled_rectangle(1920, 0, 960, 540, al_map_rgb(rand(), rand(), rand()));
				if (right == 2) {
					cout << "you clicked the right square!" << endl;
					rightcount++;
				}
				else {
					cout << "you clicked the wrong square!" << endl;
					wrongcount++;
				}
			}
			else if (ev.mouse.x < 960 && ev.mouse.y > 540) {
				//bottom left corner
				al_draw_filled_rectangle(0, 1080, 960, 540, al_map_rgb(rand(), rand(), rand()));
				if (right == 3) {
					cout << "you clicked the right square!" << endl;
					rightcount++;
				}
				else {
					cout << "you clicked the wrong square!" << endl;
					wrongcount++;
				}
			}
			else if (ev.mouse.x > 960 && ev.mouse.y > 540) {
				//bottom riught corner
				al_draw_filled_rectangle(1920, 1080, 960, 540, al_map_rgb(rand(), rand(), rand()));
				if (right == 4) {
					cout << "you clicked the right square!" << endl;
					rightcount++;
				}
				else {
					cout << "you clicked the wrong square!" << endl;
					wrongcount++;
				}
			}
		}

		if (redraw && al_is_event_queue_empty(event_queue)) {
			
			
			
				
				

				
			


			al_flip_display();
		}
	}

	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}
