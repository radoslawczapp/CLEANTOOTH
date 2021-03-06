#include <stdio.h>
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_primitives.h>

/*			Title     : CLEANTOOTH
			Developer : Rados�aw Czapp
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
	ALLEGRO_BITMAP *przegrana = NULL;
	przegrana = al_load_bitmap("przegrana.png");
	ALLEGRO_BITMAP *wygrana = NULL;
	wygrana = al_load_bitmap("wygrana.png");
	ALLEGRO_BITMAP *szczoteczka = NULL;
	szczoteczka = al_load_bitmap("szczoteczka.png");
	ALLEGRO_BITMAP *drzwi = NULL;
	drzwi = al_load_bitmap("drzwi.png");

	int t = 0;
	al_init_image_addon();
	
	
	int x, y;
	x = 0;
	y = 0;
	int zabek_x = 30;
	int zabek_y = 875;
	int dx;
	dx = 0;

	al_flip_display();

	bool done = false;
	bool gra = true;
	bool skok = false;
	bool spadek = false;
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

	typedef struct szczoteczka
	{
		bool live;
	}szczotka;

	szczotka szczota1;
	szczotka szczota2;
	szczotka szczota3;
	szczotka szczota4;
	szczotka szczota5;
	szczotka szczota6;

	szczota1.live = true;
	szczota2.live = true;
	szczota3.live = true;
	szczota4.live = true;
	szczota5.live = true;
	szczota6.live = true;

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
			//x = x + 3;
		}
		if (spadek == false && al_key_down(&keyState, ALLEGRO_KEY_RIGHT))
		{
			x = x - 3;
			dx = dx - 3;
		}
		if (al_key_down(&keyState, ALLEGRO_KEY_UP) && skok == false)
		{
			skok = true;
		}

		if (skok == true)
		{
			y = y - 13 + 0.5 * t;
			t++;

			if (y >= 0)
			{
				skok = false;
				t = 0;
				
			}
		}
		if (redraw && al_is_event_queue_empty(event_queue1))
		{
			redraw = false;

			al_draw_bitmap(rozgrywka, 0, 0, 0);
	

	if (szczota1.live)
	{
		al_draw_bitmap(szczoteczka, 100 + x, 900, 0);
		if (dx == 100 + dx) szczota1.live = false;
	}
	if (szczota2.live)
	{
		al_draw_bitmap(szczoteczka, 350 + x, 850, 0);
		if (dx == 350 + dx) szczota1.live = false;
	}
	if (szczota3.live)
	{
		al_draw_bitmap(szczoteczka, 675 + x, 800, 0);
		if (dx == 675 + dx) szczota1.live = false;
	}
	if (szczota4.live)
	{
		al_draw_bitmap(szczoteczka, 1150 + x, 750, 0);
		if (dx == 1150 + dx) szczota1.live = false;
	}
	if (szczota5.live)
	{
		al_draw_bitmap(szczoteczka, 1300 + x, 700, 0);
		if (dx == 1300 + dx) szczota1.live = false;
	}
	if (szczota6.live)
	{
		al_draw_bitmap(szczoteczka, 1500 + x, 650, 0);
		if (dx == 1500 + dx) szczota1.live = false;
	}

		al_draw_bitmap(zabek, zabek_x, zabek_y + y, 0);
			
			

			if (spadek == true)
			{
				zabek_y += 10;
				if (zabek_y > 1000)
				{
					al_draw_bitmap(przegrana, 0, 0, 0);
					al_flip_display();
					al_rest(2.0);
					break;
				}
				
			}
			
	/*1*/	al_draw_filled_rounded_rectangle(10 + x, 950, 200 + x, 990, 10, 10, al_map_rgb(0, 127, 127));
	
/*SPADANIE*/	if (200 + x <= 50 && zabek_y + y >= 875)
				{
					spadek = true;
					/*al_draw_bitmap(przegrana, 0, 0, 0);
					al_flip_display();
					al_rest(2.0);
					break;*/
				}

	/*2*/	al_draw_filled_rounded_rectangle(250 + x, 900, 600 + x, 940, 10, 10, al_map_rgb(0, 127, 127));
				if (250 + x >= -50 && 250 + x <= 50 && zabek_y + y >= 825)
				{
					zabek_y = 825;
				}

/*SPADANIE*/	if (620 + x <= 50 && zabek_y + y >= 825)
				{
					spadek = true;
				}

	/*3*/	al_draw_filled_rounded_rectangle(650 + x, 850, 750 + x, 890, 10, 10, al_map_rgb(0, 127, 127));
				if (650 + x >= -50 && 650 + x <= 50 && zabek_y + y >= 750)
				{
					zabek_y = 775;
				}

/*SPADANIE*/	if (775 + x <= 50 && zabek_y + y >= 775)
				{
					spadek = true;
				}

	/*4*/	al_draw_filled_rounded_rectangle(800 + x, 800, 1200 + x, 840, 10, 10, al_map_rgb(0, 127, 127));
				if (800 + x >= -50 && 800 + x <= 50 && zabek_y + y >= 725)
				{
					zabek_y = 725;
				}

/*SPADANIE*/	if (1220 + x <= 50 && zabek_y + y >= 725)
				{
					spadek = true;
				}
	/*5*/	al_draw_filled_rounded_rectangle(1250 + x, 750, 1400 + x, 790, 10, 10, al_map_rgb(0, 127, 127));
				if (1250 + x >= -50 && 1250 + x <= 50 && zabek_y + y >= 675)
				{
					zabek_y = 675;
				}
/*SPADANIE*/	if (1420 + x <= 50 && zabek_y + y >= 675)
				{
					spadek = true;
				}
	/*6*/		al_draw_filled_rounded_rectangle(1450 + x, 700, 1600 + x, 740, 10, 10, al_map_rgb(0, 127, 127));
				if (1450 + x >= -50 && 1450 + x <= 50 && zabek_y + y >= 625)
				{
					zabek_y = 625;
				}
/*SPADANIE*/	if (1620 + x <= 50 && zabek_y + y >= 625)
				{
					spadek = true;
				}	
	/*7*/		al_draw_filled_rounded_rectangle(1650 + x, 650, 1880 + x, 690, 10, 10, al_map_rgb(0, 127, 127));
				if (1650 + x >= -50 && 1650 + x <= 50 && zabek_y + y >= 575)
				{
					zabek_y = 575;
				}
/*SPADANIE*/	if (1620 + x <= 50 && zabek_y + y >= 625)
{
	spadek = true;
}
				al_draw_bitmap(drzwi, 1780 + x, 530, 0);
				//al_draw_filled_rounded_rectangle(1780 + x, 530, 1900 + x, 690, 0, 0, al_map_rgb(0, 127, 127));
			if (1700 + x <= -50)
			{
				al_draw_bitmap(wygrana, 0, 0, 0);
				al_flip_display();
				al_rest(2.0);
				break;
			}

			al_flip_display();
		}
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
	ALLEGRO_BITMAP *przegrana = NULL;
	ALLEGRO_BITMAP *wygrana = NULL;
	ALLEGRO_BITMAP *szczoteczka = NULL;
	
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
	przegrana = al_load_bitmap("przegrana.png");
	wygrana = al_load_bitmap("wygrana.png");
	szczoteczka = al_load_bitmap("szczoteczka.png");

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
///////////////////////////WYJ�CIE/////////////////////////////////
		if (kursor_x > 378 && kursor_x < 618 &&
			kursor_y > -946 && kursor_y < -905 &&
			ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			if (ev.mouse.button & 1)
			{
				gra = false;
			}
		}
////////////////////////////////////////////////////////////////////////////////////WY�WIETLANIE//////////////////////////////////////////////////////////////////////////////
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
//////////////////////////////WYJ�CIE////////////////////////////////////////////
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

