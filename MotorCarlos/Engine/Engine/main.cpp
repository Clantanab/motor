#include <iostream>

#include <ciso646>
#include <memory>
#include <vector>
#include <include\SDL.h>
#undef main
//#include <GLFW\glfw3.h>


int main() 
{
	int width = 800;
	int height = 800;
	SDL_Window* window = SDL_CreateWindow("Prueba", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);




	
	return 0;
}