#pragma once

#include <updateComponent.hpp>
#include <playerReader.hpp>
#include <InputSystem.hpp>


namespace engine
{
	class PlayerController : public UpdateComponent
	{
	private:
		int dirXA;
		int dirXD;
		int dirYW;
		int dirYS;
		float speed;
	public:

		PlayerController(Entity* e, float speed, InputSystem& system);

		 void Update() override;
		 void SetSpeed(float speed);
		 float GetSpeed();
		 void SetDir(int dirXA, int dirXD, int dirYW, int DirYS);
	};
}
