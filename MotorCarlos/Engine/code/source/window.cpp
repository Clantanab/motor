#pragma once


#include <window.hpp>
#include <cassert>
#include <OpenGL.hpp>

namespace engine {

	Window::Window(const std::string& name, size_t  width, size_t height, bool allScreen)
	{
		
		this->width = width;
		this->heigth = height;
		context = nullptr;


		//Comprobamos el correcto init
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			SDL_Log("SDL no se ha iniciado correctamente");
		}
		else //Si no hay error creamos una ventana
		{
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);

			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
			window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
		}

		if (not window)
		{
			SDL_Log("Problema con la creacion de la ventana");
		}
		else
		{
			//Seteamos el contexto 
			context = SDL_GL_CreateContext(window);

			assert(context != nullptr);

			if (context && glt::initialize_opengl_extensions())
			{
				if (allScreen) SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP); //Maximizamos la vetana
			}
		}
	}

	

	unsigned Window::Get_Width() const 
	{
		/*int width = 0, height = 0;
		if (context) SDL_GetWindowSize(window, &width, &height);*/
		
		return (unsigned)this->width;
	}
	unsigned Window::Get_Height() const
	{
		return (unsigned)this->heigth;
	}

	void Window::Clear()const
	{
		if(context)glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	void Window::SwapBuffers() const 
	{
		if (context) SDL_GL_SwapWindow(this->window);
	}

	void Window::End()
	{
		SDL_DestroyWindow(window);
		SDL_Quit();
	}

}