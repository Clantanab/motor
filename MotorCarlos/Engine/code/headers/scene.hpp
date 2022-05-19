#pragma once


#include <iostream>
#include <map>
#include <entity.hpp>
#include<RendererSystem.hpp>
#include <kernel.hpp>
#include <sceneManager.hpp>


namespace engine 
{


	class Window;

	class  Scene
	{

	private:
		std::string id;
		std::map<std::string, Entity* > entitys;

		Kernel* kernel;
		//std::unique_ptr <Control_System>	 controlSystem;		//< Pointer of the control system
		//std::unique_ptr <Collision_System>	 collisionSystem;		//< Pointor of the colision system

	public:
		 Scene(const std::string& id, Window& window);

		std::unique_ptr <RenderSystem>	 rendererSystem;		//< Pointer of the render system 


		void Init();
		void Update(float time);
		void Render();

		std::string GetName() {	return id;}

		void AddEntity(Entity* entity);
		Entity* GetEntity(const std::string* id);

	private:

	};


}