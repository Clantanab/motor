
#include <kernel.hpp>


namespace engine
{
	Kernel::Kernel()
	{
		active = true;
	}

	void Kernel::Init()
	{
		/*for (auto task : tasks)
		{
			task->Init();
		}*/
	}

	void Kernel::AddTask(Task* newTask)
	{
		tasks.insert(newTask);
	}

	void Kernel::Run()
	{
		for (auto task : tasks)
		{
			std::cout << task->priority  + " kernell " << std::endl;
		}
	}
}