#pragma once



#include <vector>
#include <task.hpp>
#include <component.hpp>


namespace engine
{
	class System 
	{
	private:


	public:
		System() = default;

		virtual void Init() {};
		virtual void Run() {};
		virtual void End() {};

		virtual ~System() = default;
		~Renderer_System();
	};
}