#include <stdio.h>
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_primitives.h>

/*			Title     : CLEANTOOTH
			Developer : Rados³aw Czapp
*/

const float FPS = 60;

void graj(ALLEGRO_DISPLAY *display)
{
	ALLEGRO_BITMAP *rozgrywka = NULL;
	rozgrywka = al_load_bitmap("rozgrywka.bmp");
	ALLEGRO_BITMAP *zabek = NULL;
	zabek = al_load_bitmap("zabek.png");
	ALLEGRO_BITMAP *pauza = NULL;
	pauza = al_load_bitmap("pauza.bmp");
	int t = 0;
	al_init_image_addon();
	
	
	int x, y;
	x = 0;
	y = 0;
	int zabek_x = 30;
	int zabek_y = 875;

	al_flip_display();

	bool done = false;
	bool gra = true;
	bool skok = false;
	ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);
	ALLEGRO_EVENT_QUEUE *event_queue1 = NULL;
	ALLEGRO_KEYBOARD_STATE keyState;
	al_install_keyboard();
	bool redraw = true;

	al_set_window_position(display, 0, 0);

	event_queue1 = al_create_event_queue();

	al_register_event_source(event_queue1, al_get_display_event_source(display));

	al_register_event_source(event_queue1, al_get_timer_event_source(timer));

	al_register_event_source(event_queue1, al_get_mouse_event_source());

	al_register_event_source(event_queue1, al_get_keyboard_event_source());

	al_start_timer(timer);

	

	while (1)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue1, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER)
		{
			redraw = true;

			al_get_keyboard_state(&keyState);
		}
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			break;
		}
		if (al_key_down(&keyState, ALLEGRO_KEY_ESCAPE))
		{
			break;			
		}
		if (al_key_down(&keyState, ALLEGRO_KEY_LEFT))
		{
			x = x + 3;
		}
		if (al_key_down(&keyState, ALLEGRO_KEY_RIGHT))
		{
			x = x - 3;
		}
		if (al_key_down(&keyState, ALLEGRO_KEY_UP) && skok == false)
		{
			skok = true;
		}

		if (skok == true)
		{
			y = y - 16+ 0.8 * t;
			t++;

			if (y == 0)
			{
				skok = false;
				t = 0;
			}
		}
		if (redraw && al_is_event_queue_empty(event_queue1))
		{
			redraw = false;

			al_draw_bitmap(rozgrywka, 0, 0, 0);
			al_draw_bitmap(zabek, zabek_x, zabek_y + y, 0);

	/*1*/	al_draw_filled_rounded_rectangle(10 + x, 950, 200 + x, 990, 10, 10, al_map_rgb(0, 127, 127));
				if (200 + x <= 50 && zabek_y + y + 40 >= 875)
				{
					zabek_y +=10;
				}

	/*2*/	al_draw_filled_rounded_rectangle(220 + x, 900, 600 + x, 940, 10, 10, al_map_rgb(0, 127, 127));
				if (220 + x <= 50 && zabek_y  > 865)
				{
					zabek_y = 820;
				}

	/*3*/	al_draw_filled_rounded_rectangle(650 + x, 850, 750 + x, 890, 10, 10, al_map_rgb(0, 127, 127));
				
	/*4*/	al_draw_filled_rounded_rectangle(800 + x, 950, 1200 + x, 990, 10, 10, al_map_rgb(0, 127, 127));

	/*5*/	al_draw_filled_rounded_rectangle(1250 + x, 950, 1400 + x, 990, 10, 10, al_map_rgb(0, 127, 127));

	/*6*/   al_draw_filled_rounded_rectangle(1450 + x, 900, 1600 + x, 940, 10, 10, al_map_rgb(0, 127, 127));
			

			

			al_flip_display();
		}
		//if (zabek_x)
	}
}

int main(void)
{
	int width = 1000;
	int height = 1000;
	bool done = false;
	bool gra = true;

	int imageWidth = 800;
	int imageHeight = 800;

	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}
	ALLEGRO_DISPLAY *display = NULL;

	display = al_create_display(1000, 1000);
	if (!display)
		return -1;

	ALLEGRO_TIMER *timer = NULL;
	
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;

	ALLEGRO_BITMAP *menu = NULL;
	ALLEGRO_BITMAP *menu_nowa_gra = NULL;
	ALLEGRO_BITMAP *menu_o_autorze = NULL;
	ALLEGRO_BITMAP *menu_pomoc = NULL;
	ALLEGRO_BITMAP *menu_wyjscie = NULL;
	ALLEGRO_BITMAP *kursor = NULL;
	ALLEGRO_BITMAP *rozgrywka = NULL;
	ALLEGRO_BITMAP *pomoc = NULL;
	ALLEGRO_BITMAP *oautorze = NULL;

	al_init_image_addon();
	al_init_primitives_addon();
	menu = al_load_bitmap("menu.bmp");
	menu_nowa_gra = al_load_bitmap("menu_nowa_gra.bmp");
	menu_o_autorze = al_load_bitmap("menu_o_autorze.bmp");
	menu_pomoc = al_load_bitmap("menu_pomoc.bmp");
	menu_wyjscie = al_load_bitmap("menu_wyjscie.bmp");
	kursor = al_load_bitmap("kursor.png");
	rozgrywka = al_load_bitmap("rozgrywka.bmp");
	pomoc = al_load_bitmap("pomoc.bmp");
	oautorze = al_load_bitmap("oautorze.bmp");

	al_install_mouse();
	if (!al_install_mouse()) {
		fprintf(stderr, "failed to initialize the mouse!\n");
		return -1;
	}

	imageWidth = al_get_bitmap_width(menu);
	imageHeight = al_get_bitmap_height(menu);

	int kursor_x = 0;
	int kursor_y = 0;

	bool redraw = true;

	timer = al_create_timer(1.0 / FPS);
	if (!timer) {
		fprintf(stderr, "failed to create timer!\n");
		return -1;
	}

	al_set_window_position(display, 0, 0);

	event_queue = al_create_event_queue();
	
	al_start_timer(timer);

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_register_event_source(event_queue, al_get_mouse_event_source());

	//al_clear_to_color(al_map_rgb(0, 0, 0));

	al_hide_mouse_cursor(display);

	while (gra)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		
		if (ev.type == ALLEGRO_EVENT_TIMER) 
		{
			redraw = true;

		}
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) 
		{
			break;
		}		

		if (ev.type == ALLEGRO_EVENT_MOUSE_AXES || ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY)
		{

			kursor_x = ev.mouse.x;
			kursor_y = -ev.mouse.y;
			al_draw_bitmap(kursor, kursor_x, -kursor_y, 0);
		}

///////////////////////////////////////////////////////////////////////////////////AKCJE///////////////////////////////////////////////////////////////////////////////////////		
		
///////////////////////NOWA GRA//////////////////////////////////
		if (kursor_x > 360 && kursor_x < 640 &&
			kursor_y > -714 && kursor_y < -670 &&
			ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			if (ev.mouse.button & 1)
			{
				graj(display);
			}
		}
////////////////////////POMOC/////////////////////////////////////
		if (kursor_x > 415 && kursor_x < 585 &&
			kursor_y > -790 && kursor_y < -750 &&
			ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			if (ev.mouse.button & 1)
			{
				gra = false;
				al_draw_bitmap(pomoc, 0, 0, 0);
				al_flip_display();
				al_rest(15.0);
			}
		}
////////////////////////////O AUTORZE////////////////////////////
		if (kursor_x > 347 && kursor_x < 650 &&
			kursor_y > -870 && kursor_y < -827 &&
			ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			if (ev.mouse.button & 1)
			{
				gra = false;
				al_draw_bitmap(oautorze, 0, 0, 0);
				al_flip_display();
				al_rest(15.0);
			}
		}
///////////////////////////WYJŒCIE/////////////////////////////////
		if (kursor_x > 378 && kursor_x < 618 &&
			kursor_y > -946 && kursor_y < -905 &&
			ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			if (ev.mouse.button & 1)
			{
				gra = false;
			}
		}
////////////////////////////////////////////////////////////////////////////////////WYŒWIETLANIE//////////////////////////////////////////////////////////////////////////////
		if (redraw && al_is_event_queue_empty(event_queue)) 
		{
			redraw = false;
//////////////////////////////NOWA GRA////////////////////////////////////////////////
			if (kursor_x > 360 && kursor_x < 640 &&
				kursor_y > -714 && kursor_y < -670)
			{
				al_flip_display();
				al_draw_bitmap(menu_nowa_gra, 0, 0, 0);
			}
///////////////////////////////POMOC////////////////////////////////////////////////
			else if (kursor_x > 415 && kursor_x < 585 &&
				kursor_y > -790 && kursor_y < -750)
			{
				al_flip_display();
				al_draw_bitmap(menu_pomoc, 0, 0, 0);
			}
/////////////////////////////O AUTORZE////////////////////////////////////////////
			else if (kursor_x > 347 && kursor_x < 650 &&
				kursor_y > -870 && kursor_y < -827)
			{
				al_flip_display();
				al_draw_bitmap(menu_o_autorze, 0, 0, 0);

			}
//////////////////////////////WYJŒCIE////////////////////////////////////////////
			else if (kursor_x > 378 && kursor_x < 618 &&
				kursor_y > -946 && kursor_y < -905)
			{
				al_flip_display();
				al_draw_bitmap(menu_wyjscie, 0, 0, 0);
			}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			else
			{
				al_flip_display();
				al_draw_bitmap(menu, 0, 0, 0);
			}
			al_draw_bitmap(menu, imageWidth, imageHeight, 0);

			al_draw_bitmap(kursor, kursor_x, -kursor_y, 0);

			al_flip_display();
		}
	}

	al_destroy_event_queue(event_queue);
	al_destroy_display(display);						

	return 0;
}

