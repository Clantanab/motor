

#include <updateSystem.hpp>
#include<playerController.h>

namespace engine
{
	UpdateSystem::UpdateSystem(int priorty, Kernel* kernel)
	{
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

	void UpdateSystem::AddPlayerComponent(Entity* e, float speed)
	{
		updates.push_back(new PlayerController(e, speed));
	}
}