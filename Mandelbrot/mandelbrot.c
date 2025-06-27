#include <complex.h>
#include <stdio.h>
#include <stdbool.h>

#if defined(__APPLE__)
#include <SDL.h>
#elif defined(__linux__)
#include <SDL2/SDL.h>
#elif defined(_WIN32)
#include <SDL2/SDL.h>
#endif

#define WIDTH (900)
#define HEIGHT (600)
#define MANDELBROT_LIMIT (2)
#define ZOOM (250)
#define OFFSET_X (100)
#define COLOR_WHITE (0xffffff)

double cabs(double complex number){
	return sqrt(cpow(creal(number), 2) + cpow(cimag(number), 2));
}

bool PixelBelongsToMandelbrotSet(double realPart, double imaginaryPart){
	double complex constant = realPart + imaginaryPart * I;
	double complex z = 0;
	for(int index = 0; index < 20; ++index){
		z = cpow(z, 2) + constant;
	}	
	return cabs(z) <= MANDELBROT_LIMIT;
}

void UpdateMandelbrotSet(SDL_Surface *surface){
	for(int y = 0; y < HEIGHT; ++y){
		for(int x = 0; x < WIDTH; ++x){
			if(PixelBelongsToMandelbrotSet((double)(x - (WIDTH / 2) - OFFSET_X) / ZOOM, -((double)(y - (HEIGHT / 2)) / ZOOM))){
				SDL_Rect rectangle = {x, y, 1, 1};
				SDL_FillRect(surface, &rectangle, COLOR_WHITE);
			}
		}
	}
}

int main(){
	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		printf("Failed to initialize SDL2\n");
		printf("SDL2 Error: %s", SDL_GetError());
		return -1;
	}
	SDL_Window *window = SDL_CreateWindow("Mandelbrot Set", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
	if(!window){
		printf("Failed to create window\n");
		printf("SDL2 Error: %s", SDL_GetError());
		return -1;
	}
	SDL_Surface *surface = SDL_GetWindowSurface(window);
	if(!surface){
		printf("Failed to get the surface from the window\n");
		printf("SDL2 Error: %s", SDL_GetError());
		return -1;
	}
	bool isRunning = true;
	bool needToUpdateMandelbrotSet = true;
	while(isRunning){
		SDL_Event event;
		while(SDL_PollEvent(&event)){
			switch(event.type){
				case SDL_QUIT:
					isRunning = false;
					break;
			}
		}
		if(needToUpdateMandelbrotSet){
			UpdateMandelbrotSet(surface);
			SDL_UpdateWindowSurface(window);
			needToUpdateMandelbrotSet = false;
		}
	}
	return 0;
}
