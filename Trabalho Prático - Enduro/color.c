#include "color.h"

Color new_color (unsigned int r, unsigned int g, unsigned int b)
{
    Color c;
    c.r = r;
    c.g = g;
    c.b = b;

    return c;
}

// rgb(136, 170, 204)
Color day_sky_color ()
{
    return new_color(136, 170, 204);
}

// rgb(0, 16, 64)
Color night_sky_color ()
{
    return new_color(0, 16, 32);
}

float clamp (float v, float max, float min)
{
    return (v > max) ? max : (v < min ? min : v);
}

float clamp01 (float v)
{
    return (v > 1) ? 1 : (v < 0 ? 0 : v);
}

void normalize (Color *a)
{
    a->r / (float)255;
    a->g / (float)255;
    a->b / (float)255;
}

Color mul (Color a, Color b)
{
    Color c;

    normalize(&a);
    normalize(&b);

    c.r = a.r * b.r;
    c.g = a.g * b.g;
    c.b = a.b * b.b;

    c.r *= 255;
    c.g *= 255;
    c.b *= 255;

    return c;
}

Color add (Color a, Color b)
{
    Color c;

    c.r = clamp(a.r + b.r, 255, 0);
    c.g = clamp(a.g + b.g, 255, 0);
    c.b = clamp(a.b + b.b, 255, 0);

    return c;
}

Color subtract (Color a, Color b)
{
    Color c;

    c.r = clamp(a.r - b.r, 255, 0);
    c.g = clamp(a.g - b.g, 255, 0);
    c.b = clamp(a.b - b.b, 255, 0);

    return c;
}

ALLEGRO_COLOR color_2_allegro_color (Color c)
{
    return al_map_rgb((int)c.r, (int)c.g, (int)c.b);
}

float lerp (float a, float b, float t)
{
    t = clamp01(t);
    return a + (b - a) * t;
}

Color lerp_color (Color a, Color b, float t)
{
    t = clamp01(t);
    return new_color(a.r + (b.r - a.r) * t, a.g + (b.g - a.g) * t, a.b + (b.b - a.b) * t);
}