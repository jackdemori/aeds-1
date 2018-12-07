#include <stdio.h>
#include <stdlib.h>

#include "color.h"

#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>

#define NUM_OPONENTES 1

const float FPS = 100; 
const int SCREEN_W = 960;
const int SCREEN_H = 540;

ALLEGRO_FONT *size_32;

// Map control variables
float BORDER_W = 25;

float MAX_HILL_H = 110;
float MIN_HILL_H = -50;
float HILL_H = 50;

float TRACK_TOP_SIZE = 20;
float MAX_TRACK_TOP_SIZE = 375;

// Drawing map variables
float SKY_H;

float TRACK_TOP_W;
float TRACK_BOTTOM_W;

float TRACK_TOP_LEFT_X;
float TRACK_TOP_LEFT_Y;
float TRACK_BOTTOM_LEFT_X;
float TRACK_BOTTOM_LEFT_Y;

float TRACK_TOP_RIGHT_X;
float TRACK_TOP_RIGHT_Y;
float TRACK_BOTTOM_RIGHT_X;
float TRACK_BOTTOM_RIGHT_Y;

ALLEGRO_BITMAP *sky_background = NULL;

float THETA;

// Inimigo
typedef struct
{
    int id;
    // Posicao inicial
    float pos_x;
    float pos_y;

    float initial_x;
    float target_x;

    float width;
    float height;

    ALLEGRO_BITMAP *car;
} Enemy;

Enemy oponentes[NUM_OPONENTES];

// Player
ALLEGRO_BITMAP *player = NULL;
float PLAYER_W = 128;
float PLAYER_H = 64;
float PLAYER_VERTICAL_OFFSET = 16; // Altura do player em relação a pista
float PLAYER_HORIZONTAL_OFFSET = 0;
float PLAYER_HORIZONTAL_LIMIT = 290;
float PLAYER_SPEED = 1;
float PLAYER_TURN_SPEED = 5;
bool COLLISION = false;

bool holding_A = false;
bool holding_D = false;
bool holding_P = false;

int points = 0;
int record = 0;

void debug_log_error (char message[])
{
    fprintf(stderr, "%s\n", message);
}

bool initialize (ALLEGRO_DISPLAY **display, ALLEGRO_TIMER **timer, ALLEGRO_EVENT_QUEUE **event_queue)
{
    if (!al_init())
    {
        debug_log_error("Failed to initialize allegro.");
        return false;
    }

    if (!al_init_image_addon())
    {
        debug_log_error("Failed to initialize images addon.");
    }

    if(!al_init_primitives_addon())
    {
        debug_log_error("Failed to initialize primitives addon.");
    }

    *timer = al_create_timer(1 / FPS);
    if (!*timer)
    {
        debug_log_error("Failed to create timer.");
        return false;
    }

    *display = al_create_display(SCREEN_W, SCREEN_H);
    if (!*display)
    {
        debug_log_error("Failed to create display.");
        al_destroy_timer(*timer);
        return false;
    }

    *event_queue = al_create_event_queue();
    if (!*event_queue)
    {
        debug_log_error("Failed to create event_queue.");
        al_destroy_display(*display);
        al_destroy_timer(*timer);
        return false;
    }

    // Inicializa a entrada pelo teclado
    al_install_keyboard();

    // Inicializa o modulo allegro que carrega as fontes
    al_init_font_addon();

	// Inicializa o modulo allegro que entende arquivos tff de fontes
    al_init_ttf_addon();

	// Carrega o arquivo arial.ttf da fonte Arial e define que sera usado o tamanho 32 (segundo parametro)
    size_32 = al_load_font("arial.ttf", 32, 1);   

    // Registra na fila de eventos que eu quero identificar quando a tela foi alterada
    al_register_event_source(*event_queue, al_get_display_event_source(*display));

	// Registra na fila de eventos que eu quero identificar quando o tempo alterou de t para t+1
    al_register_event_source(*event_queue, al_get_timer_event_source(*timer));
   
    al_register_event_source(*event_queue, al_get_keyboard_event_source());

    return true;
}

void init ()
{
    SKY_H = SCREEN_H  / 3 + HILL_H;

	TRACK_TOP_W = SCREEN_W / 100 + TRACK_TOP_SIZE;
	TRACK_BOTTOM_W = SCREEN_W / 1.2;
	
	TRACK_TOP_LEFT_X = SCREEN_W / 2 - TRACK_TOP_W / 2;
	TRACK_TOP_LEFT_Y = SKY_H;
	TRACK_BOTTOM_LEFT_X = SCREEN_W / 2 - TRACK_BOTTOM_W / 2;
	TRACK_BOTTOM_LEFT_Y = SCREEN_H;
	
	TRACK_TOP_RIGHT_X = SCREEN_W / 2 + TRACK_TOP_W / 2;
	TRACK_TOP_RIGHT_Y = SKY_H;
	TRACK_BOTTOM_RIGHT_X = SCREEN_W / 2 + TRACK_BOTTOM_W / 2;
	TRACK_BOTTOM_RIGHT_Y = SCREEN_H;

	// Track angle
	THETA = atan((TRACK_BOTTOM_LEFT_Y - TRACK_TOP_LEFT_Y) / (TRACK_TOP_LEFT_X - TRACK_BOTTOM_LEFT_X));

    player = al_load_bitmap("car.png");
    sky_background = al_load_bitmap("background.png");

    for (int i = 0; i < NUM_OPONENTES; i++)
    {
        oponentes[i].id = i;
        oponentes[i].pos_x = TRACK_TOP_LEFT_X + (rand() % ((int)TRACK_TOP_SIZE + 2));
        oponentes[i].pos_y = SKY_H;
        oponentes[i].initial_x = oponentes[i].pos_x;
        oponentes[i].target_x = (TRACK_BOTTOM_LEFT_X + 128) + (rand() % (int)((TRACK_BOTTOM_RIGHT_X - 128) - TRACK_BOTTOM_LEFT_X));

        oponentes[i].width = 128;
        oponentes[i].height = 64;

        oponentes[i].car = (i % 2 == 0) ? al_load_bitmap("enemy1.png") : al_load_bitmap("enemy2.png");
    }
}

// Retorna o tamanho do carro de acordo com sua distancia do jogador (0 longe, 1 perto)
float car_size (float y)
{
    //MAIOR = SCREEN_H - (PLAYER_H + PLAYER_VERTICAL_OFFSET) -> Posicao do jogador
    //MENOR = SKY_H

    if (y < SKY_H)
        return 0;
    
    if (y > SCREEN_H - (PLAYER_H + PLAYER_VERTICAL_OFFSET))
        return 1;

    return (y - SKY_H) / ((SCREEN_H - (PLAYER_H + PLAYER_VERTICAL_OFFSET)) - SKY_H);
}

void draw_scene (ALLEGRO_DISPLAY *display)
{
    // Desenha a grama
	al_set_target_bitmap(al_get_backbuffer(display));
	al_clear_to_color(al_map_rgb(22, 102, 0));
	
	// Desenha o ceu (noite(0, 16, 64)-dia(136, 170, 204))
    Color skyColor = day_sky_color();

    if (!holding_P)
        skyColor = lerp_color(day_sky_color(), night_sky_color(), sin(al_get_time() / 3) * 2);

	al_draw_filled_rectangle(0, 0, SCREEN_W, SKY_H, color_2_allegro_color(skyColor));
    al_draw_scaled_bitmap(sky_background, 0, 0, 512, 64, 0, SKY_H - 120, 960, 120, 0);

    // Desenha as bordas
    al_draw_filled_triangle(TRACK_TOP_LEFT_X, TRACK_TOP_LEFT_Y, TRACK_BOTTOM_LEFT_X - BORDER_W, TRACK_BOTTOM_LEFT_Y, 
        TRACK_BOTTOM_LEFT_X + BORDER_W, TRACK_BOTTOM_LEFT_Y, al_map_rgb(255, 255, 255));

    al_draw_filled_triangle(TRACK_TOP_RIGHT_X, TRACK_TOP_RIGHT_Y, TRACK_BOTTOM_RIGHT_X - BORDER_W, TRACK_BOTTOM_RIGHT_Y, 
        TRACK_BOTTOM_RIGHT_X + BORDER_W, TRACK_BOTTOM_RIGHT_Y, al_map_rgb(255, 255, 255));

    // Desenha a pista
    al_draw_filled_triangle(TRACK_BOTTOM_LEFT_X, TRACK_BOTTOM_LEFT_Y, SCREEN_W / 2, TRACK_BOTTOM_LEFT_Y, 
        SCREEN_W / 2, SKY_H, al_map_rgb(16, 16, 16));

    al_draw_filled_triangle(TRACK_TOP_LEFT_X, TRACK_TOP_LEFT_Y, SCREEN_W / 2, TRACK_TOP_LEFT_Y, 
        TRACK_BOTTOM_LEFT_X, TRACK_BOTTOM_LEFT_Y, al_map_rgb(16, 16, 16));

    al_draw_filled_triangle(TRACK_BOTTOM_RIGHT_X, TRACK_BOTTOM_RIGHT_Y, SCREEN_W / 2, TRACK_BOTTOM_RIGHT_Y, 
        SCREEN_W / 2, SKY_H, al_map_rgb(16, 16, 16));

    al_draw_filled_triangle(TRACK_TOP_RIGHT_X, TRACK_TOP_RIGHT_Y, SCREEN_W / 2, TRACK_TOP_RIGHT_Y, 
        TRACK_BOTTOM_RIGHT_X, TRACK_BOTTOM_RIGHT_Y, al_map_rgb(16, 16, 16));

    al_draw_filled_triangle(SCREEN_W / 2, SKY_H, SCREEN_W / 2 - 10, SCREEN_H, SCREEN_W / 2 + 10, SCREEN_H, al_map_rgb(255, 255, 255));

    //Texto
    al_draw_textf(size_32, al_map_rgb(255, 255, 255), TRACK_BOTTOM_LEFT_X - 50, 25, 0, "Score: %d", points);
    //al_draw_textf(size_32, al_map_rgb(255, 255, 255), TRACK_BOTTOM_LEFT_X - 50, 57, 0, "Record: %d", record);

    if (COLLISION)
        al_draw_text(size_32, al_map_rgb(255, 255, 255), SCREEN_W / 2 - 90, 79, 0, "You Lose!");

    //Oponentes
    for (int i = 0; i < NUM_OPONENTES; i++)
    {
        al_draw_scaled_bitmap(oponentes[i].car, 0, 0, 64, 32, oponentes[i].pos_x - oponentes[i].width, oponentes[i].pos_y - oponentes[i].height, 
            oponentes[i].width, oponentes[i].height, 0);
    }  

    //Player
    al_draw_scaled_bitmap(player, 0, 0, 64, 32, SCREEN_W / 2 - PLAYER_W / 2 + PLAYER_HORIZONTAL_OFFSET, SCREEN_H - (PLAYER_H + PLAYER_VERTICAL_OFFSET), PLAYER_W, PLAYER_H, 0);
}

void quit_application (ALLEGRO_DISPLAY **display, ALLEGRO_TIMER **timer, ALLEGRO_EVENT_QUEUE **event_queue)
{
    al_destroy_timer(*timer);
    al_destroy_display(*display);
    al_destroy_event_queue(*event_queue);
}

void handle_input (ALLEGRO_EVENT event, bool *isQuitRequested)
{
    if(event.type == ALLEGRO_EVENT_KEY_DOWN)
    {
		switch(event.keyboard.keycode)
        {
			
            case ALLEGRO_KEY_P:
                holding_P = true;
			break;
			/*
			case ALLEGRO_KEY_S:
			break;
            */
			case ALLEGRO_KEY_A:
                holding_A = true;
			break;

			case ALLEGRO_KEY_D:
                holding_D = true;
			break;

			case ALLEGRO_KEY_ESCAPE:
				*isQuitRequested = true;
			break;
		}
	}	 
	else if(event.type == ALLEGRO_EVENT_KEY_UP) 
    {
		switch(event.keyboard.keycode)
        {
            case ALLEGRO_KEY_P:
                holding_P = false;
			break;
			case ALLEGRO_KEY_A:
				holding_A = false;
			break;

			case ALLEGRO_KEY_D:
				holding_D = false;
			break;
		}
	}
}

bool AABB_collision_test (int i)
{
    float player_pos_x = SCREEN_W / 2 + PLAYER_HORIZONTAL_OFFSET;
    float player_pos_y = SCREEN_H - PLAYER_VERTICAL_OFFSET;

    if (player_pos_x < oponentes[i].pos_x + oponentes[i].width - 70 &&
        player_pos_x + oponentes[i].width > oponentes[i].pos_x - 60 &&
        player_pos_y < oponentes[i].pos_y + oponentes[i].height - 10 &&
        player_pos_y + oponentes[i].height - 10 > oponentes[i].pos_y)
    {
        return true;
    }
    return false;
}

void tick ()
{
    SKY_H = SCREEN_H  / 3 + HILL_H;

    TRACK_TOP_W = SCREEN_W / 100 + TRACK_TOP_SIZE;
	//TRACK_BOTTOM_W = SCREEN_W / 1.2;
	
	TRACK_TOP_LEFT_X = SCREEN_W / 2 - TRACK_TOP_W / 2;
	TRACK_TOP_LEFT_Y = SKY_H;
	TRACK_BOTTOM_LEFT_X = SCREEN_W / 2 - TRACK_BOTTOM_W / 2;
	TRACK_BOTTOM_LEFT_Y = SCREEN_H;
	
	TRACK_TOP_RIGHT_X = SCREEN_W / 2 + TRACK_TOP_W / 2;
	TRACK_TOP_RIGHT_Y = SKY_H;
	TRACK_BOTTOM_RIGHT_X = SCREEN_W / 2 + TRACK_BOTTOM_W / 2;
	TRACK_BOTTOM_RIGHT_Y = SCREEN_H;

	// Track angle
	THETA = atan((TRACK_BOTTOM_LEFT_Y - TRACK_TOP_LEFT_Y) / (TRACK_TOP_LEFT_X - TRACK_BOTTOM_LEFT_X));

    for (int i = 0; i < NUM_OPONENTES; i++)
    {
        oponentes[i].pos_x = lerp(oponentes[i].initial_x, oponentes[i].target_x, car_size(oponentes[i].pos_y));

        if (oponentes[i].pos_y < SCREEN_H + oponentes[i].height)
            oponentes[i].pos_y += (PLAYER_SPEED + 0.3 * i);
        else
        {
            oponentes[i].pos_y = SKY_H;

            //Gera uma nova posicao inicial
            oponentes[i].pos_x = TRACK_TOP_LEFT_X + (rand() % ((int)TRACK_TOP_SIZE + 2));

            //Gerar novo destino aleatorio
            oponentes[i].target_x = (TRACK_BOTTOM_LEFT_X + 128) + (rand() % (int)((TRACK_BOTTOM_RIGHT_X - 128) - TRACK_BOTTOM_LEFT_X));

            //Adiciona um ponto ao jogador
            points++;
        }
            
        oponentes[i].width = 128 * car_size(oponentes[i].pos_y);
        oponentes[i].height = 64 * car_size(oponentes[i].pos_y);

        // Verifica se o player bateu em outro carro
        if (!COLLISION)
            COLLISION = AABB_collision_test(i);
    }

    if (holding_D)
    {
        PLAYER_HORIZONTAL_OFFSET = clamp(PLAYER_HORIZONTAL_OFFSET + PLAYER_TURN_SPEED, PLAYER_HORIZONTAL_LIMIT, -PLAYER_HORIZONTAL_LIMIT);
    }

    if (holding_A)
    {
        PLAYER_HORIZONTAL_OFFSET = clamp(PLAYER_HORIZONTAL_OFFSET - PLAYER_TURN_SPEED, PLAYER_HORIZONTAL_LIMIT, -PLAYER_HORIZONTAL_LIMIT);
    }
}

int main (int argc, char **argv)
{
    srand(15);
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;

    if (!initialize(&display, &timer, &event_queue))
    {
        debug_log_error("Failed to initialize the game.");
        return -1;
    }

    init ();

    // Inicia o temporizador
    al_start_timer(timer);
    al_flip_display();

    // O usuario deseja fechar a aplicacao?
    bool isQuitRequested = false;

    while (!isQuitRequested)
    {
        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);

        handle_input(event, &isQuitRequested);

        if(event.type == ALLEGRO_EVENT_TIMER)
        {
            if (!holding_P)
            {
                float sine = sin(al_get_time() / 4) * 2;

                HILL_H = clamp((MAX_HILL_H - MIN_HILL_H) * sine + MIN_HILL_H, MAX_HILL_H, MIN_HILL_H);
                TRACK_TOP_SIZE = clamp(MAX_TRACK_TOP_SIZE * sine, MAX_TRACK_TOP_SIZE, 0);

                if (!COLLISION)
                {
                    tick ();
                }
                else
                {
                    al_rest(2);
                    isQuitRequested = true;
                }
            }
                
            draw_scene(display);
            al_flip_display();
        }
        else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            // Se o tipo de evento for o fechamento da janela
            isQuitRequested = true;
            quit_application(&display, &timer, &event_queue);
        }
    }

    quit_application(&display, &timer, &event_queue);
}