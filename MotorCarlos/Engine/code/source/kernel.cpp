
#include <kernel.hpp>


namespace engine
{
	Kernel::Kernel()
	{
		active = true;
	}

	void Kernel::Init()
	{
		for (auto task : tasks)
		{
			task->Init();
		}

		Run();
	}

	void Kernel::AddTask(Task* newTask)
	{
		std::cout << newTask->priority << std::endl;
		std::cout << "Priority of task" << std::endl;
		tasks.insert(newTask);	
	}

	void Kernel::Run()
	{


		std::cout << tasks.size() << std::endl;
		do
		{
			for (auto task : tasks)
			{
				task->Run();
			}

		} while (active);

		End();
	}

	void Kernel::SetActive(bool active)
	{
		this->active = active;
	}

	void Kernel::End()
	{

		for (auto task : tasks)
		{
			task->End();
		}
	}
}