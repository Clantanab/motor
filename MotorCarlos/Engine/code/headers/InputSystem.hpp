#pragma once


#include<system.hpp>
#include<vector>
#include<reciveComponent.hpp>
#include <kernel.hpp>

namespace engine
{
	class InputSystem : public System
	{
	protected:
		std::vector<RecieveComponent*> recievers;
	public:

		InputSystem(int priorty, Kernel* kernell);

		void Run() override;

		void AddReciever(RecieveComponent* reciver);
	};
}