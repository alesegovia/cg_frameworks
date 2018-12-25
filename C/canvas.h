#ifndef CANVAS_H
#define CANVAS_H

#include "SDL.h"

#include "color.h"

#include <assert.h>

void cg_init(int, int);
void cg_putpixel(int, int, Color);
void cg_clear(void);
void cg_repaint(void);
void cg_close(void);

#endif //CANVAS_H
