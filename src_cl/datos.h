/*! \file datos.h
    \brief Archivo cabecera de todas las variables, enumeraciones y definiciones.
*/

#include <allegro5/allegro.h>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PUERTO 9123
#define MY_EVENT_TYPE ALLEGRO_GET_EVENT_TYPE('S','O','C','K')
#define VACIO 99												//!< Este valor es para que no interfiera con bool ni con las enum
#define VERDADERO 255											//!< Verdadero por red

enum MYKEYS {

   KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_EXIT, KEY_SPACE,KEY_0,KEY_1,KEY_2,KEY_3,KEY_4,KEY_5,KEY_6,KEY_7,KEY_8,KEY_9,KEY_P,KEY_FULLSTOP,KEY_ENTER,KEY_BACKSPACE,KEY_PAD_DELETE
};

typedef struct ini_var {
		
	ALLEGRO_DISPLAY *display;
	ALLEGRO_EVENT_QUEUE *event_queue;
	
	ALLEGRO_TIMER *timer;	
	ALLEGRO_TIMER *timer2;						//!< Timer para red
	
	ALLEGRO_EVENT ev;
	
	ALLEGRO_BITMAP *fondoimg[7];

	
	ALLEGRO_BITMAP *pisoimg[6];

	ALLEGRO_BITMAP *enemigoimg[6];				//!< enemigo
	
	
	ALLEGRO_BITMAP *cuboimg;					//!< cubo
	
	ALLEGRO_BITMAP *explosionimg;				//!< explosion
	ALLEGRO_BITMAP *bloqueimg;					//!< bloque
	ALLEGRO_BITMAP *muertofinimg; 				//!< muerto
	ALLEGRO_BITMAP *monedaimg; 					//!< moneda
	ALLEGRO_BITMAP *volverimg; 					//!< volver al menu
	
	ALLEGRO_SAMPLE *temajuego;  
	ALLEGRO_SAMPLE *explosionsfx;  
	ALLEGRO_SAMPLE *monedasfx;
	ALLEGRO_SAMPLE *levelsfx;
   
   
	// menu
	
	ALLEGRO_BITMAP *fondomenuimg; 				//!< fondo menu
	ALLEGRO_BITMAP *fondoipimg; 				//!< fondo menu
	ALLEGRO_BITMAP *opcionesmenuimg;			//!< opciones menu
    ALLEGRO_BITMAP *jugarenlineaimg;
	ALLEGRO_FONT   *font;
	ALLEGRO_FONT   *font2;
	ALLEGRO_SAMPLE *temamenu;
	

	bool key[37];
	char ip[22];
	
} ini_var;

typedef struct niveles{
	
	int t_aparicion;
	int clase;
	
	struct niveles *sig;
	
} niveles;


typedef struct posicion {
	
	float bouncer_x;
	
	float bouncer_x2;
	float bouncer_y2;

	float bouncer_x31;
    float bouncer_x32;
    float bouncer_x33;
    float bouncer_x34;
    float bouncer_x35;
    float bouncer_x36;
    float bouncer_x37;
    float bouncer_x38;
    float bouncer_x39;

	float bouncer_x4;

	float bouncer_x5;

	float bouncer_x6;
	float bouncer_y6;

	float bouncer_dx;

} posicion;

typedef struct auxpartida {

// Variables para el calculo del juego
	
	int vida;
	int score;	
	int nivel;
	int t_nivel;

// Variables mostradas en pantalla
	
	char vidac[2];
	char scorec[22];
	char nivelc[5];
	
	int verifvida;
	
	int aux1;
	
	int auxmoneda1,auxmoneda2;
		
	float auxpisox,auxfondox,auxcolision;
	float auxspriteenemigo;
	float auxspritecubox;
	float auxspritecubov;
	float auxspritecuboy;
	
// Tipos de enemigos

	int tipo1;
	int tipo2;
	int tipo3;
	int tipo4;
	int tipo5;
	int tipo6;
	int tipo7;
	int tipo8;
	int tipo9;	
	
	niveles *INI_niv;
	niveles *aux_niv;

} auxpartida;

typedef struct frameExplosion {

	int curFrameExplosion;
	int frameCountExplosion;
	int frameDelayExplosion;
	int frameWidthExplosion;
	int frameHeightExplosion;

} frameExplosion;

typedef struct frameMonedita {
	
	int curFrameMonedita;
	int frameCountMonedita;
	int frameDelayMonedita;
	int frameWidthMonedita;
	int frameHeightMonedita;
	
} frameMonedita;

// Variables de Cliente TCP
   
typedef struct variablescliente {
    
	char hostname[16];
	
    int netflag;						//!<	Indica si esta en modo red
	int cx_stat;						//!<	Indica si hay conexion (0 = sin cx; 1 = hay cx) (PROBAR)
    
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;

// Variables de wait_cx

	int tecla; 							//!< "tecla": Ind. que impide que hagas letras de mas.
	char ip[3];
	char ip2[33];
	
	char auxip;
	int auxip2, auxip3, act;			//!< numero|cantidad de numeros|indicador prim. vez|indicador de tecla|

// Buffers para put_network_data

	char buffercl[256];
	char buffercl2[256];
	char buffercl3[256];
	char buffercl4[256];
	char buffercl5[256];

} variablescliente;

// Variables de Server TCP
 
typedef struct variablesservidor {
	
    int sockfd, newsockfd;
    socklen_t clilen;

    char buffersv[256];

    struct sockaddr_in serv_addr, cli_addr;
	int net, status, sentkey;

} variablesservidor;
