// Funciones de inicializacion

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <allegro5/allegro.h>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "datos.h"

	const float FPS = 30;
//	const int INI_SCREEN_W = 1280;
//	const int INI_SCREEN_H = 720;

int	Inicializar (ini_var **var) {

	ini_var *variables;
	
//	bool tecla[2] = { false , false };
	
	variables = *(var);
	
	(variables -> key)[0] = false;
	(variables -> key)[1] = false;

	if(!al_init()) {
		al_show_native_message_box((variables -> display), "Error", "Error", "Failed to initialize allegro!", 
								NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}
	
	if(!al_install_keyboard()) {
		fprintf(stderr, "failed to initialize the keyboard!\n");
		return -1;
	}
	
	(variables -> timer) = al_create_timer(1.0 / FPS);
	if(!(variables -> timer)) {
		fprintf(stderr, "failed to create (variables -> timer)!\n");
		return -1;
	}
	
	if(!al_init_image_addon()) {
		al_show_native_message_box((variables -> display), "Error", "Error", "Failed to initialize al_init_image_addon!", 
								NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}
	
	if(!al_install_mouse()) {
		fprintf(stderr, "failed to initialize the mouse!\n");
		return -1;
	}

// Audio
	
	if(!al_install_audio()){
		fprintf(stderr, "failed to initialize audio!\n");
		return -1;
	}
	
	if(!al_init_acodec_addon()){
		fprintf(stderr, "failed to initialize audio codecs!\n");
		return -1;
	}
	
	if (!al_reserve_samples(1)){
		fprintf(stderr, "failed to reserve samples!\n");
		return -1;
	}

// Sonidos
	
	(variables -> temajuego)= al_load_sample( "Forever Bound - Stereo Madness.wav" );
	(variables -> explosionsfx) = al_load_sample( "explosion.wav" );
	(variables -> monedasfx) = al_load_sample( "(variables -> monedasfx).wav" );
	(variables -> temamenu)= al_load_sample( "DJVI - Back On Track.wav" );
	
	if (!(variables -> temajuego)){
		printf( "Audio clip sample not loaded!\n" ); 
		return -1;
	}

// Pantalla
	
	(variables -> display) = al_create_display(1280,720);
	
	if(!(variables -> display)) {
		al_show_native_message_box((variables -> display), "Error", "Error", "Failed to initialize (variables -> display)!", 
								NULL, ALLEGRO_MESSAGEBOX_ERROR);                            
		al_destroy_timer((variables -> timer));
	return -1;
	}
	
	(variables -> cuboimg) = al_load_bitmap("cubos.png");
	
	if(!(variables -> cuboimg)) {
		al_show_native_message_box((variables -> display), "Error", "Error", "Failed to load image!", 
								NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display((variables -> display));
		return -1;
	}
	
	al_set_target_bitmap((variables -> cuboimg));
	
	al_set_target_bitmap(al_get_backbuffer((variables -> display)));
	
	
  /* bouncer = al_create_bitmap((BOUNCER_SIZE), (BOUNCER_SIZE));
   if(!bouncer) {
      fprintf(stderr, "failed to create bouncer bitmap!\n");
      al_destroy_display((variables -> display));
      al_destroy_timer((variables -> timer));
      return -1;
   }*/
  // al_set_target_bitmap(bouncer);
	
	al_clear_to_color(al_map_rgb(255, 0, 255));
 
 //  al_set_target_bitmap(al_get_backbuffer((variables -> display)));
 
	(variables -> event_queue) = al_create_event_queue();
   
	if(!(variables -> event_queue)) {
		fprintf(stderr, "failed to create (variables -> event_queue)!\n");
		//al_destroy_bitmap(bouncer);
		al_destroy_display((variables -> display));
		al_destroy_timer((variables -> timer));
		return -1;
	}
	
	al_register_event_source((variables -> event_queue), al_get_display_event_source((variables -> display)));
	
	al_register_event_source((variables -> event_queue), al_get_timer_event_source((variables -> timer)));
	
	al_register_event_source((variables -> event_queue), al_get_mouse_event_source());
	
	
	al_register_event_source((variables -> event_queue), al_get_keyboard_event_source());
	
	al_clear_to_color(al_map_rgb(0,0,0));
	
	al_flip_display();
	
	al_start_timer((variables -> timer));

// Imagenes
	
	(variables -> fondoimg) = al_load_bitmap("fondo1.png");
	(variables -> pisoimg) = al_load_bitmap("piso.png");
	(variables -> enemigoimg)  = al_load_bitmap("enemigo.png"); 
	(variables -> explosionimg)= al_load_bitmap("sprite_explosiones.png");
	(variables -> bloqueimg)   = al_load_bitmap("pared.png");
	(variables -> fondomenuimg) = al_load_bitmap("menu.jpg");
	(variables -> opcionesmenuimg) = al_load_bitmap("opciones.png");
	(variables -> monedaimg) = al_load_bitmap("monedita.png");
	(variables -> volverimg) = al_load_bitmap("volveralmenu.png");
	
	(variables -> muertofinimg)  = al_load_bitmap("muerto.png");

	al_convert_mask_to_alpha((variables -> explosionimg), al_map_rgb(106, 76, 48));		//DA CORE DUMP NETBOOK MAX
	
	al_init_font_addon();
	al_init_ttf_addon();

// Fuentes
	
	(variables -> font) = al_load_font ("Lato-Black.ttf" , 24 , 0);
	(variables -> font2) = al_load_font ("Strings Theory.otf" , 48 , 0);
	
	if(!(variables -> fondoimg)) {
		al_show_native_message_box((variables -> display), "Error", "Error", "Failed to load image!", 
								NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display((variables -> display));
		return -1;
	}
	
	return 0;
	
}


