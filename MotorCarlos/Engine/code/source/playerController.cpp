
#include <playerController.h>
#include <entity.hpp>
#include <transform.hpp>

namespace engine
{
	PlayerController::PlayerController(Entity* e, float speed)
	{
		this-> entity = e;
		this->speed = speed;
		dirXA = 0;
		dirXD = 0;
		dirYW = 0;
		dirYS = 0;

	}

	void PlayerController::Recieve(SDL_Event e)
	{

		if(e.type == SDL_KEYDOWN)
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
		
	}

	void PlayerController::Update()
	{
		//Si no se esta moviendo saltamos este update
		if ((dirXA + dirXD) == 0 && (dirYW + dirYS) == 0) return;

		Vector3 dir(1 * (dirXA + dirXD), 1 * (dirYW + dirYS), 0);
		dir = glm::normalize(dir);
		dir.x = dir.x * speed;
		dir.y = dir.y * speed;
		this->GetEntitiy()->GetTransform()->Translate(dir);

		//Limites de la pantalla 
		//Esto se podria haber hecho con un systemCollider pero teniendo en cuenta lo que se pide en la entrega no creo que este justificado
		if (this->GetEntitiy()->GetTransform()->GetPosition().x < -5.5f)
		{
			this->GetEntitiy()->GetTransform()->SetPosition(Vector3(-5.5, this->GetEntitiy()->GetTransform()->GetPosition().y, this->GetEntitiy()->GetTransform()->GetPosition().z));
		}
		else if (this->GetEntitiy()->GetTransform()->GetPosition().x > 5.5f)
		{
			this->GetEntitiy()->GetTransform()->SetPosition(Vector3(5.5f, this->GetEntitiy()->GetTransform()->GetPosition().y, this->GetEntitiy()->GetTransform()->GetPosition().z));
		}
		if (this->GetEntitiy()->GetTransform()->GetPosition().y < -5.5f)
		{
			this->GetEntitiy()->GetTransform()->SetPosition(Vector3(this->GetEntitiy()->GetTransform()->GetPosition().x,-5.5f , this->GetEntitiy()->GetTransform()->GetPosition().z));
		}
		else if (this->GetEntitiy()->GetTransform()->GetPosition().y > 5.5f)
		{
			this->GetEntitiy()->GetTransform()->SetPosition(Vector3(this->GetEntitiy()->GetTransform()->GetPosition().x, 5.5f, this->GetEntitiy()->GetTransform()->GetPosition().z));
		}

	}
}