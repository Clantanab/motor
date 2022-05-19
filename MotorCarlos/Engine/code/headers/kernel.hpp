#pragma once


#include <task.hpp>
#include <iostream>
#include <set>


namespace engine 
{
	class Kernel
	{
	public:
		static Kernel& Instance() 
		{
			static Kernel kernel;
			return kernel;
		}

		bool active = true;

		std::set<Task*,decltype (Task::cmp)* > tasks;

		Kernel();
		void Init();
		void AddTask();
		void Run();
		void Deactivate();
		void End();



	};
}