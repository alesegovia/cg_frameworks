#ifndef CANVAS_H
#define CANVAS_H

#include "color.h"

#include <SDL.h>

#include <cassert>

#include <iostream>
using std::cout;
using std::endl;

class Canvas
{
	public:
		Canvas(int, int);
		~Canvas();
		void putpixel(int, int, const Color&);
		void clear();
		void repaint();
		int width();
		int height();
			
	private:
		SDL_Surface* _pSurface;
		void putpixel(int, int, int);

};

#endif //CANVAS_H
