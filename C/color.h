#ifndef COLOR_H
#define COLOR_H

#include <SDL.h>

typedef struct
{
	int r, g, b;
} Color;

/** Crear un color con los valores r, g, b. r,g,b deben pertenecer
al rango 0-255.**/
Color cg_color_new(int r, int g, int b);

#endif //COLOR_H

