CC = gcc
TARGET = mandelbrot
SRC = mandelbrot.c

ifeq ($(OS), Windows_NT)
	CFLAGS = -I C:\SDL2\include -L C:\SDL2\lib
	LIBS = -lmingw32 -lSDL2main -lSDL2
	TARGET = mandelbrot.exe
else
	CFLAGS = $(shell sdl2-config --cflags)
	LIBS = $(shell sdl2-config --libs)
endif

all:
	$(CC) $(SRC) -o $(TARGET) $(CFLAGS) $(LIBS)
run: all
	./$(TARGET)
clean:
	rm -f $(TARGET)
