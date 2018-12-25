#include "canvas.h"

Canvas::Canvas(int w, int h)
{
	assert (SDL_Init(SDL_INIT_VIDEO) == 0);
	
	_pSurface = SDL_SetVideoMode(w, h, 0, SDL_HWSURFACE|SDL_DOUBLEBUF);
	
	assert (_pSurface != NULL);
}

void Canvas::putpixel(int x, int y, const Color& color)
{
	int newx = x + _pSurface->w/2;
	int newy = -y + _pSurface->h/2;
	//assert (newx >= 0 && newx < _pSurface->w && 
	// newy >= 0 && newy < _pSurface->h);
	if (newx >= 0 && newx < _pSurface->w && newy >= 0 && newy < _pSurface->h)
		putpixel(newx, newy, 
				SDL_MapRGB(_pSurface->format, 
						color.getR(), 
						color.getG(), 
						color.getB()));
}

void Canvas::putpixel(int x, int y, int pixel)
{
	SDL_LockSurface(_pSurface);
	int bpp = _pSurface->format->BytesPerPixel;
	Uint8 *p = (Uint8 *)_pSurface->pixels + y * _pSurface->pitch + x * bpp;

	switch (bpp)
	{
		case 1:	*p = pixel;
			break;
			
		case 2:	*(Uint16 *)p = pixel;
			break;
			
		case 3:	if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
			{
				p[0] = (pixel >> 16) & 0xff;
				p[1] = (pixel >> 8) & 0xff;
				p[2] = pixel & 0xff;
			}
			else
			{
				p[0] = pixel & 0xff;
				p[1] = (pixel >> 8) & 0xff;
				p[2] = (pixel >> 16) & 0xff;
			}
			break;

		case 4:	*(Uint32 *)p = pixel;
			break;
	}
	
	SDL_UnlockSurface(_pSurface);
}

void Canvas::clear()
{
	SDL_Rect r;
	r.x = r.y = 0;
	r.w = _pSurface->w;
	r.h = _pSurface->h;
	SDL_FillRect(_pSurface, &r, 0x0);
}

void Canvas::repaint()
{
	//cout << "Updating canvas" << endl;
	SDL_UpdateRect(_pSurface, 0, 0, _pSurface->w, _pSurface->h);
	SDL_Flip(_pSurface);
}

Canvas::~Canvas()
{
	SDL_Quit();
}


int Canvas::width()
{
	return _pSurface->w;
}

int Canvas::height()
{
	return _pSurface->h;
}

