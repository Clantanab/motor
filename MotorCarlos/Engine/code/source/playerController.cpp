
#include <playerController.h>
#include <entity.hpp>
#include <transform.hpp>

namespace engine
{
	PlayerController::PlayerController(Entity* e, float speed, InputSystem& system)
	{
		this-> entity = e;
		this->speed = speed;
		dirXA = 0;
		dirXD = 0;
		dirYW = 0;
		dirYS = 0;

		system.AddReciever(new PlayerReader(entity, this));

	}


	void PlayerController::SetSpeed(float speed)
	{
		this->speed = speed;
	}
	
	float PlayerController::GetSpeed()
	{
		return this->speed;
	}

	void PlayerController::SetDir(int dirXA, int dirXD, int dirYW, int DirYS)
	{
		std::cout << dirXD << std::endl;
		this->dirXA = dirXA;
		this->dirXD = dirXD;
		this->dirYW = dirYW;
		this->dirYS = DirYS;
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