

#include <updateSystem.hpp>
#include<playerController.h>

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
		PlayerController* p = new PlayerController(e, speed);
		updates.push_back(p);
		i.AddReciever(p);
	}
}