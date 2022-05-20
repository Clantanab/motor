#pragma once

#include <component.hpp>

#include<include\SDL.h>

namespace engine
{
	class RecieveComponent : public Component
	{
	public:
		virtual void Recieve(SDL_Event e) {};
	};
}
