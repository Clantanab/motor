#pragma once

#include <updateComponent.hpp>
#include <reciveComponent.hpp>


namespace engine
{
	class PlayerController : public UpdateComponent, public RecieveComponent
	{
	private:
		int dirX;
		int dirY;
		float speed;
	public:

		PlayerController(Entity* e, float speed);

		void Recieve(SDL_Event e) override;
		 void Update() override;
	};
}
