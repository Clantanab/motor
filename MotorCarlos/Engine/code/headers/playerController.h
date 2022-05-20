#pragma once

#include <updateComponent.hpp>
#include <reciveComponent.hpp>


namespace engine
{
	class PlayerController : public UpdateComponent, public RecieveComponent
	{
	private:
		int dirX = 1;
		int dirY = 0;
		float speed;
	public:

		PlayerController(Entity* e, float speed);

		void Recieve(SDL_Event e) override;
		 void Update() override;
	};
}
