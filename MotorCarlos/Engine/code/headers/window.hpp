#pragma once


#include <include\SDL.h>
#include <ciso646>
#include <iostream>

namespace engine
{


	class Window {
	private:
		size_t width;
		size_t heigth;

	public:

		SDL_Window* window;

		SDL_GLContext context;


		Window(const std::string& name, size_t  width, size_t height, bool allScreen = false);

		unsigned Get_Width() const;
		unsigned Get_Height() const;

		void Clear() const;
		void SwapBuffers() const;


		void End();


	};
}