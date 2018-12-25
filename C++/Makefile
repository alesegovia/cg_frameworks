APP = a.out

CC = g++

CFLAGS = -Wall `sdl-config --cflags`

LIBS = `sdl-config --libs`

OBJECTS = color.o canvas.o

%.o: %.cpp Makefile
	$(CC) -c $< $(CFLAGS) -o $@

all: $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) $(LIBS) main.cpp -o $(APP)
clean:
	rm -f $(OBJECTS) $(APP)
