#pragma once


#include <iostream>
#include <map>

namespace engine 
{


	class Window;

	class  Scene
	{

	private:
		std::string id;
		//std::map<std::string, Entity* > entitys;

		//std::unique_ptr <Renderer_System>	 rendererSystem;		//< Pointer of the render system 
		//std::unique_ptr <Control_System>	 controlSystem;		//< Pointer of the control system
		//std::unique_ptr <Collision_System>	 collisionSystem;		//< Pointor of the colision system

	public:
		 Scene(const std::string& id, Window& window);

		~ Scene();

		void Init();
		void Update(float time);
		void render();
		//void add_entity(Entity*);
		//Entity* get_entity(const std::string&);
		std::string get_name() {	return id;}

	private:

	};


}