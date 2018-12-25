#include "Canvas.h"

SDL_Surface* pSurface = NULL;

void cg_init(int w, int h)
{
	assert (SDL_Init(SDL_INIT_VIDEO) == 0);
	pSurface = SDL_SetVideoMode(w, h, 0, SDL_HWSURFACE|SDL_DOUBLEBUF);
	assert (pSurface != NULL);
}

void cg_putpixel(int x, int y, Color c)
{
	assert (pSurface != NULL);

	int newx = x + pSurface->w/2;
	int newy = -y + pSurface->h/2;

	assert (newx >= 0 && newx < pSurface->w && newy >= 0 && newy < pSurface->h);
	
	SDL_LockSurface(pSurface);
	int bpp = pSurface->format->BytesPerPixel;
	Uint8 *p = (Uint8 *)pSurface->pixels + newy * pSurface->pitch + newx * bpp;
	
	int pixel = SDL_MapRGB(pSurface->format, c.r, c.g, c.b);
	
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
	SDL_UnlockSurface(pSurface);
}

void cg_clear(void)
{
	assert (pSurface != NULL);
	SDL_Rect r;
	r.x = r .y = 0;
	r.w = pSurface->w;
	r.h = pSurface->h;
	SDL_FillRect(pSurface, &r, 0x0);	
}

void cg_repaint(void)
{
	assert (pSurface != NULL);
	SDL_UpdateRect(pSurface, 0, 0, pSurface->w, pSurface->h);
	SDL_Flip(pSurface);
}

void cg_close(void)
{
	SDL_Quit();
}

