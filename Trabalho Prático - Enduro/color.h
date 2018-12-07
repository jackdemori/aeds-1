#pragma once
#include <allegro5/allegro.h>
#include <math.h>

typedef struct
{
    float r;
    float g;
    float b;
} Color;

Color new_color (unsigned int r, unsigned int g, unsigned int b);

Color day_sky_color ();
Color night_sky_color ();

float clamp (float v, float max, float min);
float clamp01 (float v);

void normalize (Color *a);

Color mul (Color a, Color b);
Color add (Color a, Color b);
Color subtract (Color a, Color b);

ALLEGRO_COLOR color_2_allegro_color (Color c);

float lerp (float a, float b, float t);
Color lerp_color (Color a, Color b, float t);