#include <iostream>

#include <ciso646>
#include <memory>
#include <vector>
#include <include\SDL.h>
#include <GLFW\glfw3.h>


int main() 
{
	int width = 80;
	int height = 80;
	SDL_Window* window = SDL_CreateWindow("Prueba", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
	
	return 0;
}