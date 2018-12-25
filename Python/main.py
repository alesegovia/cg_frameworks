#!/usr/bin/python

import sys
from Canvas import *

def main():
	canvas = Canvas(300, 300)
	canvas.putpixel(0, 0, (255, 0, 0))
	while 1:
		for event in pygame.event.get():
			if event.type == pygame.QUIT : sys.exit()
		canvas.repaint()
	
if __name__ == "__main__":
	main()
