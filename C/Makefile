EXE = a.out

OBJECTS = color.o canvas.o

CC = gcc

CFLAGS = -Wall `sdl-config --cflags`

LIBS = `sdl-config --libs`

%.o: %.c
	$(CC) -c $< $(CFLAGS) -o $@

all: $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) $(LIBS) main.c -o $(EXE)

clean:
	rm -f $(OBJECTS) $(EXE)
