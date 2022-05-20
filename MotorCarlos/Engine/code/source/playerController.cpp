
#include <playerController.h>



namespace engine
{
	PlayerController::PlayerController(Entity* e, std::size_t speed)
	{
		this-> entity = e;
		this->speed = speed;
		dirX = 0;
		dirY = 0;

	}

	void PlayerController::Recieve(SDL_Event e)
	{

		if(e.type == SDL_KEYDOWN)
		{
			switch (e.key.keysym.sym)
			{
			
			case SDLK_a:
				dirX = -1;
				break;
			case SDLK_s:
				dirY = -1;
				break;
			case SDLK_w:
				dirY = 1;
				break;
			case SDLK_d:
				dirX = 1;
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
				dirX = 0;
				break;
			case SDLK_s:
				dirY = 0;
				break;
			case SDLK_w:
				dirY = 0;
				break;
			case SDLK_d:
				dirX = 0;
				break;
			default:
				break;
			}
		}
		
	}
}