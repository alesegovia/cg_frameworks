import pygame, sys

class Canvas:
	def __init__(self, w, h):
		self.surface = pygame.display.set_mode((w,h))
	
	def putpixel(self, x, y, color):
		w = self.surface.get_width()
		h = self.surface.get_height()
		newx = x + w/2
		newy = -y + h/2
		assert (newx >= 0 and newx < w and newy >= 0 and newy < h)
		self.surface.set_at((newx, newy), color)

	def clear(self):
		self.surface.fill((0,0,0))

	def repaint(self):
		pygame.display.flip()
