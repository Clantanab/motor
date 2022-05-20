

#include <playerReader.hpp>
#include<playerController.h>

namespace engine
{

	PlayerReader::PlayerReader(Entity* e, PlayerController* p)
	{
		this->entity = e;
		this->player = p;
	}

	void PlayerReader::Recieve(SDL_Event e)
	{
		if (e.type == SDL_KEYDOWN)
		{
			switch (e.key.keysym.sym)
			{

			case SDLK_a:

				 dirXA = -1;
				break;
			case SDLK_s:

				dirYS = -1;
				break;
			case SDLK_w:

				dirYW = 1;
				break;
			case SDLK_d:
				dirXD = 1;
				break;
			default:
				break;
			}
			
		}
		else if (e.type == SDL_KEYUP)
		{
			switch (e.key.keysym.sym)
			{

			case SDLK_a:

				dirXA = 0;
				break;
			case SDLK_s:

				dirYS = 0;
				break;
			case SDLK_w:

				dirYW = 0;
				break;
			case SDLK_d:

				dirXD = 0;
				break;
			default:
				break;
			}
		}
		player->SetDir(dirXA, dirXD, dirYW, dirYS);

	}
}