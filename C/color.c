#include "color.h"

Color cg_color_new(int r, int g, int b)
{
	Color color;
	color.r = r;
	color.g = g;
	color.b = b;
	return color;
}

