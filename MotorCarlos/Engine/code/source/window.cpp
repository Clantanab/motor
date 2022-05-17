#pragma once


#include <window.h>
#include <cassert>
#include <OpenGL.hpp>

namespace engine {

	Window::Window(const std::string& name, size_t  width, size_t height, bool allScreen = false)
	{

		context = nullptr;

		this->width = width;
		this->heigth = height;

		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			SDL_Log("Error SDL2.");
		}
		else
		{
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

			window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
		}

		if (not window)
		{
			SDL_Log("Error window.");
		}
		else
		{

			context = SDL_GL_CreateContext(window);

			assert(context != nullptr);

			if (context && glt::initialize_opengl_extensions())
			{
				if (allScreen)
				{
					SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
				}
			}
		}
	}

}