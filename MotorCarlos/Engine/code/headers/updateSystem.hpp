#pragma once

#include <system.hpp>
#include <vector>
#include <updateComponent.hpp>
#include <kernel.hpp>
#include <InputSystem.hpp>
#include <transform.hpp>

namespace engine
{
	class UpdateSystem : public System
	{
	protected:
		std::vector<UpdateComponent*> updates;

	public:

		UpdateSystem(int priority, Kernel* kernell);

		void Run() override;

		void AddPlayerComponent(Entity* e, float speed, InputSystem& i);
		void AddEnemyComponent(Entity* e, float speed, Transform* target);

	};
}
