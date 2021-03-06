#pragma once


#include <vector>
#include <system.hpp>
#include <window.hpp>
#include <renderComponent.hpp>
#include <Render_Node.hpp>
#include <kernel.hpp>

namespace engine 
{


	class RenderSystem : public System
	{
	private:
		Window* window;
		std::vector<RenderComponent*> renderComponents;


	public:
		std::unique_ptr < glt::Render_Node > renderNode;

		RenderSystem(Window* window, int priorty, Kernel* kernel);

		 //void  Init() override ;
		 void AddComponent(RenderComponent* newComponent);
		 void Run() override;
		 void CreateMeshComponent(Entity* e, std::string path);
		 void CreateCameraComponent(Entity* e);
		 void CreateLightComponent(Entity* e);
		 //void End() override;

		 //~RenderSystem();


	};





}
