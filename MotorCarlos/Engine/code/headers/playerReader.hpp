#pragma once


#include <reciveComponent.hpp>


namespace engine
{
	class PlayerController;

	class PlayerReader : public RecieveComponent
	{
	protected:
		PlayerController* player;
		int dirXA = 0;
		int dirYS = 0;
		int dirYW = 0;
		int dirXD = 0;
	public:
		PlayerReader(Entity* e, PlayerController* p);
		void Recieve(SDL_Event e) override;
	};
}



