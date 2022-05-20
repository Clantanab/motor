

#include <updateSystem.hpp>
#include<playerController.h>
#include <EnemyFollower.hpp>

namespace engine
{
	UpdateSystem::UpdateSystem(int priorty, Kernel* kernel) :System(priorty)
	{
		std::cout << "creo un update system" << std::endl;
		this->priority = priority;
		kernel->AddTask(this);
	}

	void UpdateSystem::Run()
	{
		for (auto updater : updates)
		{
			updater->Update();
		}
	}

	void UpdateSystem::AddPlayerComponent(Entity* e, float speed, InputSystem& i)
	{

		updates.push_back(new PlayerController(e, speed, i));
	}
	void UpdateSystem::AddEnemyComponent(Entity* e, float speed, Transform* target)
	{
		updates.push_back(new EnemyFollower(e, target, speed));
	}
}