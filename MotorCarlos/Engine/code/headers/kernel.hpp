#pragma once


#include <task.hpp>
#include <iostream>
#include <set>


namespace engine 
{
	class Kernel
	{
	private:
		bool active = true;

	public:

		static Kernel& Instance() 
		{
			static Kernel kernel;
			return kernel;
		}


		std::set<Task*, Task::Comparar> tasks;

		Kernel();
		void Init();
		void AddTask(Task* newTask);
		//Hacer una funcion que elimine una task 
		void Run();
		void SetActive(bool active);
		void End();



	};
}