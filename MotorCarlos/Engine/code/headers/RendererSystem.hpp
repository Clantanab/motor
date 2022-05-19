#pragma once


#include <vector>
#include <system.hpp>
#include <window.hpp>
#include <renderComponent.hpp>
#include <Render_Node.hpp>

namespace engine 
{

	class RenderSystem : public System
	{
	private:
		Window* window;
		std::vector<RenderComponent*> renderComponents;

		std::unique_ptr < glt::Render_Node > renderNode;

	public:

		RenderSystem(Window* window);

		 void  Init() override ;
		 void AddComponent(RenderComponent* newComponent);
		 void Run() override;
		 void End() override;

		 ~RenderSystem();


	};





}
