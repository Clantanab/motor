#pragma once




#include <scene.h>


namespace engine 
{



	Scene::Scene(const std::string& id, Window& window) 
	{
		this->id = id;

		//Scene_manager::instance().add_scene(this);

		//renderer_system.reset(new Renderer_System(window));
		//collision_system.reset(new Collision_System);
	}

	void Scene::Init()
	{
		//Falta alguna clase de implementacion a futuro en caso de que sea necesario
	}

	void Scene::Update(float time)
	{
		//control_system->run(time);
		//collision_system->run(time);
	}
	void Scene::render()
	{
		//Run the render system
		//renderer_system->run(0);
	}


	/*void Scene::add_entity(Entity* new_entity)
	{
		entities.insert(std::pair<Id, Entity*>(new_entity->id, new_entity));
	}*/


	/*Entity* Scene::get_entity(const std::string& id)
	{
	
		return entitiys[id];
	}*/
}