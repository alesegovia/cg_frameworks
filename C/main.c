#include "Canvas.h"

int main(int argc, char* argv[])
{
	int cw = 500;
	int ch = 500;
	cg_init(cw, ch);
	Color color = cg_color_new(0xff, 0x0, 0x0);
	cg_putpixel(0, 0, color);
	cg_repaint();
	for (;;)
	{
		SDL_Event event;
		while(SDL_PollEvent(&event))
		{
			switch (event.type)
			{
				case SDL_KEYDOWN:
				case SDL_QUIT : cg_close();
						return 0;
			}
		}
	}
	return 0;
}

