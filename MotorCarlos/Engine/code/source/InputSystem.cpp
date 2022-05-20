
#include <InputSystem.hpp>

namespace engine
{
	InputSystem::InputSystem(int priorty, Kernel* kernell) : System(priorty)
	{
		this->priority = priority;
		kernell->AddTask(this);
	}

	void InputSystem::Run() 
	{
		SDL_Event evento;

		while (SDL_PollEvent(&evento) > 0)
		{
			for (auto reciever : recievers)
			{
				reciever->Recieve(evento);
			}
		}

	}

	void InputSystem::AddReciever(RecieveComponent* reciver)
	{
		recievers.push_back(reciver);
		std::cout << "RECIEVER" << std::endl;
		std::cout << recievers.size() << std::endl;
	}
}