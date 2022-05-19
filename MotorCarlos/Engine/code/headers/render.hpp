#pragma once


#include <task.hpp>
#include <sceneManager.hpp>
#include <kernel.hpp>


namespace engine
{
	class Render : public Task
	{
	public :
		Render(int priority);
		//void Init() override;
		void Run(float time) override;
		void End() override;

	};
}