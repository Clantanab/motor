

#include <render.hpp>

namespace engine
{
	Render::Render(int priority)
	{
		this->priority = priority;

		Kernel::Instance().AddTask(this);
	}


	void Render::Run(float time)
	{
		SceneManager::Instance().GetCurrentScene()->Render();
	}

	void Render::End()
	{
		//esta funcion deberia eliminar la task del kernel.
	}
}