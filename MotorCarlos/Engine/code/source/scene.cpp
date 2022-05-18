#pragma once




#include <scene.h>
#include <sstream>

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


	void Scene::AddEntity(Entity* new_entity)
	{
		if (entitys[*new_entity->GetID()] != nullptr) 
		{
			unsigned iterator = 0;
			std::string aux;
			do {
				++iterator;
				aux = *new_entity->GetID() + std::to_string(iterator);
			} while (entitys[aux] != nullptr);

			*new_entity->GetID() = aux;


		}


		entitys.insert(std::pair<std::string, Entity*>(*new_entity->GetID(), new_entity));
	}


	Entity* Scene::GetEntity(const std::string* id)
	{
	
		return this->entitys[*id];
	}
}