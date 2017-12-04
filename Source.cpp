#include <stdio.h>
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>


const float FPS = 60;

int main(void)
{
	int width = 1000;
	int height = 1000;
	bool done = false;

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

	al_init_image_addon();
	menu = al_load_bitmap("menu.bmp");
	menu_nowa_gra = al_load_bitmap("menu_nowa_gra.bmp");
	menu_o_autorze = al_load_bitmap("menu_o_autorze.bmp");
	menu_pomoc = al_load_bitmap("menu_pomoc.bmp");
	menu_wyjscie = al_load_bitmap("menu_wyjscie.bmp");
	kursor = al_load_bitmap("kursor.png");
	
	ALLEGRO_MOUSE_CURSOR *al_create_mouse_cursor(ALLEGRO_BITMAP *bmp,
		int x_focus, int y_focus)
	{
		ALLEGRO_SYSTEM *sysdrv = al_get_system_driver();
		ASSERT(bmp);

		ASSERT(sysdrv->vt->create_mouse_cursor);
		return sysdrv->vt->create_mouse_cursor(bmp, x_focus, y_focus);
	}
	imageWidth = al_get_bitmap_width(menu);
	imageHeight = al_get_bitmap_height(menu);

	int kursor_x = 0;
	int kursor_y = 0;

	bool redraw = true;

	al_install_mouse();
	if (!al_install_mouse()) {
		fprintf(stderr, "failed to initialize the mouse!\n");
		return -1;
	}

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

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_draw_bitmap(menu, 0, 0, 0);

	while (!done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) 
		{
			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) 
		{
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES || ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY)
		{
				kursor_x = ev.mouse.x;
				kursor_y = ev.mouse.y;
			
		}
		if (kursor_x > 460 && kursor_x < 820 && kursor_y > 855 && kursor_y < 913)
		{
			al_draw_bitmap(menu_nowa_gra, imageWidth, imageHeight, 0);
		}
		else
		{
			al_draw_bitmap(menu, imageWidth, imageHeight, 0);
		}

		if (redraw && al_is_event_queue_empty(event_queue)) 
		{
			redraw = false;

			//al_draw_bitmap(menu, imageWidth, imageHeight, 0);

			//al_draw_bitmap(kursor, kursor_x, kursor_y, 0);

			al_flip_display();
		}
	}

	al_destroy_event_queue(event_queue);
	al_destroy_display(display);						

	return 0;
}