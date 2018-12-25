#include "canvas.h"

int main(int argc, char* argv[])
{
	Canvas canvas(320, 240);

	canvas.putpixel(0, 0, COLOR_RED);
	canvas.putpixel(1, 0, COLOR_RED);
	canvas.putpixel(-1, 0, COLOR_RED);
	canvas.putpixel(0, 1, COLOR_RED);
	canvas.putpixel(0, -1, COLOR_RED);
	canvas.repaint();
	for(;;)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
				case SDL_QUIT: return 0;
				case SDL_KEYDOWN : return 0;
			}
		}
		canvas.repaint();
	}
	return 0;
}

