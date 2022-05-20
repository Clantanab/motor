#pragma once

#include <updateComponent.hpp>
#include <reciveComponent.hpp>
#include <iostream>

namespace engine
{
	class PlayerController : public UpdateComponent, public RecieveComponent
	{
	private:
		int dirX = 0;
		int dirY = 0;
		std::size_t speed;
	public:

		PlayerController(Entity* e, std::size_t speed);

		void Recieve(SDL_Event e) override;
		 void Update() override;
	};
}
