#pragma once


#include <iostream>
#include <map>
#include <entity.hpp>
#include<RendererSystem.hpp>
#include<updateSystem.hpp>
#include <InputSystem.hpp>
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



	public:
		 Scene(const std::string& id, Window& window);

		std::unique_ptr <RenderSystem>	 rendererSystem;		
		std::unique_ptr <UpdateSystem>   updateSystem;
		std::unique_ptr <InputSystem>    inputSystem;

		void Init();
		void Update(float time);
		void Render();

		std::string GetName() {	return id;}

		void AddEntity(Entity* entity);
		Entity* GetEntity(const std::string* id);

	private:

	};


}