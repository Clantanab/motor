#pragma once



#include <vector>
#include <task.hpp>
#include <component.hpp>


namespace engine
{
	class System : public Task
	{
	private:
		

	public:
		System(int priority) : Task(priority) {}

		virtual void Init() {};
		virtual void Run() {};
		virtual void End() {};

		virtual ~System() = default;

	};
}